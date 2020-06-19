#include <iostream>
#include <string>

using namespace std;

class PrintString {
public:
	PrintString(istream &in = cin, char c = ' ')
		: is(in), os(cout), seq(c) {}

	void operator()()
	{
		string s;
		while (is) {
			is >> s;
			os << s << seq;
		}
	}

private:
	istream &is;
	ostream &os;
	char seq;
};



int main()
{
	PrintString a= PrintString(cin, '\n');
	a();
	return 0;
}