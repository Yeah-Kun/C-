#include<iostream>
#include<string>
#include<vector>
#include<list>


using namespace std;

template <typename T_ctr_iter, typename T_type>
bool find_in_ctr(const T_ctr_iter& biter, const T_ctr_iter& eiter, const T_type& value)
{
    for(T_ctr_iter iter = biter; iter != eiter; iter++)
    {
        if((*iter) == value){
            return true;
        }
    }
    return false;
}

int main()
{
    vector<int> v{1,2,3,4,5,6,7,8,9};
    list<string> l{"good", "bad", "study", "day", "up"};
    std::cout << find_in_ctr(v.begin(), v.end(), 12) << "\n";
    std::cout << find_in_ctr(l.begin(), l.end(), "up") << "\n";
}


