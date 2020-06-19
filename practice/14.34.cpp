#include <iostream>
#include <string>

using namespace std;

class PrintSelect
{
public:
    int operator()(int d1, int d2, int d3)
    {
        if (d1 > 65535)
            return d2;
        else
            return d3;
    }
};


int main()
{
    PrintSelect p;
    int j = p(65534, 0, 65534);
    int k = p(65536, 0, -1);
    cout << j << "\n" << k;
    return 0;
}