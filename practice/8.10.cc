#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
	ifstream in(argv[1]);
	if(!in)
	{
		cerr << "cannot open file";
		return -1;
	}
	string line, word;
	vector<string> v;
	while(getline(in, line))
	{
		v.push_back(line);
	}
	in.close();
	auto it = v.begin();
	while(it != v.end())
	{
		istringstream reader(*it);
		while(reader >> word)
			cout << word << endl;
		++it;
	}
	return 0;
}