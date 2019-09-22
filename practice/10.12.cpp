#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Sales_data3.h"

using namespace std;


bool compareIsbn(const Sales_data& s1, const Sales_data& s2){
    return s1.isbn().size() < s2.isbn().size() ? true : false;
}


int main(){
    vector<Sales_data> msg = { Sales_data("good"), Sales_data("fix"),Sales_data("sheel"),Sales_data("a")};
    stable_sort(msg.begin(), msg.end(), compareIsbn);
    for(const auto& s : msg){
        cout << s.isbn() << " ";
    }
    return 0;
}