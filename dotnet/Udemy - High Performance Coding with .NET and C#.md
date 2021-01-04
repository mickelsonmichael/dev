# High Performance Coding with .NET and C\#

[Udemy Course](https://www.udemy.com/course/high-performance-coding-with-net-core-and-csharp/learn/lecture/8651380#overview)

*Post-Course:* I ended up giving the course a 3/5. It was alright, it had a lot of useful information in it to grow as a C# developer more, but really I'm probably not going to use most of it. If anything it's just nice to know stuff. There may be cases where I do intense computations and every millisecond counts, but I think it most scenarios the gains I get from reference types and value types will be outweighed by the debt of readability.

Perhaps the most useful was the monitoring tool Prefix (by Stackify), since it will allow me to view  the SQL requests and API requests being made by my application.

## Section 3: Measure Performance During Development Part 2

### Event Tracing: ETW and PerfView

[GitHub Link](https://github.com/microsoft/perfview)

*Run* is the same as *collect* except it automatically stops collection when the started process terminates. The results of the run command and collect command are similar to what you would get with Visual Studio, that means you can attach it to a running process without needing to launch Visual Studio.

#### The Managed Heap

- Small Object Heap (SOH) - objects smaller than 85,000 bytes
- Large Object Heap (LOH) - objects larger than 85,000 bytes

##### GC generations

- Gen0
  - Every new object including temp variables
  - Most objects will be in Gen0 and collected during first GC
  - Objects smaller than 85,000 bytes
- Gen1 - Buffer between Gen0 and Gen2
  - Objects who survive the first carbage collection are promoted to Gen1
- Gen2 - Long living objects (e.g. static fields)
  - Survive multiple GC runs
  
Large Object Heap does not have this generational heirarchy, and all objects will be collected together with Gen2.

This heirarchy will result in performance improvements since smaller objects are collected frequently, while Gen2 collections (slower collections) are ran less frequently. Gen2 collection is called a full GC.

If Gen2 grows quickly, it could mean that you have a memory leak.

PerfView gives information about the GC using Heap Snapshots, something not available in Visual Studio (at the time of the course). Can be run on the production machine and analyze on the dev machine.

Can start Perfview in the background into a file or buffer and automatically write the content. Example: if .NET uses more than 85% of CPU, it can write to the buffer

Check here for more video tutorials on PerfView: https://channel9.msdn.com/Series/PerfView-Tutorial

### Micro Benchmarking with BenchmarkDotNet

[GitHub Link](https://github.com/dotnet/benchmarkdotnet)

IL code is JITed when a method is executed for the first time, meaning the first method pass will be the slowest, while the second will be much faster. There are also other programs that can interefere with the speed of your application while doing benchmark tests outside of the BenchmarkDotNet tool.

Additionally, there are different "flavors" of .NET, and BenchmarkDotNet can test all of them quickly with little work on the part of the Dev.

It's just a NuGet library, and requires no other installation.

1. Add "BenchmarkDotNet" NuGet package
2. Mark methods for benchmarking
3. Call `BenchmarkRunner.Run<T>` in your main method where `T` is a class with the `[Benchmark]` methods

You should always benchmark release builds. BenchmarkDotNet will even warn you if you do not.

#### Additional Features

- MemoryDiagnoser - gets GC and allocation statistics by using the `MemoryDiagnoserAttribute` decorator
- Change which CLR you utilize with several attributes (e.g. `[ClrJob]`, `[CoreJob]`, `[MonoJob]`)
- Change which JIT compiler you use (i.e. `[LegacyJitX86Job]` or `[RyuJitX64Job]`)

There are other settings, and Attributes are not the only way to configure your runs.

### .NET Core Performance Diagnostic on Linux

Utilize **Perf**. Basically is a command line tool. I will be mostly auditing this chapter since I don't currently utilize Linux machines.

[FlameGraph](https://github.com/brendangr/flamegraph) can be used to visualize profiler data.

LTTng messages are sent by the CoreCLR and can be captured easily to monitor performance.  

### Performance Monitoring on the Developer Machine with Stackify Prefix

- Micro-benchmarking
  - What the previous lessons did
  - Measure methods, GC, allocations, etc.
  - Difficult since code must be isolated and not contain dependencies
- Macro-benchmarking
  - Takes dependencies into account
  - ASP.NET Core - Response time, database calls, external HTTP calls
  - Most .NET Applications spend most time waiting on dependencies

  Can utilize [Prefix Stackify](http://www.stackify.com/prefix) to look at the big picture. It won't list all methods that are called, but will instead the calls to other libraries.

## Section 4: Make your Code Faster - General Tips for .NET Developers

### Value Types vs. Reference Types and Reducing Pressure on the GC

- Reference Types
  - Value is a reference that navigate to the object that is referenced (or null)
  - String, CLasses, Arrays, Delegates
  - `=` operator assigns the reference itself
  - `==` operator compares whether the two operands reference the same object
    - Except String
- Value Types
  - Stores its value directly within its own memory
  - `int`, `bool`, `char`, `Date`, `struct`, `enum`
  - `=` assigns values stored within the value type
  - `==` compares the values stored within the value type

Heap is managed by the GC, while the Stack is "self managed" since it can only be allocated and deallocated on the top. This makes deallocation of the stack much cheaper.

- Local Variables
  - Stored on the stack
  - Value type completely on the stack
  - Reference type has reference on the stack, but the object is on the heap
- Instance variable
  - For a reference type, the instance variables will *always* be stored on the heap
  - For a value type, they is stored where the variable is stored that declares the value type
    - Value types are not always created on the stack
    - If an instance variable of a value type (e.g. `struct`), the value will also be on the stack

#### Reference Types - Object Header

- Per-object overhead
  - Two additional fields are added to the stack
    - Sync Block Index: stores information about lock status
    - Method Table Pointer: which methods are usable on a given type
- Advantages
  - Polymorphism
  - Inheritance
  - Lock - Sync Block Index stores locking information
- Disadvantages
  - Bigger size - for small objects, this means that the size is substantially bigger than expected
  - Only allocated on the heap

When creating a `ValueType`, you automatically implement the `Equals` method which utilizes reflection and is slow.
You should override and overload the `Equals` method to get around this, and in the case of structs you should implement the `IEquitable` interface.

#### Advantages of Value Types

- Can be stored on the stack (less pressure on the GC)
- No metadata table and sync-block
- Best for small types with primitive values
- No inheritance
- Lots of copying
- Boxing

Don't simply change everything to value types; measure the performance before and after to see if there really is a benefit to the change.

### Saving Threads with `async`/`await`

This section discusses what the `async` and `await` keywords do and what they *don't* do.

#### What is Asynchronous Programming

- Something is asynchronous when you don't have to stop and wait for it
- Is often confused with other concepts; it is not multi-threading or parallel programming
  - Multi-threading - multiple execution contexts in the application
  - Parallel Computing - multiple calculations carried out simultaneously
  - Both cases, threads and calculations can be started synchronous or asynchronous

#### Asynchronous Programming in C3

- Introduced in C# 5
  - Two new keywords: `async` and `await`
- About asynchronous programming, but not multi-threading or parallel programming
- Don't create or start threads, just express that something is asynchronous
- Possible return types (pre-C# 7)
  1. `Task`
  2. `Task<T>`
  3. `void`
- Since C# 7
  - Anything with a `GetAwaiter` method can be returned from an `async` method

This is beneficial since the `await` keyboard lets the thread that starts the operation sit idle while waiting for a response. With parallel requests you can save requests from the threadpool and with GUI applications there is no heavy work on the UI thread.

### Choosing the Right Collection

#### Array

- Very effective with memory, items are stored next to each other
- Size is fixed, cannot add or remove items
- Fast access
- Searching is O(N), since in worst-case you have to visit *every* item

#### `List<T>`
  
- Implemented with an array
- Very effective with memory, fast indexing
- Size is not fixed, and add or remove items
  - This is expensive
  - Inserting to the end of the list is less expensive (`Add()`), inserting in the middle means everything must be shifted
  - When the underlying array is full, a new array is created with 2x the size of the previous
  
#### `LinkedList<T>`
  
- Implemented with a classic linked list
  - Every item is linked to its successor and predecessor
- There is overhead per item, since it must have additional references
- Fast insertion and deletion because of these references

#### `Dictionary<T,N>`, `HashSet<T>` - Associative Collections

- Implemented with a hash table
- Dictionary has a key-value pair while a HashSet has only the value
- Very fast lookup, insert, and delete (*O(1)*)
- HashTable maps keys to values by calling the `GetHashCode` method on the object
  - `GetHashCode` returns an integer
  - There is a limited number of "buckets" to store the objects in, but it is difficult to fill them all

##### GetHashCode method

- It is important to have uniform distribution with `GetHashCode` calls to spread the objects between different buckets
- If you were to return a constant from the method, all the objects would be put into the same "bucket"

### `SortedDictionary<T,N>`, `SortedSet<T>`
  
- Implement a binary tree structure
- Better lookup, insert, and delete than List and Array, but worse than Dictionary or HashSet
- Items are sorted by `IComparable<T>`
- The downside is the per-object overhead

## Section 5: C# 7 Performance

- Language features and performance
- Avoiding heap allocations with local functions
- Boosting performance with Ref returns
- Performance implications of ValueTuples
- Optimization of async-methods with ValueTask
- Pattern matching and performance

### Performance Impact of C# 7 Features

- CLR - the virtual machine of the .NET Framework
- Can execute IL code
- Provides GC, JIT, and thread management
- Does not run C# code, runs IL Code
- Roslyn compiles C# code into that IL Code

As a developer, it is almost impossible to modify what the JIT does with your code, but it's easier to change how your C# Code is converted into IL Code.

You can use *dnSpy* to analyze .dll files and view the IL code.

#### Language Features and Performance

- It is important to measure everything! Always measure first.
- In general, most things in this section will be relevant for library authors or programs that work in tight loops
- If you have a code-base where most time is spent waiting on I/O, then these changes will not have much of an effect

### Avoid Heap Allocations with Local Functions

Looks into a particular C# 7 feature called Location Functions, and compare its performance to delegates, `Action<T>`, and `Func<T>`

#### Local Functions - Use Cases

- Comes from a functional program
- Function within a function
- Local helpers within a method that you can use multiple times within *only* this method
- Similar to private methods, except they aren't exposed to other methods in the class
- Before C# 7, you had to use delegates instead (e.g. `Action<T>` and `Func<T>`)
- Syntax is slightly nicer, but most importantly performance is improved

When converted into IL code, the local function is significantly fewer lines than the delegate. The less IL code you have to run, the faster your application will be.

When the local function is compiled to IL code, it is converted into a private method. This means the `call` operation can be used, which is the fastest way to call a method. Meanwhile, the delegate uses the `newobj` operation, which puts pressure on the GC, and uses the `callvirt` (call virtual) operation, which can be slow method of calling a function.

This difference can be really small or nothing, but it is still important to note the difference.

He advises not overestimating this. If you have a codebase focused on waiting for I/O, this will not net you much performance gain.

### Make ValueTypes Faster with `ref return`

This section will look at the history of the `ref` keyword in C# and understand how it boosts the performance of ValueTypes. It will also analyze what new features have been added in C# 7 to enhance the `ref keyword`, `ref return` and `ref local`.

C# by default passes by value with a value type. A new storage location is created for value types, and a new reference is created for reference types (two references that reference the same object). Setting the reference to `null` will not remove the original reference.

This means that every time you pass a value type, a copy is created, which could be potentially very heavy, especially for larger structs. C# 1.0 provided the `ref` keyword to work around this; by passing a parameter with `ref`, the original value is passed instead. For value types, there is no copying, only a reference i made. For reference types, a reference to the reference is passed, meaning if you set the new reference to null, the original reference will also be set to null. The performance will sill be about the same for reference types, but you can see improvements for value types.

The consequences of the `ref` keyword:

1. If you change a `ref` value, you also change the original value
2. Avoids copying large `structs`

The `ref return` feature allows for more performant IL code in a lot of cases, particularly cases where the return type is a large `struct`. Instead of returning the actual value or pointer, it returns a reference to the value or a new pointer.

```c#
public static ref int SelectArrayItem(int[] array, Func<int> selectionLogic)
{
  return ref array[selectionLogic()];
}

static void Main(string[] args)
{
  int[] myArray = new int[] { 1,2,3,4,5 };
  
  Console.WriteLine(myArray[2]); // Outputs 3
  
  ref int refToArrayItem = ref SelectArrayItem(myArray, () => 2);
  refToArrayItem = 99;
  
  Console.WriteLine(myArray[2]); // Outputs 99
}
```

If your value type is very large, then it makes sense to return it by reference instead to prevent duplication of large data.

#### `ref` local

You can mark a local variable with the `ref` keyword to make sure two variables point to the same value. If one is updated so is the other.

```c#
int x = 1;
ref int y = ref x;
y = 42;
Console.Write(x); // Output: 42
```

### The Performance Characteristics of C# 7 Tuple Feature

ValueTuples were added in C# 7 (based on the System.ValueTuple type) and allow you to return two values from a function without creating a new class. System.Tuple was introduced in .NET 4.0 and is not a language feature but is instead a type, the two concepts are similar but are not related; the C# 7 feature does not use the System.Tuple namespace.

> [The Tuple] is a data structure that has a specific number and sequence of elements

When converted to IL code, tuples are converted to the `ValueTuple` type. The original `Tuple` class was a ValueType, meaning it was always allocated on the heap, while the new `ValueTuple` is stored on the stack instead.

To summarize, utilize the `ValueTuple` class instead when you have a tight loop and need the extra processing power. If you are writing new, non-performant code then you should write in the new value tuple type, but don't rewrite old applications just to use this new feature.

### Optimization of async-methods with ValueTask

As of C# 7, you can now return a `ValueTask` from an `async` function, while originally you could only return a `Task`, `Task<T>`, or `void`. Unfortunately, the original return types were reference types, meaning each time an async method is returned, a task is added to the heap.

*Note: the ability to return void is for backwards compatibility reasons. You should not return void on new methods*.

> Starting with C# 7.0, you return another type, typically a value type, that has a GetAwaiter method to minimize memory allocations in performance-critical sections of code.

[MSDN Link to ValueTask](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/async/async-return-types#generalized-async-return-types-and-valuetasktresult)

`ValueTask` was specifically designed to fix this memory issue. It is essentially the result of the task without allocating a `Task` on the heap. Only use `ValueTask` if you have numbers proving that your `async` method is faster with it; do not use it by default. The official recommendation is to use `Task` by default. `ValueTask` also adds additional overhead, since it must be converted to a `Task` when passed into a `Task.WhenAll`-like function.

### Pattern matching and Performance

Before C# 7, pattern matching types of operations were performed via an "is-as" construct like below. You first check if the object is of the desired type, then cast it to that type using the `as` keyword.

```C#
public void ProcessPerson(Object item)
{
  if (item is Person)
  {
    var person = item as Person;
    person.Name = "Mike";
  }
}
```

C# 7 adds the pattern matching process to siplify this; the check, cast, and assignment are all done in one line like below.

```c#
public void ProcessPerson(Object item)
{
  if (item is Person person)
  {
    person.Name = "Mike";
    // Can only use the `person` variable inside the if block
  }
}
```

When converted to IL code, there is a duplication of code, since it must check the type twice. With pattern matching, the process instead uses the `dup` operation to store the value in the new variable.
Pattern matching can possibly result in speeding up of code, but again, you should benchmark your code before and after before updating the process.

Pattern Matching Switch-cases allow for pattern matching within the switch statement itself like below

```c#
var object parameter = // something

switch (param)
{
  case int i when i > 50:
    Console.WriteLine("big");
  case int i when i > 100:
    Console.WriteLine("bigger");
  case int i:
    Console.WriteLine("small");
    break;
  case string str:
    Console.WriteLine("wordy");
    break;
  case var v:
    Console.WriteLine($"who knows{v.GetType()}");
    break;
}
```

In the above code, we have three cases where the `param` is checked as an `int`, but the `isinst` operation in IL code is only performed once. The compiler will only check the type once per type in the switch statement. In the example above, there are only two checks performed, once for `int` and once for `string`.

## Section 6: New Performance Related APIs

These new APIs were introduced during the development of .NET Core and ASP.NET Core. These APIs became a part of .NET Standard so they can be used within our projects as well.

### Reusing Arrays with `ArrayPool<T>`

If you have a method that is frequently called that allocates an array, then each time the method is called, a new array is allocated on the heap and collected by the GC. For larger arrays like byte arrays for files or images, these can be expensive computations.

The `ArrayPool` contains an pool of arrays that allow you to reuse arrays without needing them to be recreated or garbage collected. This process is thread-safe, so it can be used in concurrent operations without issue.

`ArrayPool<T>.Shared.Rent(int length)` checks out an array from the pool that is *at least* as big as the array size you requested. This size may be larger.

`ArrayPool<T>.Shared.Return(T[] array)` returns the array to the pool.

By reusing large arrays, you save a lot of time garbage collecting; by reducing the number of arrays garbage collected, you increase the performance and speed of the application.

The `ArrayPool` construct also emits ETWs, so its performance can be monitored using PerfView by adding `*System.Buffers.ArrayPoolEventSource` to the "Additional Providers:" box inside the Advanced Options of a PerfView run. You can then look at the event log and filter for `ArrayPool`.

`ArrayPool<T>.Shared` gives you the shared pool, which always exists. The default size (and maximum size) of an array in the pool is 2<sup>20</sup>. Therefore if you try to rent an array that is larger than the 2<sup>20</sup> array, then the pool allocates and returns a new array and does not pool it again if it is returned.

`ArrayPool<T>.Create(maxArrayLength, maxArraysPerBucket)` creates a new pool where you can customize the maximum size of the array pool. So if you have a series of arrays that will be larger than 2<sup>20</sup>, you should create your own array. However, if you don't need to create a custom pool to get past the size limits, you should stick with the shared pool instead to avoid instantiating too many objects on the heap.

The ArrayPool is utilized in many .NET Core projects including Kestrel.

### Accessing all Types of Memory Safely and Efficiently with `Span<T>`

There are three ways you can allocate memory in .NET:

- Managed memory
  - Using the `new` keyword
  - `var array = new byte[100];`
  - The most common way to allocate memory
- Unmanaged memory
  - `IntPtr myArray = Marshal.AllocHGlobal(100);`
  - `Marshal.FreeHGlobal(myArray);`
  - The allocation is invisible to the GC
  - Used in scenarios where you don't want GC to collect your memory
- Stack memory
  - Allocating memory directly on the stack
  - `byte* myArray = stackalloc byte[100];`
  - Can lead to `StackOverflowException`s if too much is allocated at once
  - This is much faster than managed memory, but can lead to issues

Libraries like Kestrel and ASP.NET are very high performant, and utilize all three types of memory allocation. However, the API for these do not accept all three types of memory since this is "very uncomfortable." You will need to add three overloads for each type of memory. The `Span<T>` type is the fix for this.

The `Span<T>` type "represents contiguous regions of arbitrary memory. An abstraction over all types of memory that we can allocate in .NET." Instead of three methods that accept all three types of memory, you can instead use one method that accepts a `Span`. The `ReadOnlySpan` class is the same, but you cannot modify the memory once the object is created. This is useful for types that are immutable like the `string` class.

```c#
public void ProcessByteArray(Span<byte> array) => //.. do something

public void Main(args[] arg) 
{
  var array = new array[100];
  var managed = Marshal.AllocHGlobal(100);
  var unmanaged = stackalloc byte[100];

  ProcessByteArray(new Span<byte>(array, 100));
  ProcessByteArray(new Span<byte>(manage.ToPointer(), 100));
  ProcessByteArray(new Span<byte>(unmanaged, 100));

  Marshal.FreeHGlobal(managed);
}
```

In the case of a string, each time you call the `string.Substring` method, you are allocating a new string on the managed heap. By utilizing a `ReadOnlySpan<char>` (read-only like the string type is), you can instead perform a more efficient search of the string without creating new objects on the heap.

There is a library of helpers in the `PrimitiveParser` class that can be used to convert a `byte[]` into primitive types like an `int`.

## Section 7: Data Access Performance: Entity Framework Core

### Make faster Queries with Entity Framework Core

You should utilize profilers like Prefix and MiniProfiler to view the SQL Statements as they are called. This will allow you to seek out inefficiencies in your queries. While in development mode, Entity Framework Core will also write the queries to the debug console.

All filtering should be done in the database first, instead of in C#. For example, you should filter using the `Where` method and `Select` method to build an efficient query instead of making C# handle the query. `Where` will return on the objects you are searching for, while `Select` will return only the properties you need, which puts less stress on your code.

A good practice when working with a large database is to utilize paging instead of returning all rows back from a database, which will cut back on the total response time.

Entity Framework Core also supports asynchronous statements as well, like the `ToListAsync` statement. This will prevent the threads from being idle while the program is waiting for the database call to complete. This will not result in faster code for small data sets, but for multiple users trying to call your database at once, this can make all the difference.

### Loading Dependent Entities Efficiently

Before, you were able to lazy load the dependent entities (like comments on a post), but this would still result on a lot of calls. Instead, you can utilize eager loading and explicit loading.

#### Eager Loading

Related entities are loaded from the database as part of the initial query. Simply call `DbSet<T>.Include` to tell Entity Framework Core to also grab the related entities as well. This will reduce the number of queries down to two, one for the dependency and one for the dependent items.

With the include, you can also limit the number of fields returned by calling the `SelectMany` method and the `GroupBy` method.

#### Explicit Loading

In scenarios where you want to load particular dependencies for only certain entries, you can utilize Explicit Loading (for example, loading comments for only one post). You would use something like below, which will populate the first post with all the related comments using only two queries (one for the list of posts, one for the comments of the first post).

```c#
DbContext.Entry(posts.First())
    .Collection(n => n.Comments)
    .Load();
```

This is ideal for loading only small subsets of dependencies from an original large query.

### EF Core Performance: Maximum Length, Client Side Execution, Change Tracking

#### Maximum Length

Entity Framework Core provides two methods to define the restrictions of your columns to make queries more efficient. Either through using the attributes of fluent API. For example, you can use the `MaxLengthAttribute` or the `.HasMaxLength(int)` method to limit the maximum length of a string. In the case of Dates where time is not important, you should set the column time to a `date` rather than a `datetime`.

#### Client Side Execution

Entity Framework Core executes part of the query in the database and part of the query on the client. If Entity Framework Core comes across a method that it cannot convert into SQL code, it will instead retrieve the entire database and execute it on the "client side" or in your C# code.

Entity Framework Core provides a method to warn you when these client side evaluations are occurring inside the `OnConfigure` method.

```c#
protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
{
  optionsBuilder.UseSqlServer("connectionString")
    .ConfigureWarnings(warn => warn.Throw(RelationalEventId.QueryClientEvaluationWarning));
}
```

#### Change Tracking

By default, EF Core tracks information about changes that the entities undergo, which will be used to make queries based on implied changes. If you have lots of read-only data, you will get a lot of unnecessary overhead. You can either disable tracking for a queries or globally for a particular context.

If you have a query that you know will not change anything, you can use the `.AsNoTracking()` method, which can potentially boost the performance of a query.

You can turn off change tracking for all queries using the `dbContext.ChangeTracker.QueryTrackingBehavior = QueryTrackingBehavior.NoTracking`, which will also boost the performance of your application.

## Section 8: .NET Core Specific Performance Tools and Configurations

This section will review three tools that can improve the performance of .NET Core code.

### Pre-JIT .NET Core Applications with CrossGen

You can use CrossGen images in .NET Core and can even CrossGen your own assemblies.

Converting code from C# code into Machine Code during the first compilation instead of "Just-in-Time" can be faster, since you don't have to wait for the JIT compiler to work.

In pervious .NET versions, you could use *ngen.exe* which will turn IL code to machine code and installs it on the native image cache. This is for full framework only and will result in a `.ni.dll` file called either a native, precompiled or an ngend image. This image contains both the IL code *and* the native code. **CrossGen** is the CoreCLR version of this process and is a cross-platform tool. This is called Ahead-of-Time compilation, or (AOT).

#### CrossGen

- No JIT at runtime, meaning faster warmup
- Platform and CPU specific code, meaning you lose compatibility
  - You will need to CrossGen your application for each platform

With CrossGen, there is no compilation at runtime. When you use CrossGen and the shared framework, you will use already CrossGen images. In self-contained apps, the default packages are not made into CrossGen images.

Usually, the first request to an application will take the most time because of the JIT compiler converting the IL code to machine code. With CrossGen, you can bypass this wait time during Compilation.

> *Note: the shared libraries are already passed through CrossGen*

### Make your .NET Core Application Smaller with Mono's Linker

Mono's IL Linker will help you ship only the minimal IL code that your application requires to run. This is already used by Xamarin and was introduced to .NET Core via the .NET IL Linker. This will result in smaller deployment packages and is especially good microservices and applications where you deploy frequently.

As of the time of this course, the feature is only in a preview state, so all resulting code should be tested thoroughly before being published to production.

The .NET Linker only works with a self-contained application, so you must specify a runtime identifier.

The linker is a basic NuGet package (at the time of the course, you must add an additional package source in order to retrieve it). Once added to an application, the linker will automatically perform its process when the application is published.

The linker only works with self-contained applications since a lot of the unused code is in the framework itself, and removing part of a shared framework is not practical. If your application uses reflection, you must do extra work, since the reflection API does not expose types the linker will not detect the references; there is a workaround for this issue available on GitHub.

### Faster Startup with ASP.NET Core Precompiled Views

Unlike Mono's Linker and CrossGen, this feature is very stable and can be comfortably used without additional testing. However, this is only available in ASP.NET with Razor Pages. By default, views are compiled when the view is called. This allows you to modify views without recompiling the entire application, but also means that larger views have performance impacts.

With precompilation, you lose the ability to modify those files without a full recompile, but you will have a much smaller footprint for all your views and a faster response time.

> If you see your "View" folder in your output, then you do not have precompilation enabled

When enabled, precompilation will create a *.PrecompiledViews.dll file when published which contains the code of the views.

To turn on precompilation, you must add a reference to the *Microsoft.AspNetCore.StaticFiles* package and add the `<MvcRazorCompileOnPublish>true</MvcRazorCompileOnPublish>` tag to the .csproj file. The next time you publish your application, the view folder will be replaced with the precompiled dll.

For ASP.NET Core 2.0, this is enabled by default, but can be disabled.

If you are using full Framework, then you must add the *Microsoft.AspNetCore.Mvc.Razor.ViewCompilation* package.

## Section 9: Performance Monitoring in Production for .NET Core

This section will discuss how you can monitor the performance of your code and its dependencies while it is running.
When collecting data from the development environment, you aren't gathering information pertinent to the production machine.

### Enabling Application Insights for ASP.NET Core Applications

Application Insights can be added using Visual Studio by right clicking the project, hovering over the "Add" menu, and clicking the "Application Insights..." which will then open a wizard for passing telemetry data to a Microsoft account. There is a Free Version of Application Insights, and you can automatically stop the collection of data once you reach the limitation of the free tier. Once added, a few configuration files were edited automatically by the wizard and data will be sent to the azure portal online.

The Application Portal will include metrics like server response time, page view load time, server requests, etc. It can also include the number of JavaScript issues encountered and the number of failed requests.

At the time of the course recording, Application Insights didn't yet support Entity Framework Core, but the feature should have been added by now so that you can monitor your database as well.

### Tracking Slow Requests and Performance Testing with Application Insights

Application Insights allows you to narrow down requests by their response time, enabling you to analyze slow requests with information like the URL they called, where it was called from, and what kind of dependencies your page(s) have.

A.I. also provides access to Performance Testing features, which will allow you simulate *n* number of users from a certain server for *m* minutes. This will give you useful information like failure rate and response time. (In general, you don't want to perform this on a live site, but on a development server instead. Otherwise you would mix test results with your real metrics.) The load tester will tell you which resources failed when, and will also provide which HTTP status code the simulation received, allowing you to test when your application breaks under a stress test.

The application can be running everywhere, it doesn't have to be on Azure, it only needs to be able to communicate with Azure. It is a common misconception that Application Insights only works with .NET, when in reality there are SDKs for many other frameworks and runtimes.

### Tracking Custom Dependencies with Application Insights

Application Insights can allow you to write in-depth monitoring code using its API. This will provide a greater depth of information for incoming requests. Utilizing the `TelemetryClient` class will allow you to manually track a number of events and telemetry data. This class is thread-safe, so it can be added to your code without issue as a new instance.

- `TelemetryClient.TrackDependency` - allows you to track certain calls to dependencies
- `TelemetryClient.TrackMetric` - accepts a `MetricTelemetry` object
- `TelemetryClient.TrackEvent` - accepts a key-value list of properties

Using these methods, you can send more data along with your requests and get an in-depth look at what your code resulted in. You can also view the CustomMetric results in a graph format to see how quickly your code is functioning.

### Monitoring .NET Core Applications with Dynatrace

**Note:** the course instructor has disclosed that he works with Dynatrace

[Dynatrace](http://www.dynatrace.com) is a full stack monitoring solution for many environments and frameworks. It can be installed via Azure by utilizing a Token and installing the "Dynatrace OneAgent" extension.

Dynatrace will automatically determine the layout of your application including the different layers and services being called, the hosts and data centers, and more. Much like Application Insights, you can see request information including response time, but also host information like the CPU and Memory usage.

Using Dynatrace, monitoring certain methods is slightly different. Instead of adding code, you can add monitoring using the Dynatrace UI by diging through the .dll file.
