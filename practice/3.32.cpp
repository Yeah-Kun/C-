#include <iostream>
#include <windows.h>

using namespace std;
int main(int argc, char const *argv[])
{
	const int array_size = 10;
	int a[array_size],b[array_size],i = 0;
	for (;i<array_size;i++)
	{
		a[i] = i;
	}
	i = 0;
	for (auto bb : b)
	{
		bb = a[i];
		cout << bb << " ";
		i++;
	}
	for(auto aa : a)
		cout << aa << " ";
	cout << endl;
	//system("pause");
	return 0;
}
