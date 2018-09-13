#include <iostream>
#include "Person.h"

using namespace std;

int main(int argc, char const *argv[])
{
	Person p1("kk","wyu");
	cout << p1.getName() << " " << p1.getAddress() << endl;
	return 0;
}