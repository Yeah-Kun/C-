#include <iostream>
#include <string>
#include <vector>
#include <memory>

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
        return 0;
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
    // std::shared_ptr<Bulk_quote> q1 = std::make_shared<Bulk_quote>("good job", 10, 10, 0.9);
    // std::shared_ptr<Bulk_quote> q2 = std::make_shared<Bulk_quote>("bad job", 10, 10, 0.9);
    // std::shared_ptr<Bulk_quote> q3 = std::make_shared<Bulk_quote>("no job", 10, 10, 0.9);
    // std::shared_ptr<Bulk_quote> q4 = std::make_shared<Bulk_quote>("have job", 10, 10, 0.9);
    // std::shared_ptr<Bulk_quote> q5 = std::make_shared<Bulk_quote>("do job", 10, 10, 0.9);

    std::shared_ptr<Quote> q1 = std::make_shared<Quote>("good job", 10); // 15.29
    std::shared_ptr<Quote> q2 = std::make_shared<Quote>("bad job", 10);
    std::shared_ptr<Quote> q3 = std::make_shared<Quote>("no job", 10);
    std::shared_ptr<Quote> q4 = std::make_shared<Quote>("have job", 10);
    std::shared_ptr<Quote> q5 = std::make_shared<Quote>("do job", 10);


    std::vector<std::shared_ptr<Quote>> backet = {q1, q2, q3, q4, q5};
    double total_net_price = 0;
    for(const auto q : backet){
        total_net_price += q->net_price(10);
    }

    std::cout << "total net price:" << total_net_price << "\n";
    return 0;
}


