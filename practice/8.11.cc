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
	istringstream reader;
	while(in >> line)
	{
		v.push_back(line);
	}
	in.close();
	std::vector<string>::const_iterator it = v.begin();
	while(it != v.end())
	{
		reader.clear(); // 如果没有clear，istringstream将会与之前的流保留关联，无法与新的流产生联系
		reader.str(*it);
		while(reader >> word)
			cout << word << endl;
		++it;
	}
	return 0;
}