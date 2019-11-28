#include <iostream>
#include <string>
#include <vector>

/**
 * Quote类
 * 作用：表示按原价销售的书籍
 */
class Quote{
public:
    Quote(const std::string& s):bookNo(s){};

    std::string isbn() const{
        return bookNo;
    };
    virtual double net_price(std::size_t n) const{
        return n*price;
    };

private:
    std::string bookNo; // 书籍的ISBN号码

protected:
    double price = 10.0; // 不打折的状态

};


double print_total(std::ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
        << " # sold: " << n << " total due: " << ret << std::endl;
    
    return ret;
}


int main()
{
    Quote q("good job");
    print_total(std::cout, q, 100);

    return 0;
}