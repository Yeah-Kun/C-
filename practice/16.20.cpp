#include<iostream>
#include<string>
#include<vector>
#include<list>

using namespace std;


template <typename ctr>
void PrintContainer(ctr& c)
{
    for(auto it = c.cbegin(); it != c.cend(); ++it)
    {
        cout << *it << " ";
    }
}


int main()
{
    vector<int> iv = {1112,3234,2,34,3,5,6,45,56,7};
    list<string> ls = {"good", "good", "study", "day", "day", "up"};
    PrintContainer(iv);
    cout << "\n";
    PrintContainer(ls);
    return 0;
}