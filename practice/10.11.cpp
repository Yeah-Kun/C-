#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;


void elimDups(vector<int> &msg){
    sort(msg.begin(), msg.end());
    auto unique_it = unique(msg.begin(), msg.end());
    msg.erase(unique_it, msg.end());
}


int main(){
    vector<int> msg = {3,23,2,321,0,4,23,4,2,3};
    elimDups(msg);
    stable_sort(msg.begin(), msg.end());
    for(const auto & num : msg){
        cout << num << " ";
    }
    return 0;
}