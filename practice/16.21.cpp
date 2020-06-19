#include<iostream>
#include<string>
#include<vector>

using namespace std;

class DebugDelete{
public:
    DebugDelete(std::ostream& s = cerr):os(s){}
    template<typename T>
    void operator()(T *p)const{
        os << "delete unique_ptr." << std::endl;
        delete p;
    }

private:
    ostream& os;
};


int main()
{
    DebugDelete d;
    int* pi = new int;
    d(pi);

    return 0;
}