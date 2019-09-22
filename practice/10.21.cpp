#include <iostream>

using namespace std;

int main()
{
    int key = 3;
    auto f = [&]()->bool{
        if(key > 1){
            key--;
            return true;
        }
        else{
            key = 0;
            return false;
        }
    };
    cout << f() << endl;
    cout << f() << endl;
    cout << f() << endl;
    cout << f() << endl;
}
