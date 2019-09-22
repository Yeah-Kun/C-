#include <iostream>
#include <memory>

using namespace std;

int main(){
    unique_ptr<int> u(new int(10));
    cout << *u << endl;
}