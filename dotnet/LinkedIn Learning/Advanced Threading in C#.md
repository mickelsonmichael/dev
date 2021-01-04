# Advanced Threading in C\#

[Course Link](https://www.linkedin.com/learning/advanced-threading-in-c-sharp/welcome)
Started *January 9, 2020*
Completed *January 13, 2020*

## Introduction

Course will go over thread safety, thread affinity, and signaling over multiple threads.

Before watching, you should know C# and the instructor recommends taking his [Threading in C#](https://www.linkedin.com/learning/threading-in-c-sharp/welcome) course first.
Since it looks like a good class, I'll stop here and start that class instead, hopefully to come back here someday and take this Advanced course.

*Update 1/10/2019* - I went back through the last class and find it a little regretful. Sure there was new information but I don't know that there was much there I will be working with. Mostly was important to learn about the `lock` keyword and other methods of locking. I am quite confident now that I will be able to finish this course with ease, but am more nervous about the instructor than before.

## Section 1: Signaling and Thread Concepts

When writing multi-threaded code, you need to worry about thread safety. Code where shared data structures are modified in a matter that all threads behave properly, fulfill design specification and not have unintended consequences; there should be no deadlocks.

In .NET Framework, all static methods provided are thread safe. *This does not mean that any static method created will be thread safe.* When creating a static method it should be done in a thread safe manner.

### Thread Affinity

**Thread affinity** means the thread that instantiates an object is the only thread that can access its members. This can have both advantages and disadvantages

- Pros
  - Don't need a lock to access a UI object in WPF
  - Able to access all objects within a thread without a lock, since no other thread can invoke them
- Cons
  - Cannot call members on a thread that is on another thread

In WPF, if you try to update the UI thread, which has thread affinity, on any other tread, an exception will be thrown. You instead need to use `Dispatcher.Invoke`, which [in WPF is associated with the UI thread](https://docs.microsoft.com/en-us/dotnet/api/system.windows.threading.dispatcher?view=netframework-4.8) and will queue the call onto the UI thread to prevent any issues.

### Signaling

Signaling notifies another thread that it can now access the resource that was being used by the current thread. There are three kinds of `EventWaitHandle` calls for signaling

1. AutoResetEvent
2. ManualResetEvent
3. CountdownEvent

**AutoResetEvent** is used when threads need exclusive access to a thread and resets itself automatically. A thread waits for a signal by calling `WaitOne` and calling the `Set` method signals the release of the waiting thread and automatically resets. If `Set` is called when no thread is waiting, the handle stays open indefinitely. Calling `Set` only releases one thread at a time. The event can be created with an initial state of "signaled" by passing "true" into the constructor parameter and will remained signaled until any thread is released.

```c#
// first parameter indicates whether or not the event starts signaled

EventWaitHandle handle = new EventWaitHandle(false, EventResetMode.AutoReset);
// or
EventWaitHandle handle2 = new AutoResetEvent(false);

public void MyMethod()
{
    Task.Factory.StartNew(DoWork);

    Thread.Sleep(2500);

    handle.Set();
}

private void DoWork()
{
    // will wait until the first time Set is called
    handle.WaitOne();

    // do stuff
}
```

### Two-way Signaling

By having two `EventWaitHandle` objects, you can have one thread wait for the main thread to perform some action, then signal to the thread to continue and hold on the main thread, waiting for the background thread to signal for the continue.

### Signaling: ManualResetEvent

Unlike with the `AutoResetEvent` class, you need to manually "reset" the `ManualResetEvent` by calling the `Reset` method. Additionally, there are allowed any amount of threads at the same time.

If an event is not "reset" then all threads are able to pass through the Wait functions without stopping. In order to force them to stop until the next `Set()` call, you must call `Reset()`.

```c#
ManualResetEvent event1 = new ManualResetEvent(false);
// or
EventWaitHandle event1 = new EventWaitHandle(false, EventResetMode.ManualReset);
```

### Signaling: Countdown

A `CountdownEvent` object will block the current thread when `Wait()` is called. After an `x` amount of threads have called the `Signal()` method, the waiting thread may proceed. The number of signals to wait for is determined upon creation of the `CountdownEvent(int)` object.

```c#
CountdownEvent countdown = new CountdownEvent(5); // requires 5
```

## Section 2: Task Parallel Library (TPL)

A set of public types and APIs that can be found in `System.Threading` and `System.Threading.Tasks`. They simplify the process of adding parallelism and concurrency to applications. The TPL also handles scheduling, cancellation, partitioning of the work, and the management of state.

Even though the TPL is the preferred way to write multi-threaded and parallel code, not all code is suitable for parallelization, due to the overhead of creating threads and changing context. Some things may be slower when run with the TPL library due to this overhead.

See the code snippet below for an example of using the TPL library instead of a `for` loop.

```c#
private void CountUp()
{
    // parallel query will not run in order
    // the output of 1 - 10 is not necessarily going to be ordered
    Parallel.For(0, 10, i =>
    {
        Console.WriteLine(i);
    });
}
```

### Cancellation

```c#
CancellationTokenSource cancellationTokenSource = new CancellationTokenSource();

ParallelOptions options = new ParallelOptions
{
    CancellationToken = cancellationTokenSource.Token,
    MaxDegreeOfParallelism = Environment.ProcessorCount
};

Task.Factory.StartNew(() =>
{
    // listen for a keypress or some other event
    cancellationTokenSource.Cancel();
});

int total = 0;

Parallel.For(0, 100, parallelOptions, () => 0, (i, parallelLoopState, subTotal) =>
{
    parallelOptions.CancellationToken.ThrowIfCancellationRequested();
    subTotal += i;
    return subTotal;
}, Add);

void Add(int amt)
{
    Interlocked.Add(ref total, amt);
}
```

### Continuation with State

```c#

pubic void Main()
{
    Task<DateTime> mainTask = Task.Run(() => GetNow());

    List<Task<DateTime>> continuationTasks = new List<Task<DateTime>>();

    for (int i = 0; i < 3; i++)
    {
        // the "state" changes based on ID
        task = task.ContinuesWith((x, y) => DoSomething(), new Person { Id = i });

        // Chains the tasks together
        continuationTasks.Add(task);
    }

    // waits for the last task in the chain
    task.Wait();

    foreach (var continuation in continuationTasks)
    {
        // get the "state" from this particular task
        var person = continuation.AsyncState as Person;
        Console.WriteLine($"{person.Id} at {continuation.Result}");
    }
}

private DateTime GetNow()
{
    return DateTime.Now;
}

```

### TaskCompletionSource

There are times you want to perform a task only when a user performs some action. The `TaskCompletionSource` task will start a background task that will complete a task once a user triggers the event. [See MSDN for more information](https://docs.microsoft.com/en-us/dotnet/api/system.threading.tasks.taskcompletionsource-1?view=netframework-4.8).

``` c#
TaskCompletionSource<Product> source = new TaskCompletionSource<Product>();

Task<Product> lazyTask = source.Task;

Task.Factory.StartNew(() =>
{
    // not sure why we're doing this SetResult in this Task
    source.SetResult(new Product { Name = "Github" });
});

Task.Factory.StartNew(() =>
{
    if (Console.ReadyKey().KeyChar == 'x')
    {
        Product result = lazyTask.Result;
        Console.WriteLine($"Result: {result.Name}");
    }
});

Console.ReadLine();
```

## Section 3: PLINQ

Parallel-LINQ was created to automate parallelization using the same LINQ query format that developers are already used to using the `.AsParallel` method. PLINQ automatically creates the tasks and consolidates the results without additional work on the part of the developer. It is declarative vs imperative; you don't need to explicitly write code the do the tasks.

The following queries will not work with PLINQ and will instead result in a sequential process.

- Take
- Select
- SelectMany
- Skip
- TakeWhile
- SkipWhile
- ElementAt

Parallelized queries are not always faster than the regular query.

Some methods will use an expensive partitioning strategy and will often result in slower queries

- Join
- GroupBy
- GroupJoin
- Distinct
- Union
- Intersect
- Except

PLINQ can also change the execution to sequential if it believes that the query will be better off in a sequential query. This is done to avoid any kind of overhead, but can be forced by calling `WithExecutionMode(ParallelExecution.ForceParallelism)`.

You can use PLINQ to optimize I/O-intensive operations as well, and also configure the degree of parallelism.

```c#
var list = Enumerable.Range(1, 100_000_000);

// convert the enum into a PLINQ enum
var primeNumbers = list.AsParallel()
    .Where(IsPrime);

bool IsPrime(int x)
{
    // Do some intense calculation to find a prime number
}
```

### Degree of parallelism

You can specify the *degree of parallelism* using PLINQ method `WithDegreeOfParallelism(int)`, which will specify the number of concurrently processing Tasks. [See MSDN](https://docs.microsoft.com/en-us/dotnet/api/system.linq.parallelenumerable.withdegreeofparallelism?view=netframework-4.8).

> Degree of parallelism is the maximum number of concurrently executing tasks that will be used to process the query.

```c#
var sites = new List<string>
{
    "google.com",
    "apple.com",
    "microsoft.com"
};

// get the list of responses, running 3 Tasks at a time
var responses = sites.AsParallel()
    .WithDegreeOfParallelism(websites.Count)
    .ToList();

private PingReply PingSite(string url) => new Ping().Send(url);
```

### Concurrency bag

The PLINQ statement `ForAll` is faster than the `ForEach` method since it aggregates the data for you into a list. With the `ForAll`, you can still order the results, which will slow things down but has the advantage of being ordered.

There is also the `ConcurrentBag` class, which will allow you to continually adding to the list of items, but will not sort the results. [See MSDN for more info.](https://docs.microsoft.com/en-us/dotnet/api/system.collections.concurrent.concurrentbag-1?view=netframework-4.8) Bags are essentially a list that is thread-safe and can accept duplicate values.

> Bags are useful for storing objects when ordering doesn't matter, and unlike sets, bags support duplicates. ConcurrentBag<T> is a thread-safe bag implementation, optimized for scenarios where the same thread will be both producing and consuming data stored in the bag.

```c#
var list = Enumerable.Range(1, 100_000_000);

var query = list.AsParallel()
                .AsOrdered() // will return the result in an ordered fashion
                .Where(x => x % 25 == 0);

var concurrentBag = new ConcurrentBag<int>(); // note: concurrencyBag may not respect ordering

query.ForAll(x => concurrentBag.Add(x));
```

### Merge options

There are three methods for buffering in PLINQ, `NotBuffered`, `AutoBuffered`, and `FullyBuffered`. The default method is `AutoBuffered`.

- FullyBuffered will cause the entire output of the query to be buffered. It will not yield any elements until the entire result is buffered.
- AutoBuffered is between full and not. It will take the result of a query in chunks instead of all or none
- NotBuffered is analogous to streaming. It will give results as they come in (and sort them). May result in the longest total time, but will result in the fastest initial result.

[Check out MSDN for more information on buffer types](https://docs.microsoft.com/en-us/dotnet/api/system.linq.parallelmergeoptions?view=netframework-4.8).

```c#
var list = Enumerable.Range(1, 100_000_000);

var query = list.AsParallel()
                .WithMergeOptions(ParallelMergeOptions.FullyBuffered);
                // or ParallelMergeOptions.NotBuffered
                // or ParallelMergeOptions.AutoBuffered
```

## Section 4: Task Asynchronous Pattern (TAP)

Task-based Asynchronous pattern is the recommended way of doing task-based programmer. It's very simple, and has only a few things to keep in mind.

1. Return a `Task` or `Task<TResult>`
2. Use the "async" suffix in the method name (except in special cases)
    - e.g. `MyMethodAsync` or `DoStuffAsync`
3. Must accept a `CancellationToken` in it's overload (or an `IProgress`)
4. Returns quickly to the caller
    - The synchronous phase is a small phase
    - If an I/O bound task, it should free up the thread ASAP

## Conclusion

Suggests you visit [cazton.com](http://cazton.com) to view some technical blogs. You can see the previous course, "Threading in C#.md" for the remainder of the suggested extended learning opportunities including his website and Albahari.

---

**Course Completed:** 1/13/2020
