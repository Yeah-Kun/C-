#include <iostream>
#include<string>

using namespace std;
class Sales_data
{

    // 友元声明
    // Sales_data 的非成员接口函数
    friend std::ostream &print(std::ostream &, const Sales_data &);
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);
    friend Sales_data operator+(const Sales_data &, const Sales_data &);
    friend std::istream& operator>>(std::istream&, Sales_data &);
    friend std::ostream& operator<<(std::ostream&, const Sales_data &);

    // 新增构造函数
public:
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p);
    Sales_data(std::istream &is);

    std::string isbn() const { return bookNo; } // 隐式内联函数
    Sales_data &combine(const Sales_data &);
    Sales_data& operator+=(Sales_data &d){
        if(this->bookNo == d.bookNo){
            bookNo += d.bookNo;  
            units_sold += d.units_sold; 
            revenue += d.revenue;  
        }
        return *this;
    }

private:
    double avg_price() const; // 每本单价
    std::string bookNo;       // 书的ISBN
    unsigned units_sold = 0;  // 销售量
    double revenue = 0.0;     // 销售额
};

Sales_data::Sales_data(std::istream &is)
{
    read(is, *this);
}


Sales_data::Sales_data(const std::string &s, unsigned n, double p)
{
    bookNo = s;
    units_sold = n;
    revenue = p * n;
}


// 在类的外部定义内联函数
inline double Sales_data::avg_price() const
{
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}


// 定义read函数
std::istream &read(std::istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}


// 定义print函数
std::ostream &print(std::ostream &os, const Sales_data &item)
{
    double price = 0;
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}


Sales_data operator+(const Sales_data &d1, const Sales_data &d2)
{
    Sales_data d;
    if (d1.bookNo == d2.bookNo)
    {
        d.bookNo = d1.bookNo;                         // 书的ISBN
        d.units_sold = d1.units_sold + d2.units_sold; // 销售量
        d.revenue = d1.revenue + d2.revenue;          // 销售额
    }

    return d;
}

Sales_data add(const Sales_data &d1, const Sales_data &d2)
{
    return d1 + d2;
}

std::ostream& operator<<(std::ostream& os, const Sales_data &d)
{
    os << d.isbn() << " " << d.units_sold << " " << d.revenue << " " << d.avg_price();
    return os;
}

std::istream& operator>>(std::istream& is, Sales_data &d)
{
    double price;
    is >> d.bookNo >> d.units_sold >> price;
    if(is)
        d.revenue = d.units_sold * price;
    else
        d = Sales_data();
    return is;
}

int main()
{
    Sales_data a("good", 3, 1), b("good", 3, 1), c("good", 3, 1);
    Sales_data d = a + b;
    cout << d.isbn();
    return 0;
}

