#include <iostream>
#include <string>

using namespace std;

template <typename T>
T Add(const T &a, const T &b)
{
	return a + b;
}

template <typename T, typename R>
auto AutoAdd(const T & a, const R & b)
{
	return a + b;
}

int main()
{
	int i = 6;
	double d = 2.0;

	string hey = "hey ", there = "there\n";

	cout << Add(i, i) << '\n'; // OK
	cout << Add(d, d) << '\n'; // OK
	cout << Add(hey, there); // OK

	// char[3] and char[6] are considered different types by the compiler
	// so we must explicitly define the parameters as string types
	// either by Add<string>() or by declaring the variables typed (as above in the hey and there vars)

	cout << AutoAdd(i, i) << '\n'; // OK
	cout << AutoAdd(d, d) << '\n'; // OK
	cout << AutoAdd(hey, there); // OK
	
	//cout << Add(i, d) << '\n'; // Ambiguous

	return 0;
}
