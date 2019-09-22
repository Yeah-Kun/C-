#include<iostream>
#include<vector>
#include<memory>

using namespace std;

shared_ptr<vector<int>> new_vector(void)
{
	return make_shared<vector<int>>();
}

void read_ints(std::shared_ptr<vector<int>> pv)
{
	int d;
	while(cin >> d)
	{
		pv->push_back(d);
	}
}

void print_ints(shared_ptr<vector<int>> pv)
{
	for(auto v : *pv)
	{
		cout << v << " "; 
	}
	cout << endl;
}

int main()
{
	shared_ptr<std::vector<int>> pv = new_vector();
	if(!pv){
		cout << "内存不足" << endl;
		return -1;
	}
	read_ints(pv);
	print_ints(pv);
	// delete pv;
	// pv = nullptr;
	return 0;
}