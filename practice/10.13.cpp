#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

bool isLong(string& s1){
    return s1.size() < 5;
}

vector<string>::iterator GetString(vector<string>& msg){
    return partition(msg.begin(), msg.end(), isLong); // 要让大于等于5的值放在后面，即要让大于等于5的值为false
}

int main(){
    vector<string> msg = {"revenue", "good", "sheel", "isbn" };
    auto s_it = GetString(msg);
    while(s_it != msg.end()){
        cout << *s_it << " ";
        s_it ++;
    }
    return 0;
}