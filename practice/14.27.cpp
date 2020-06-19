#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class StrBlobPtr; // 需要前向声明

bool eq(const StrBlobPtr& s1, const StrBlobPtr& s2);
bool neq(const StrBlobPtr& s1, const StrBlobPtr& s2);




class StrBlob
{
    friend class StrBlobPtr;

public:
    
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    // 添加和删除元素
    void push_back(const std::string &t) { data->push_back(t); }
    void push_back(std::string&& t){ data->push_back(t); }
    void pop_back();
    // 元素访问
    std::string& front();
    std::string& back();

    StrBlobPtr begin();
    StrBlobPtr end();
    


private:
    std::shared_ptr<std::vector<std::string>> data;
    // 如果data[1]不合法，抛出一个异常
    void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob(): 
    data(make_shared<vector<string>>() ) {}

StrBlob::StrBlob(initializer_list<string> il):
    data(make_shared<vector<string>>(il)) {}


void StrBlob::check(size_type i, const std::string &msg) const{
    if(i >= data->size()){
        throw out_of_range(msg);
    }
}

std::string & StrBlob::front(){
    // 如果vector为空，check抛出一个异常
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string & StrBlob::back(){
    // 如果vector为空，check抛出一个异常
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back(){
    // 如果vector为空，check抛出一个异常
    check(0, "pop_back on empty StrBlob");
    return data->pop_back();
}


class StrBlobPtr{

    friend bool eq(const StrBlobPtr& s1, const StrBlobPtr& s2);

public:

    StrBlobPtr():curr(0){} // curr 显式置为0， 将wptr隐式地置为空
    StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) {}
    std::string& deref() const;
    StrBlobPtr& incr(); // 前缀递增
    StrBlobPtr& operator++();
    StrBlobPtr& operator++(int);


private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;

    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr; // 指针
};


StrBlobPtr& StrBlobPtr::operator++()
{
    check(curr, "increment past end of StrBlobPtr.");
    ++curr;
    return *this;
}


StrBlobPtr& StrBlobPtr::operator++(int)
{
    auto it = this;
    ++*this;
    return *it;
}

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

bool eq(const StrBlobPtr& s1, const StrBlobPtr& s2)
{
    auto s1_ptr = s1.wptr.lock(), s2_ptr = s2.wptr.lock();
    if(s1_ptr == s2_ptr){
        return (!s2_ptr || s1.curr == s2.curr);
    }
    else
    {
        return false;
    }
    
}

// 检查vector是否存在
std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
    auto ret = wptr.lock(); // 使用weak ptr要先lock再用
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret; // 如果合法，则获得share_ptr
}

std::string &StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr]; // 解引用指针，获得vector对应的位置的元素
}


StrBlobPtr& StrBlobPtr::incr(){
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

bool neq(const StrBlobPtr& s1, const StrBlobPtr& s2){
    return !eq(s1, s2);
}


int main()
{
    StrBlob bb = {"good", "good", "study", "day", "day", "up"};
    StrBlobPtr b_ptr(bb);
    b_ptr++;
    b_ptr++;
    cout << b_ptr.deref() << "\n";
    return 0;
}


