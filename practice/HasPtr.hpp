#include <iostream>
#include <string>

class HasPtr{
public:
    HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0){}
    HasPtr(const HasPtr& h):ps(new std::string(*h.ps)),i(h.i){}
    HasPtr& operator=(const HasPtr& h){
        ps = new std::string(*h.ps), i = h.i; 
        return *this;
    }
private:
    std::string *ps;
    int i;


};