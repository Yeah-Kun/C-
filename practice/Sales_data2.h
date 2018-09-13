
struct Sales_data{
	std::string isbn() const {return bookNo;} // 返回ISBN的函数，隐式内联函数
	Sales_data& combine(const Sales_data&);  // 
	double avg_price() const; // 每本单价
	std::string bookNo; // 书的ISBN
	unsigned units_sold = 0; // 销售量
	double revenue = 0.0; // 销售额
};
// Sales_data 的非成员接口函数
Sales_data add(const Sales_data&, const Sales_data&); 
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

