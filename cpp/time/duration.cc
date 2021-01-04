#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
	hours h(24);
	seconds s = h;

	cout << h.count() << " hours = " << s.count() << " seconds" << endl;


	using custom = duration<float, ratio<500>>;

	custom mytime(h);

	cout << mytime.count() << " custom time units = " << h.count() << " hours" << endl;
	
	return 0;
}
