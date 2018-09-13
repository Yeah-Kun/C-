#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	string s1, s2, s;
	s = argv[0];
	s1 = argv[1];
	s2 = argv[2];
	s = s1 + s2;
	cout << s << endl;
	return 0;
}