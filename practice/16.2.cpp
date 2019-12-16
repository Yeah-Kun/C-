#include<iostream>


template <typename T>
int compare(const T& v1, const T& v2)
{
    if(v1 < v2) return -1;
    if(v2 < v1) return 1;
    return 0;
}

int main()
{
    int a = 10, c = 100;
    double ac = 10.0;
    std::cout << compare(a, c) << "\n";
    return 0;
}