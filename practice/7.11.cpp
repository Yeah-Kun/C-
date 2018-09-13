#include <iostream>
#include "Sales_data3.h"

using namespace std;

int main(int argc, char const *argv[])
{
	Sales_data s1("9787515349435",50,49.9);
	//Sales_data s2(cin);
	//s1 = new Sales_data("9787515349435",50,49.9);
	cout << s1.isbn() << " ";
	cout << s1.units_sold << " ";
	cout << s1.revenue << endl;
	//cout << s2 << " ";
	cout << endl;
	return 0;
}