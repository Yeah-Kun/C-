#include<iostream>
#include<fstream>
#include<string>
#include <vector> 

using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	vector<string> v;
	ifstream in;
	in.open(argv[1]);
	if(!in)
	{
		cerr << "cannot open file" << endl;
		return -1;
	}
	while(in >> s,!in.eof())
	{
		v.push_back(s);
		cout << s << endl;
	}
	return 0;
}