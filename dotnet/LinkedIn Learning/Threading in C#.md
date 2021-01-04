# Threading in C\#

[Course Link](https://www.linkedin.com/learning/threading-in-c-sharp/)
Started *January 9, 2020*

- [Threading in C\](#threading-in-c)
  - [Introduction](#introduction)
  - [Section 1: Introduction to Threading](#section-1-introduction-to-threading)
    - [Threads vs. Processes](#threads-vs-processes)
    - [Local Memory](#local-memory)
    - [Thread Pool](#thread-pool)
      - [Ways to Enter a Thread Pool](#ways-to-enter-a-thread-pool)
    - [Other Threading Concepts](#other-threading-concepts)
    - [Exception Handling](#exception-handling)
  - [Section 2: Tasks](#section-2-tasks)
    - [Tasks Introduction](#tasks-introduction)
    - [Task with I/O](#task-with-io)
    - [Tasks with Continuation](#tasks-with-continuation)
  - [Section 3: Synchronization](#section-3-synchronization)
    - [Monitor and locks](#monitor-and-locks)
    - [Nested Locks](#nested-locks)
    - [Dead Locks](#dead-locks)
    - [Reader/writer Locks](#readerwriter-locks)
    - [Mutex](#mutex)
    - [Semaphore](#semaphore)
  - [Conclusion](#conclusion)

## Introduction

Chander Dhall - Software and big data architect; Microsoft MVP for 7+ years

Course will look at different ways to synchronize concurrent code.

You need a basic understanding of C# to take this course.

## Section 1: Introduction to Threading

**Thread** - Basic unit of execution; allocated processor time by an operating system. A sequence of program instruction that can be managed independently by a scheduler that is part of the operating system.

Every single process can have one or more thread running in the context of the process.
In a single-threaded program only one thread has full access to the process.

Multi-threaded programs allow multiple threads to coexist within the process; they execute independently but share resources within the process.

Threading is also referred to as multi-threading.

"Thick" client applications. Computation-intensive code should be run on a different thread than the UI code; you want the UI to remain responsive.

You can create threads in C# using the `Thread` class. However, you cannot choose which thread has control of the context, that is left up to the operating system.

```c#
    public static void Main(string[] args)
    {
        Thread thread = new Thread(WriteUsingNewThread);

        thread.Start(); // starts the new WORKER thread
    }

    private static void WriteUsingNewThread()
    {
        for (int i = 0; i < 1000; i++)
            Console.Write($"Process {i}");
    }
```

To understand threading, you have to understand how the operating system works.
The system has multiple applications running and each application can have multiple processes and each process can have multiple threads.

You can utilize the "Threads" window in Visual Studio to view the current threads in your process. You are able to name your threads by setting `thread.Name` to the string name you want to update. You can updated the main thread by utilizing the `Thread.CurrentThread.Name` property.

Multi-threading is managed internally by a thread scheduler and the .NET CLR works with the operating system and this scheduler. The CLR then assigns each thread its own local memory stack to keep the local variables separate between threads; a separate copy of the current local variables is created on each thread's new memory stack.

The thread scheduler ensures all active threads get the right processing time.

In a single-processing computer, the system utilizes timeslicing, which is rapidly switching execution between each active thread. The CPU overhead for switching is microseconds.

In a multi-processor computer, different threads can run the code simultaneously on different processors.

**Preempted Thread** a thread that has had its execution interrupted, usually by something external like timeslicing. The thread has no control over this.

The `lock` keyword allows you to lock a segment of code, requiring other threads to wait for the lock to end before they can access the code.

### Threads vs. Processes

Threads run in parallel on a single process and share memory, while processes are isolated from one another.

### Local Memory

When two threads call the same function, if the function has local variables like `i` in a loop, then each thread gets its own copy of the local variable; if two threads go over the same loop with a local variable `i`, they will not interfere with each other.

### Thread Pool

Every thread requires a few hundred milliseconds and about 1 MB of memory to spawn a new thread. You can reduce this penalty by sharing and recycling these threads.

A thread pool only spawns *background threads*. Background threads are like normal threads, except they do not keep the execution environment running. If the main thread dies, the background thread dies.

The thread pool limits the number of threads that can run simultaneously, since too many threads can throttle the CPU system and render CPU caches ineffective. When the thread pool limit is reached, a queue will form, and a new job will only begin when another completes. You can utilize the `Thread.CurrentThread.IsThreadPoolThread` property to determine if the thread is from a pool.

#### Ways to Enter a Thread Pool

You can enter the thread pool in several ways

- Task Parallel Library (TPL)
- Asynchronous delegate
- Background work
- Call `ThreadPool.QueueUserWorkItem`
  - Takes a `WaitCallback` item and optionally an object/state

```c#
    public static void Main(string[] args)
    {
        var workItem = new WaitCallback(MyMethod);
        var per = new Person("mike");

        ThreadPool.QueueUserWorkItem(workItem, per);
        Console.WriteLine(Thread.CurrentThread.IsThreadPoolThread); // False
    }

    private static void MyMethod(object person)
    {
        Console.WriteLine(Thread.CurrentThread.IsThreadPoolThread); // True

        if (person is Person per)
        {
            Console.WriteLine(per.Name); // mike
        }
    }
```

You can check the number of processors on a machine by entering `Environment.ProcessorCount` and the `ThreadPool.MaxThreads(int, int)` allows you to define the maximum number of threads. The first parameter is an int representing the maximum number of `workerThreads` and the second parameter is the maximum number of `completionPortThreads`.

The maximum number of workerThreads and completionPortThreads should be at least the number of processors, but likely more.

You can use the `GetMinThreads(out int, out int)` and `GetMaxThreads(out int, out int)` methods to determine what the current set values are.

There is a caveat with this process, since it won't really matter, but you want to keep it within a very controlled number.

### Other Threading Concepts

`thread.Join()` will force the current thread to wait for the specified thread. Allows developers to specify some sort of order to their methods.

`Thread.Sleep(int)` blocks the current thread for the specified amount of time.

`thread.IsAlive` determines if the thread is currently working

### Exception Handling

**Exception handling is per-thread**. If you have a try-catch in the main thread, and an exception is thrown in a worker thread, the exception will *not* be caught by the code in the main thread.

You should handle exceptions near where they are thrown so that you handle them in the thread that they occur.

## Section 2: Tasks

Threads are the lowest-level constructs of multi-threading, and they can be very challenging. Returning a value from a separate thread is not trivial, and can result in a lot of complications.

Task is a higher level abstraction capable of returning a value. Tasks can be chained together infinitely, are capable of using the thread pool, and can be used for I/O Operations.

A *CPU bound* process uses the resources of the local machine. An *I/O bound* operation uses out-of-process calls that are external to the application.

### Tasks Introduction

Tasks can be found in the `System.Threading.Tasks` namespace and can be instantiated much like a Thread.

```c#
Task task = new Task(MyMethod);

task.Start();
```

Unlike a `Thread`, you can easily return a value from a `Task`.

```c#
Task<string> returnTask = new Task<string>(MyOtherMethod);

returnTask.Start();
returnTask.Wait();

Console.WriteLine(returnTask.Result);
```

### Task with I/O

You can also create a task using the Task factory and automatically start it.

```c#
var task = Task.Factory.StartNew(() => return "hello");
```

The `task.Result` property will block execution until the result is available; this is OK, but be careful not to abuse this. Additionally, if there is any unhandled exception, it will be wrapped in an `AggregateException`. For the most part, if you use the `task.Result` property, you do not need to use `await`.

### Tasks with Continuation

With TPL, you can utilize continuation easily. This allows you to pass data or exceptions to the continueation, or determine whether or not the continuation is invoked or cancelled.

**Antecedent** - an asynchronous task that is invoked by another task.

You can invoke multiple continuations from any antecedent, and can invoke a continuation after any antecedents complete.

```C#
public void Main(string[] args)
{
    var antecedent = Task.Run(() => DateTime.Today.ToString());
    var continuation = antecedent.ContinueWith(x => $"Today is {antecedent.Result}");

    Console.WriteLine(continuation.Result);
}
```

*Note:* Inside of a task, you should use `Task.Delay(int)` instead of `Thread.Sleep(int)`.

## Section 3: Synchronization

With multiple tasks and threads running concurrently, synchronization becomes important. WIthout it, you would not get predictable outcomes.

You can utilize blocking methods, exclusive/non-exclusive locks, signals, or non-blocking constructs. So far we've used `Sleep`, `Join`, and `Task.Wait` which are all blocking methods; they stop execution of the thread until the task is complete.

Blocked threads *do not consume CPU* but do consume memory. When a thread is blocked, it lets go of its timeslice and lets the CPU work on other processes.

Spinning is when the CPU is consumed for as long as the thread is blocked. For example, the `while` loop uses CPU as long as the condition is not met.

Locks limit the number of threads that can perform activities on any section of code. There are two different kinds, exclusive and non-exclusive locks.

**Exclusive** locks allow only one thread to access a piece of code until that thread has finished; there are two types of exclusive locks, lock and mutex. You can utilize the `lock` keyword or the `Monitor.Enter` and `Monitor.Exit` methodology to create an exclusive lock.

**Non-Exclusive** locks include Semaphores, SemaphoreSlims, and reader/writer locks. They allow multiple threads to access a resource. They add a limit to the number of threads accessing a particular resource.

**Signaling Constructs** allow a thread to pause until they receive a notification/signal from another thread. This allows communication between threads. Very helpful when you want a thread to execute a particular set of code but wait for another thread before continuing. You can utilize "event wait handles," "monitor's Wait/Pulse methods", or the `CountdownEvent` and `Barrier` classes.

**Non-blocking Synchronization** constructs protect access to a common field. Things like `Thread.MemoryBarrier`, `Thread.VolatileRead`, `Thread.VolatileWrite`, the `volatile` keyword, and the `Interlocked` class.

### Monitor and locks

The `Monitor.Enter(object)` method accepts an object that will behave as a lock. Only one thread will be able to access the code between the `Enter` and `Exit` methods at one time.

```c#
object myLock = new object();

public void MyMethod()
{
    Monitor.Enter(myLock);

    try
    {
        // do some stuff
    }
    finally
    {
        Monitor.Exit(myLock);
    }
}
```

### Nested Locks

You can nest multiple locks calling the same object. The only lock that matters is the "parent" lock, or the lock containing all other locks. The thread knows that it owns the lock already, so it can continue to process the locked code.

```c#
object myLock = new object();

public void MyMethod()
{
    lock(myLock)
    {
        DoStuff();
    }
}

public void DoStuff()
{
    lock(myLock)
    {
        Task.Delay(2000);
        lock(myLock)
        {
            Console.WriteLine("here");
        }
    }
}
```

### Dead Locks

In the example below, the first Task will lock down thread one, then sleep before it attempts to lock thread two. At the same time, the second task will lock thread two, then Wait before it attempts to lock thread one. Both Tasks will then be waiting on the other to release their first locks, but neither will ever be able to progress any further. This is a **dead lock** and is exactly why you should be careful while using Nested locks.

```c#
object oneLock = new object();
object twoLock = new object();

public void MyMethod()
{
    Task.Run(LockOne);
    Task.Run(LockTwo);
}

private void LockOne()
{
    lock (oneLock)
    {
        Task.Delay(2000).Wait();

        lock (twoLock)
        {
            // Do something
        }
    }
}

private void LockTwo()
{
    lock (twoLock)
    {
        Task.Delay(2000).Wait();

        lock (oneLock)
        {
            // Do something
        }
    }
}
```

### Reader/writer Locks

The "Slim" version of the `ReaderWriterLock` [performs better than the standard class](https://docs.microsoft.com/en-us/archive/blogs/pedram/a-performance-comparison-of-readerwriterlockslim-with-readerwriterlock). There may be multiple different threads acquiring `ReadLock` at the same time, but this is OK, however, when a thread enters the WriteLock, then no other threads can enter either a Read or WriteLock.

```c#
ReaderWriterLockSlim lock = new ReaderWriterLockSlim();

public void Read()
{
    for (int i = 0; i < 10; i++)
    {
        lock.EnterReadLock();
        // read
        // multiple threads can read at the same time
        lock.ExitReadLock();
    }
}

public void Write()
{
    lock.EnterWriteLock();
    // write
    // nothing else can read or write until the exit is hit
    lock.ExitWriteLock();
}
```

### Mutex

When creating a `Mutex`, if you pass true to the constructor, then the thread that creates the Mutex claims ownership of it, otherwise the Mutex will be unclaimed. A second parameter provides the name of the Mutex which is computer-wide.

`Mutex.WaitOne` returns true when the Mutex is no longer owned. It also accepts a first parameter of `int` that will determine the timeout for trying to acquire the Mutex; if after *x* seconds, the thread cannot obtain the mutex, it will stop trying to acquire the Mutex.

```c#
Mutex mutex = new Mutex();

public void MyMethod()
{
    Thread thread = new Thread(GetMutex)
                            .Start();
}

private void GetMutex()
{
    mutex.WaitOne(); // blocks current thread until WaitHandle receives a signal

    // do something

    mutex.ReleaseMutex();
}
```

### Semaphore

The `SemaphoreSlim` was introduced in .NET Framework 4.0, which is an improvement on the original `Semaphore` class. The original class takes about 1000 microseconds to create, while the slim version takes only 200 nanoseconds.

A Semaphore ensures that only a certain number of concurrent threads can access a particular resource.

```c#
SemaphoreSlim sema = new SemaphoreSlim(3); // capacity of 3 threads

public void MyMethod()
{
    for (int i = 0; i < 10; i ++)
    {
        new Thread(UseSemaphore)
                .Start(i); // number of the thread
    }
}

private void UseSemaphore(object id)
{
    var threadId = (int)id;

    sema.Wait(); // makes the thread wait if the max threads is reached

    Console.WriteLine($"Thread {threadId} has access");
}

```

## Conclusion

You can visit [Cazton.com](http://cazton.com) and view the technical blogs.

There is also an e-book book at [albahari.com](http://albahari.com/threading)
