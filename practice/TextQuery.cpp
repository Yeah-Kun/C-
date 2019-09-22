#include "TextQuery.hpp"


TextQuery::TextQuery(ifstream& infile):input_text(new vector<string>) {
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


