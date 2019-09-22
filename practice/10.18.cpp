#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/* 容器排序，并输出大于sz的单词 */
void biggies(vector<string> &words, vector<string>::size_type sz)
{
    stable_sort(words.begin(), words.end(), 
        [](const std::string &s1, const std::string &s2){return s1.size() <= s2.size();});

    auto wi = partition(words.begin(), words.end(), 
                    [sz](const std::string &s){return s.size()<sz;});
    
    for_each(wi, words.end(), 
            [](const std::string &s){cout << s << " ";});
    
    cout << endl;
}

int main(){
    vector<string> msg = {"revenue", "good", "sheel", "isbn", "a", "stl" };
    biggies(msg, 4);
    return 0;
}