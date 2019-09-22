#include <algorithm>
#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	std::list<string> v(99,"1");
	string giveValue = "1";
	int counter_ptr = count(v.cbegin(), v.cend(), giveValue);
	cout << "giveValue出现的次数：" << counter_ptr << endl;
	return 0;
}