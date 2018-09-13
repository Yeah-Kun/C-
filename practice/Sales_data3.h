#include<iostream>

using namespace std;
class Sales_data{

// 友元声明
friend Sales_data add(const Sales_data&, const Sales_data&);
friend std::istream &read(std::istream&, Sales_data&);
friend std::ostream &print(std::ostream&, const Sales_data&);

// 新增构造函数
public:
	Sales_data() = default;
	Sales_data(const std::string &s): bookNo(s){}
	//Sales_data(const std::string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n){}
	Sales_data(const std::string &s, unsigned n, double p);
	Sales_data(std::istream &is){is >> *this;}

	std::string isbn() const {return bookNo;} // 隐式内联函数
	Sales_data& combine(const Sales_data&);

private:
	double avg_price() const; // 每本单价
	std::string bookNo; // 书的ISBN
	unsigned units_sold = 0; // 销售量
	double revenue = 0.0; // 销售额
};
// Sales_data 的非成员接口函数
Sales_data add(const Sales_data&, const Sales_data&); 
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

// Sales_data::Sales_data(std::istream &is)
// {
// 	read(is, *this);
// 	//is >> *this;
// }
Sales_data::Sales_data(const std::string &s, unsigned n, double p)
{
	bookNo = s;
	units_sold = n;
	revenue = p*n;
}

// 在类的外部定义内联函数
inline double Sales_data::avg_price() const
{
	// mutable double avg;
	// avg = revenue / units_sold;
	// return avg;
	if(units_sold)
		return revenue / units_sold;
	else
		return 0;
}

// 定义read函数
istream& read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >>price;
    item.revence = price * item.units_sold;
    return is;
}

// 定义print函数
ostream &print(ostream &os, Sales_data &item)
{
    double price = 0;
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}
