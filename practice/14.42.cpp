#include<iostream>
#include<string>
#include<vector>
#include<functional>
#include<algorithm>

using namespace std;


int main()
{
    vector<int> iv = {1,2234,3,34,45,6,5,3,23,2,34,5,4634535,3,23,42345};
    int a = count_if(iv.begin(), iv.end(), bind2nd(greater<int>(), 1024));
    transform(iv.begin(), iv.end(), iv.begin(),bind2nd(multiplies<int>(), a));
    cout << a << "\n";
    for(auto one : iv){
        cout << one << " ";
    }
    return 0;
}