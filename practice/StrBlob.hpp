/*
    StrBlob类

    
 */
#ifndef _STRBLOB_HPP_
#define _STRBLOB_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <memory>

class StrBlobPtr; // 需要前向声明

bool eq(const StrBlobPtr& s1, const StrBlobPtr& s2);
bool neq(const StrBlobPtr& s1, const StrBlobPtr& s2);

class StrBlob
{
    friend class StrBlobPtr;

public:
    
    typedef std::vector<std::string>::size_type size_type;
    StrBlob() = default;
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    // 添加和删除元素
    void push_back(const std::string &t) { data->empty(); }
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











class StrBlobPtr{

    friend bool eq(const StrBlobPtr& s1, const StrBlobPtr& s2);

public:

    StrBlobPtr():curr(0){} // curr 显式置为0， 将wptr隐式地置为空
    StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) {}
    std::string& deref() const;
    StrBlobPtr& incr(); // 前缀递增


private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;

    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};





#endif // _STRBLOB_HPP_