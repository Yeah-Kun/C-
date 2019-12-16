#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Base{
public:
    virtual int fcn();


};


class D1: public Base{
public:
    int fcn() override; // 修改
    virtual void f2();
};


class D2: public D1{
public:
    int fcn(int);
    int fcn();
    void f2();
};

int main()
{
    Base obj; D1 obj1; D2 obj2;
    Base *p1 = &obj1; D1 *p2 = &obj2; D2 *p3 = &obj2;

}