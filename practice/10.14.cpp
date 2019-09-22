#include <iostream>
#include <string>
#include <vector>



using namespace std;

int main(){
    int a = 10;
    int b = 13;
    auto sum = [a,b](){return a+b;}; // 函数
    auto sum_v2 = [](const int &a, const int &b){return a+b;};
    cout << sum() << endl;
    cout << sum_v2(a,b) <<endl;
}
