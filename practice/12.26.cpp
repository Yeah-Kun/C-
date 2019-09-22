#include <iostream>
#include <memory>
#include <string>

using namespace std;


int main(){
    const int n = 3;
    // string *const p = new string[n];
    // string s;
    // string *q = p;
    // while (cin >> s && q != p + n){
    //     *q++ = s;
    //     cout << s << std::endl;
    // }
    // const size_t size = q - p;
    // delete[] p;


    allocator<string> a;
    auto p = a.allocate(n);
    string* q = p;

    string s;

    while(cin >> s && q != p + n){
        a.construct(q, s);
        cout << s << std::endl;
    }
    a.destroy(p);

    a.deallocate(p, n);
    return 0;
}
