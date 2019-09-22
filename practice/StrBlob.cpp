#include "StrBlob.hpp"
using namespace std;

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
    auto ret = wptr.lock();
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