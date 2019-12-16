#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Base{
public:
    void pub_mem();
    std::size_t size() const {return n;}
protected:
    int prot_mem;
    size_t n;
private:
    char priv_mem;
};

struct Pub_Derv : public Base{
    int f()
    {
        return prot_mem;
    }

};

struct Priv_Derv : private Base{
    int f1() const {
        return prot_mem;
    }
};


struct Derived_from_Public : public Pub_Derv
{
    int use_base()
    {
        return prot_mem;
    }
};

struct Derived_from_Protected : protected Pub_Derv
{
    int use_base()
    {
        return prot_mem;
    }
};

class Derived : private Base{
public:
    using Base::size;

protected:
    using Base::n;

};


int main(){
    Pub_Derv d1;
    Priv_Derv d2;
    Derived_from_Public dd1;
    Derived_from_Protected dd3;

    Base *p = &d1;

    p = &dd1;
    p = &dd3;

    return 0;
}