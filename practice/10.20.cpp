#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<string> msg = {"aaa", "bbbbb", "cccccc", "dddddddddd", "333333", "ffffffff", "e", "j"};
    int counter = count_if(msg.begin(), msg.end(), 
        [](const string& s1)
            {return s1.size() > 6;});

    cout << counter << endl;
}