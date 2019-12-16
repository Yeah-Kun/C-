#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Resources
{
public:
    Resources(size_t n)
    {
        p = new int[n];
    }
    ~Resources()
    {
        delete[] p;
    }

private:
    int *p;

};


void exercise(int b, int e)
{
    vector<int> v(b, e);
    Resources res(v.size());
    try
    {
        ifstream in("ints");
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << "\n";
    }
    
}

int main()
{
    int a = 10;
    int c = 20;
    exercise(a, c);

    return 0;
}