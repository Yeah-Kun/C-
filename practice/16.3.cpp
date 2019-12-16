#include<iostream>
#include<string>
// #include<>

using namespace std;
class Sales_data{

// 友元声明
// Sales_data 的非成员接口函数
friend std::ostream &print(std::ostream&, const Sales_data&);
friend Sales_data add(const Sales_data&, const Sales_data&);
friend std::istream &read(std::istream&, Sales_data&);


// 新增构造函数
public:
	Sales_data() = default;
	Sales_data(const std::string &s): bookNo(s){}
	Sales_data(const std::string &s, unsigned n, double p);
	Sales_data(std::istream &is);

	std::string isbn() const {return bookNo;} // 隐式内联函数
	Sales_data& combine(const Sales_data&);

protected:
	double avg_price() const; // 每本单价
	std::string bookNo; // 书的ISBN
	unsigned units_sold = 0; // 销售量
	double revenue = 0.0; // 销售额
};

Sales_data::Sales_data(std::istream &is)
{
	read(is, *this);
}
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


template <typename T>
int compare(const T& v1, const T& v2)
{
    if(v1 < v2) return -1;
    if(v2 < v1) return 1;
    return 0;
}

int main()
{
    Sales_data b1("good"), b2("bad");

    int a = 10, c = 100;
    double ac = 10.0;
    std::cout << compare(a, c) << "\n";
    return 0;
}