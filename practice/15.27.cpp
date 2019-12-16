#include <iostream>
#include <string>
#include <vector>

/**
 * Quote类
 * 作用：表示按原价销售的书籍
 */
class Quote{
public:
    Quote() = default;
    Quote(const std::string& s, double p):bookNo(s)
    {
        price = p;
    };
    Quote(const Quote& q)
    {
        this->bookNo = q.bookNo;
        this->price = q.price;
        std::cout << "create Quote object: " 
                  << "bookNo:" << bookNo
                  << " price:" << price
                  << "\n";
    }

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



class Disc_quote:public Quote
{

public:
    Disc_quote() = default;
    Disc_quote(const std::string& book, double price, std::size_t qty, double disc)
                : Quote(book, price), quantify(qty), discount(disc){}
    Disc_quote(const Disc_quote& q): Quote(q)
    {
        this->quantify = q.quantify;
        this->discount = q.discount;
        std::cout << "create Disc_quote object: " 
                  << "quantify:" << quantify
                  << " discount:" << discount
                  << "\n";
    }

    double net_price(std::size_t) const = 0;
protected:
    std::size_t quantify = 0; // 适用折扣的购买量
    double discount = 0.0; // 折扣

};


/**
 * Bulk_Quote类
 * 作用：打折销售的书籍
 */
class Bulk_quote: public Disc_quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string& filename, double p, std::size_t min_q, double d)
        : Disc_quote(filename, p, min_q, d) {}

    using Disc_quote::Disc_quote;

    double net_price(std::size_t n) const override{
        if(n >= quantify)
        {
            return n * price * discount;
        }
        else
        {
            return n*price;
        }
    }

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
    Bulk_quote bbq("good job", 10, 10, 0.9);
    Bulk_quote q(bbq);
    print_total(std::cout, q, 100);

    return 0;
}