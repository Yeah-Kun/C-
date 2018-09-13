// struct Person{
// 	std::string name; // 姓名
// 	std::string address; // 地址
	
// };

class Person
{
public:
	// 构造函数
	Person(const std::string &name, const std::string &address):strName(name), strAddress(address){}
	Person(const std::string &name):strName(name){}
	Person(const std::string &name, const std::string &address, const double high, const double wigh):
		strName(name), strAddress(address)
		{height = high; weight = wigh;}
	Person(std::istream &is) {is >> *this;}
private:
	std::string strName;
	std::string strAddress;
	double height;
	double weight;
public:
	std::string getName() const {return strName;}
	std::string getAddress() const {return strAddress;}
};

