# C# 7 Features

Most information in this section will be based upon the Udemy course "High Performance Coding with .NET Core and C#."

- [C# 7 Features](#c-7-features)
  - [Local Methods](#local-methods)
    - [Update January 17, 2020](#update-january-17-2020)
  - [`async` and `await`](#async-and-await)
  - [System.ValueTuple vs System.Tuple](#systemvaluetuple-vs-systemtuple)

## Local Methods

In cases where you are repeating the same thing over and over but only in one method, you may get performance benefit by using a local method instead of a delegate while having better encapsulation than a private method. See the example below.

```c#
public int Factorial(int x)
{
    var value = 0;

    // the delegate function
    Func<int, int, int> fact = (a, b) => return a * b;

    while (x > 0) {
        value = fact(value, x); // the delegate will be called repeatedly
        x--;
    }

    return value;
}

public int Factorial_Local(int x)
{
    var value = 0;

    while (x > 0) {
        value = fact(value, x);
        x--;
    }

    return value;

    int fact(int a, int b) {
        return a * b;
    }
}
```

The two methods in the example will perform the same operation, but when condensed down to IL code, the local function in the second example will be converted to a private method on the class. This leads to utilizing the more efficient `call` operation, where the first example would utilize a virtual call instead, which can potentially be a much more expensive operation than the standard `call`.

As of now, I don't know that I will use this very often. I might begin to slip it in here and there, but I'm afraid that general knowledge might not be ready for it; people haven't seen it enough to be comfortable with it. In C# it looks ugly like something that won't compile.

- Pros
  - Faster IL code than a delegate
  - Better encapsulation than a private method
- Cons
  - Other programmers may not be used to seeing it
  - You cannot reuse the code outside of the method
    - However, you could simply rewrite it as a private method without much trouble

### Update January 17, 2020

*Employer:* Lake Michigan Credit Union  
*Project:* CMS

In the `PageHistoryService` class, I went through and replaced all functions that only had one reference with a local function. This was too far. It was no longer clean code; the functions, while subdivided, were still very long. Additionally, inline functions do not have the benefit of summary documentation.

After a discussion with Lyn and Leighann, we decided that local functions are best used for short, one reference methods. Generally somewhere where a lambda method would be used. They should not be used to replace a private method that does several things. The limit for a local function should comfortably be 3 lines, but 1 line is the ideal.

## `async` and `await`

This is a more complex topic that I'm still coming to grips on in the early days of 2020.

I recently read [this article from "The DEV Community"](https://dev.to/zhiyuanamos/async-await-from-zero-to-hero-a22) which really narrowed things down for me to start things off.

Additionally, I went through the Udemy course *High Performance Coding with .NET Core and C#*, which introduced me to some of the more performant C# 7 features, including a bit of information about `async` and `await`. While going through the course I realized I had been using some features of the `await` operator poorly. The real power comes from the fact that you can start a task running by calling the method, then await the result later when you actually need it. See the example below.

```c#
public async Task<double> DoSomeHardMath()
{
    double result = 0;
    var pi = GetPi(); // cal the async method without await

    // do some more maths here that's really hard but doesn't yet require pi
    result += 100;

    result *= await pi; // finally get the value of pi

    return result;
}

public async await GetPi()
{
    var httpClient = new HttpClient();
    var request = httpClient.GetStringAsync("someurltogetpi");

    return await request;
}
```

The example above demonstrates that you can call the method before you need the value, continue computations, then finally use the `await` keyword once you need the value itself. When you call the method, the process will continue to calculate the value, `GetPi()` in this example, in the background, and by calling `await`, you tell the process to either wait for the method to finish or to immediately use the value you obtained!

## System.ValueTuple vs System.Tuple

The `System.ValueTuple` class is the more mature version of the `System.Tuple` class. The advantage of the new class is that it does not implement a value type, it can be stored on the heap. Additionally, it is a language tool and not a class like the original `Tuple` class.

The performance saved by using the `ValueTuple` over the `Tuple` is most likely negligible, so you don't need to swap out older code with these updated values. Instead you should use the `ValueTuple` class with new code, since it is now the gold standard.
