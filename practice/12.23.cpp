#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main()
{

    int x = 1;
    // 1.
    if(x == 1){
        const int num_s1 = 5;
        const int num_s2 = 4;
        char s1[num_s1] = "good";
        char s2[num_s2] = "job";
        char* c = new char[num_s1 + num_s2 - 2];
        memcpy(c, s1, (num_s1 - 1) * sizeof(char));
        memcpy(c + (num_s1 - 1), s2, (num_s2 - 1)  * sizeof(char));

        delete[] c;

    }

    // 2.
    else if (x == 2)
    {
        string s1("good");
        string s2("job");
        const int num_all = s1.size() + s2.size();
        char *c = new char[num_all];
        memcpy(c, s1.data(), s1.size() * sizeof(char));
        memcpy(c + s1.size(), s2.data(), s2.size() * sizeof(char));
        delete[] c;
    }


    // 3. 官方答案
        /*
            1. 可以使用strlen获得字符串长度
            2. 如果保存的是字符串，new的时候要多加1位，保存'\0'
            3. 可以使用strcpy拷贝字符串
            4. 可以使用strcat连接字符串
         */
    return 0;
}