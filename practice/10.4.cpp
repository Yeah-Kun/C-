#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void outmsg(vector<string>& msg){
    for(auto it = msg.begin(); it != msg.end(); it++){
        cout << *it << endl;
    }
}

void elimDups(vector<string> &msg){
    sort(msg.begin(), msg.end());
    auto unique_it = unique(msg.begin(), msg.end());
    msg.erase(unique_it, msg.end());
}


int main(){
    string word;
    vector<string> msg;
    while(cin >> word){
        if(word == "\n") break;
        msg.push_back(word);
    }
    outmsg(msg);
    elimDups(msg);
    outmsg(msg);

    return 0;
}
