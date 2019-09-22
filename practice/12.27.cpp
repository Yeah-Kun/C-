#include "TextQuery.hpp"

int main(int argc, char *argv[]) {
	ifstream in("12.27.cpp");
	if (in) {
		runQueries(in);
		in.close();
	}
	return 0;
}


