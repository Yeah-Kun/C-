#include<iostream>
#include<string>
#include<vector>
#include<list>

using namespace std;


template <typename ctr>
void PrintContainer(ctr& c)
{
    // for(size_t i = 0; i < c.size(); i++)
    // {
    //     cout << c[i] << " ";
    // }
    for( auto item : c){
        cout << item << " ";
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