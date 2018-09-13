#include <iostream>
#include <windows.h>

using namespace std;
int main(int argc, char const *argv[])
{
	int a[10],i = 0;
	for (auto aa : a)
	{
		aa = i;
		i++;
		cout << aa << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}