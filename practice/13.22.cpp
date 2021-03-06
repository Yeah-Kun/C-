#include<iostream>
#include<string>

class HasPtr{
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0){}
    
    // 拷贝构造函数
    HasPtr(const HasPtr& p){
        this->ps = new std::string(*(p.ps));
        this->i = p.i;
    }


    // 复制构造函数
    HasPtr& operator=(const HasPtr& p)
    {
        auto newp = new std::string(*(p.ps));
        delete ps;
        this->ps = newp;
        this->i = p.i;
        return *this;
    }

    std::string GetString(){
        return *ps;
    }


private:
    std::string *ps;
    int i;
};

int main()
{
    HasPtr origin("good job!");
    HasPtr assignmentPtr = origin;
    HasPtr copyPtr(origin);
    std::cout << assignmentPtr.GetString() << "\ncopy:" << copyPtr.GetString() << "\n";
    return 0;
}


