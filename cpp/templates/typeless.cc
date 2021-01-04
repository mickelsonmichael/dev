#include <iostream>

using namespace std;

template <int size>
void makeArray()
{
	auto ary = new int[size];

	delete[] ary;
}

int main()
{
	makeArray<32>();

	return 0;
}
