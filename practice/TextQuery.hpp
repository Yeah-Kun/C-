#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <memory>
#include <set>

using namespace std;

class DebugDelete{
public:
    DebugDelete(std::ostream& s = cerr):os(s){}
    template<typename T>
    void operator()(T *p)const{
        os << "delete unique_ptr." << std::endl;
        delete p;
    }

private:
    ostream& os;
};

class TextQuery {

public:
	TextQuery(ifstream& infile);
	shared_ptr<set<int>> query(const string& s);


	shared_ptr<map<int, string>> s_ptr;



private:
	shared_ptr<vector<string>> input_text;
	map<string,shared_ptr< set<int>>> result;


};


class QueryResult {

public:
	static ostream& print(ostream& out, shared_ptr<set<int>> index_ptr);

};



void runQueries(ifstream& infile);


