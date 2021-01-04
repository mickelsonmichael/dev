# `var` Test

The [C# Coding Conventions](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/inside-a-program/coding-conventions#implicitly-typed-local-variables) page on MSDN recommends the following:

> Use implicit typing to determine the type of the loop variable in for loops.

For example, 

```c#
for (var i = 0; i < 100; i++)
{
  Console.WriteLine(i);
}
```

However, this is unlike the convention that I usually follow, where I always explicitly define the variable `i` to be an `int` (unless I need a `byte` or other data type).
In C++, the compiler does some intelligent casting when utilizing the `auto` feature.
So I was curious whether the C# compiler was intelligent enough to recognize if the condition of the loop required a larger number than a simple `int` and would compensate by defining `i` as a `long`.
Thus I wrote this small program to double-check that theory.

The end result is: *No*. The compiler will take the type of the literal you define. Thus, `var i = 0` will be an `int` and `var i = 0L` will be a `long`.

Therefore, I don't really agree with this particular convention. It seems unecessary; we aren't saving any characters or any though on the part of the developer, so why would we enforce the convention.
