#include <iostream>
#include <windows.h>
#include "Sales_data.h"
using namespace std;

int main(int argc, char const *argv[])
{
	Sales_data d1,d2;
	double price = 0; // 书的单价
	cin >> d1.bookNo >> d1.units_sold >> price;
	d1.revenue = d1.units_sold * price;
	cout << "revenue: " << d1.revenue <<endl;
	return 0;
}