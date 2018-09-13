#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	double pi = 3.14;
	double * const ptr = &pi; // ptr是指向常量对象的常量指针
	*ptr = 3.1415926; // 正确，将pi的值改成3.1415926
	cout << "pi: " << pi << endl;
	return 0;
}
