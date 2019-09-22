#include<iostream>
#include<vector>

using namespace std;

std::vector<int> *new_vector(void)
{
	return new (nothrow) std::vector<int>;
}

void read_ints(std::vector<int> *pv)
{
	int d;
	while(cin >> d)
	{
		pv->push_back(d);
	}
}

void print_ints(vector<int> *pv)
{
	for(auto v : *pv)
	{
		cout << v << " "; 
	}
	cout << endl;
}

int main()
{
	std::vector<int>* pv = new_vector();
	if(!pv){
		cout << "内存不足" << endl;
		return -1;
	}
	read_ints(pv);
	print_ints(pv);
	delete pv;
	pv = nullptr;
	return 0;
}