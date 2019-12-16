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
    Quote(const std::string& s):bookNo(s){};

    std::string isbn() const{
        return bookNo;
    };
    virtual double net_price(std::size_t n) const{
        return n*price;
    };

    virtual void debug(std::ostream &os) const{
        os << "bookNo:" << bookNo <<
              " price:" << price << std::endl;
    };

private:
    std::string bookNo; // 书籍的ISBN号码

protected:
    double price = 10.0; // 不打折的状态

};


/**
 * Bulk_Quote类
 * 作用：打折销售的书籍
 */
class Bulk_quote: public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string& filename, double p, std::size_t min_q, double d)
        : Quote(filename), min_qty(min_q) {
            price = p;
            discount = d;
        }
    
    double net_price(std::size_t n) const override{
        if(n >= min_qty)
        {
            return n * price * discount;
        }
        else
        {
            return n*price;
        }
    }

    virtual void debug(std::ostream &os) const override{
        this->Quote::debug(os);
        os << "min_qty:" << min_qty <<
              " discount:" << discount;
    };

private:
    std::size_t min_qty = 0; // 最低购买数量
    double discount = 0.0; // 折扣

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
    Bulk_quote q("good job", 10, 10, 0.9);
    q.debug(std::cout);
    return 0;
}