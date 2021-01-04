#include <iostream>

template <int num = 4>
void DoStuff()
{
	std::cout << num << '\n';
}

int main()
{
	DoStuff<10>(); // Output: 10
	DoStuff<>(); // Output 4 (from default)

	return 0;
}
		
