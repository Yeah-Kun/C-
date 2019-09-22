#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	std::vector<int> v(10,1);
	int giveValue = 1;
	int counter_ptr = count(v.cbegin(), v.cend(), giveValue);
	cout << "giveValue出现的次数：" << counter_ptr << endl;
	return 0;
}