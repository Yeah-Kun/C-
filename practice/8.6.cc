// 保存文件求和结果
#include<iostream>
#include<fstream>
#include"Sales_data.h"

using namespace std;

int main(int argc, char const *argv[])
{
	Sales_data total;
	ifstream in(argv[1]);
	if(!in)
	{
		cerr << "cannot open file" << endl;
		return -1;
	}

	if(read(in, total)){
		Sales_data trans;
		while(read(in, trans)){
			if(total.isbn() == trans.isbn())
				total.combine(trans);
			else{
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;

	}else{
		cerr << "No data?" << endl;
	}
	in.close();
	return 0;
}