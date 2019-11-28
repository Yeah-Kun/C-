#include <iostream>
#include <string>

using namespace std;

class numbered
{
public:
    numbered(){mysn = gen_mysn++;}
    int mysn;

private:
    

    static int gen_mysn;
};

int numbered::gen_mysn  = 0;

void f(numbered s)
{
    cout << s.mysn << "\n";
}


int main()
{
    numbered a, b=a, c=b;
    f(a);
    f(b);
    f(c);

    return 0;
}