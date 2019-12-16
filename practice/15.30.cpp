#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<memory>


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



class Basket{
public:
    void add_item(const std::shared_ptr<Quote> & sale)
    {
        items.insert(sale);
    }

    double total_receipt(std::ostream& os)const;


private:
    static bool compare(const std::shared_ptr<Quote> &lhs, 
                        const std::shared_ptr<Quote> &rhs)
    {
        return lhs->isbn() < rhs->isbn();
    }

    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};
};

double print_total(std::ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
        << " # sold: " << n << " total due: " << ret << std::endl;
    
    return ret;
}

double Basket::total_receipt(std::ostream& os)const
{
    double sum = 0.0;
    for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
    {
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << "Total Sale: " << sum << std::endl;

    return sum;
}

