#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	string s1, s2, s;
	s = argv[0];
	s1 = argv[1];
	s2 = argv[2];
	cout << "1 parm:" << s << endl;
	cout << "2 parm:" << s1 << endl;
	cout << "3 parm:" << s2 << endl;
	return 0;
}