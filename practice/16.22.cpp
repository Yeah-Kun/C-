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

TextQuery::TextQuery(ifstream& infile):input_text(new vector<string>, DebugDelete()) {
	string s, word;
	int i = 0;
	while (getline(infile, s)) {
		input_text->push_back(s);
		istringstream line(s);
		while (line >> word) {
			auto &wp = result[word];
			if (!wp) {
				wp.reset(new set<int>);
			}
			wp->insert(i++);
		}
	}
}


shared_ptr<set<int> > TextQuery::query(const string& s) {
	auto it = result.find(s);
	if (it != result.end()) {
		return it->second;
	}
	else return make_shared<set<int>>();
}


ostream& QueryResult::print(ostream& out, shared_ptr<set<int>> index_ptr) {
	if (index_ptr && index_ptr->empty()) {
		out << "element occurs " << index_ptr->size() << " times\n";
		for (auto it = index_ptr->cbegin(); it != index_ptr->cend(); it++) {
			out << "( line " << (*it) + 1 << ")\n";
		}
	}

	return out;
}


void runQueries(ifstream& infile) {
	TextQuery tq(infile);

	while (true) {
		cout << "Enter word to look for , or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q")break;
		QueryResult::print(cout, tq.query(s)) << endl;
	}
}


int main()
{
    ifstream in_f("in.txt");
    TextQuery t(in_f);

    return -1;
}