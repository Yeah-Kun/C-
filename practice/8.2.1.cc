#include<iostream>
#include<fstream>

using namespace std;

int main(int argc, char const *argv[])
{
	ifstream(argv[1]);
	ofstream out;
	out.open(argv[1]);
	cout << out.failbit;
	out.open("in.exe");
	cout << out.failbit;
	return 0;
}
