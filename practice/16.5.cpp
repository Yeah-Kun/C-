#include<iostream>
#include<string>
#include<vector>
#include<list>


using namespace std;

template <typename T>
ostream& print(ostream& os, const T &any_array, const size_t &n)
{
    for(size_t i = 0; i < n; i++)
    {
        os << any_array[i];
    }
    os << "\n";
    return os;
}

int main()
{
    char bb[] = "good job";
    print(std::cout, bb, 8);
    return 0;
}