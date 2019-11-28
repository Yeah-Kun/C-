#include<iostream>
#include<string>

// 像指针的类
class HasPtr{
public:
    HasPtr(const std::string &s = std::string()):ps(new std::string(s)), i(0)
    {
        referenceCounter = new std::size_t(1);
    }

    // 拷贝构造函数
    HasPtr(const HasPtr& p){
        ++*p.referenceCounter;
        this->ps = p.ps;
        this->i = p.i;
        this->referenceCounter = referenceCounter;
    }


    // 复制构造函数
    HasPtr& operator=(const HasPtr& p)
    {
        ++*p.referenceCounter; // 递增右侧的计数器
        --(*(this->referenceCounter)); // 递减左侧计数器
        if(*(this->referenceCounter) == 0){
            delete ps;
            delete referenceCounter;
        }

        this->ps = p.ps;
        this->i = p.i;
        this->referenceCounter = p.referenceCounter; // 指针换成右侧的
        return *this;
    }

    ~HasPtr()
    {
        --*referenceCounter;
        if(*referenceCounter == 0){
            delete ps;
            delete referenceCounter; // 不要忘了delete引用计数器
        }
    }


    std::string GetString(){
        return *ps;
    }


private:
    std::string *ps;
    int i;

    std::size_t *referenceCounter;
};


int main(int argc, char *argv[])
{

    HasPtr origin("good job!");
    HasPtr assignmentPtr = origin;
    HasPtr copyPtr(origin);
    std::cout << assignmentPtr.GetString() << "\ncopy:" << copyPtr.GetString() << "\n";

}

