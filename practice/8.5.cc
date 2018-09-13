#include<iostream>
#include<fstream>
#include<string>
#include <vector> 

using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	vector<string> v;
	ifstream in(argv[1]);
	while(in >> s,!in.eof())
		v.push_back(s);

	in.close();
	
	while(s=v.begin(),s != v.end())
	{
		cout << s << endl;
		++s;
	}
	return 0;
}