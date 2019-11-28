#include <iostream>
#include <string>

struct X{
    X() {std::cout << "X()" << "\n";}
    X(const X&){std::cout << "X(const X&)" << std::endl;}

    // 构造拷贝运算符

    // 析构函数

};

int main()
{



    return 0;
}
