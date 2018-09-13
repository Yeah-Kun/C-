#include<iostream>
#include<fstream>
#include <string>
#include <windows.h>

using namespace std;


istream& accept(istream& c)
{
	string s;
	while(c >> s, !c.eof())
	{
		if (c.bad())
			throw runtime_error("遇到了系统级的错误");
		else if(c.fail())
			throw runtime_error("遇到了一些错误");
		cout << s <<endl;

	}
	c.clear();
	return c;
}

int main(int argc, char const *argv[])
{
	accept(cin);
	system("pause");
	return 0;
}