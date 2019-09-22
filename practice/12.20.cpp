#include <iostream>
#include <string>
#include <vector>

#include "StrBlob.hpp"

using namespace std;

int main(){
    // 自己虚构一个文件内容
    vector<string> msg{"book", "yellow", "chicken", "child"};

    StrBlob s;
    for(auto& m:msg){
        s.push_back(m);
    }
    for(auto it = s.begin(); neq(it, s.end()); it.incr()){
        cout << it.deref() << endl;
    }



    return 0;
}





