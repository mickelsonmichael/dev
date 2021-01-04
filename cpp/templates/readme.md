# Templates in C++

In C++, the compiler does a large amount of backend work that the developer won't see. The _template_ is exactly that, a template for how the compiler should write the functions. Then at compile-time, it will generate a function for each of the types utilizing the template; if you had a template that was used by both an `int` and a `double` (but not a `string`), then the compiler would generate two separate functions, one for the `int` and one for the `double` (and no `string` method will be generated.

It is also the case that non-template functions will always take precedence over expanded templates. If you have a template and a non-template function with the same name, then the compiler will favor the non-template version over the template version.

There can be ambiguity when a template can be matched by two (or more) of the expanded functions at once. For instance, if you had an `Add(T a, T b)` method, then a conflict would occur if you attempted to send in a `double` and an `int` as the parameters, since the compiler doesn't know whether to send it to the `Add(double a, double b)` expansion or the `Add(int a, int b)` expansion. Thus, a compile-time error is thrown.

## Function Templates

A function template is as described in the above paragraph; a function is defined "generically" by the programmer, then the compiler "expands" that function out into multiple copies of the same function.

When declaring a function template, you preface the function definition with either `template <typename _type_>` or `template <class _type_>`, which are interchangeable, but the former seems to be the preferred method.

```c++
template <typename ValueType>
ValueType Add(ValueType a, ValueType b)
{
	return a + b;
}
```

## Class Templates

Very similar to [function templates](#function-templates), class templates will be expanded out to multiple versions of the same class to support each of the types that is passed to it. Due to the poor support for separate compilation of class templates, they are generally defined in the same file they are implemented in (meaning there is no separate header file from the class file); many of the standard libary classes follow this pattern. Changes to the C++ Standard, however, make the split compilation more appealing, but the syntax for the separate files is still cumbersome, since the class implementation will need to include `template <typename Object>` before each function definition.
 
```c++
template <typename Object>
class ObjectThing
{
	public:
		void DoThing(const Object & = Object());
};
```

## Other Features

### Multiple Template Parameters

You can define a (theoretically) infinite number of template parameters (e.g. `template <typename Object, typename ValueType>`). This is evident in the Standard Library type `map`, which allows for key values pair definitions like `map<int,string>`.

### Template Nontype Parameters

While it is initially hard to see the purpose behind them, the nontypes parameters provide the advantage that they must be compile-time constants, and thus can be used in place of other compile time constants.

```c++
template <int size>
void makeArray()
{
	auto myArray = new int[size]; // Works because of compile time constant
}

makeArray<101>();
```

The main disadvantage to this is the potential "code bloat" that comes from creating a separate definition for every value passed into the function.

### Default Template Parameters

You can define default values for both type and nontype parameters, like `template <typeclass Object=char>` or `template <int size=0>`. You can then rely on those defaults by omitting the arguments in the declaration like `myFunc<>()`.

### Member Templates

This is the usage of a template within a template. The example provided in _C++ for Java Programmers_ is to fix typing issues for copy constructors.

```c++
template <typename T, typename K>
public class Mathman
{
	public:
		Mathman(const T &a, const K &b)
			: A(a), B(b) {} // Default constructor

		template <typename R, typename M>
		Mathman(const Pair<R,M> &rhs`)
			: A(rhs.A), B(rhs.B) {} // templated constructor allowing more copies

	private:
		T A;
		K B;
}
```

It is important to remember that there is no dynamic typing in C++, the types are defined at compile time, so while `Mathman<int, double>` could theoretically be converted to `Mathman<long, float>`, they are separate types in the compiled code and cannot be properly converted. Thus, why we need to create the templated copy constructor in the code sample above.

