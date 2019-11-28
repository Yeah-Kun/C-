#include <iostream>
#include <string>

using namespace std;

class Employee
{
public:
    Employee(string s):m_name(s){
        m_number = ++s_number;
    };


private:
    static int s_number; 

    string m_name;
    int m_number;
    

};

int Employee::s_number = 0;


int main(){
    Employee e("aa");
    Employee ee("bb");
    return 0;
}


