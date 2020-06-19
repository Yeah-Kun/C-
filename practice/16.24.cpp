#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <memory>
#include <set>

using namespace std;

template <typename T>
class Blob
{
public:
    template <typename It>
    Blob(It b, It e);

private:
    std::shared_ptr<vector<T>> data;
};

template <typename T>
template <typename It>
Blob<T>::Blob(It b, It e)
    : data(std::make_shared<std::vector<T>>(b, e))
{
}

int main()
{
    vector<int> vi = {123, 234, 23, 5, 34, 645, 2, 567, 68};
    Blob<int> bi(vi.begin(), vi.end());

    return 0;
}
