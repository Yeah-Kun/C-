#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void exercise(int b, int e)
{
    vector<int> v(b, e);
    int *p = new int[v.size()];
    try
    {
        ifstream in("ints");
    }
    catch(const std::exception& e)
    {
        delete [] p;
        std::cout << "fix the problem.\n";
    }
    
}

int main()
{
    int a = 10;
    int c = 20;
    exercise(a, c);

    return 0;
}