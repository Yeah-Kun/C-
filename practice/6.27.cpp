#include<iostream>

using namespace std;
int MySum(initializer_list<int> int_list)
{
	int count = 0;
	// for(auto num_ptr = int_list.begin(); num_ptr == int_list.end(); ++num_ptr){
	// 	count += *num_ptr;
	// }
	for(auto num : int_list){
		count += num;
	}
	return count;
}

int main(int argc, char const *argv[])
{
	std::cout << "sum: " << MySum({1,2,3,4}) << std::endl;
	return 0;
}