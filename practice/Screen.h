#include <iostream>
#include <string>


class Screen{

public:
	Screen() = default;
	Screen(unsigned h, unsigned w): 
		height(h), width(w), contents(h*w, ' ') {}
	Screen(unsigned h, unsigned w, char c): 
		height(h), width(w), contents(h*w, c) {}

public:
	// 移动光标函数（移动指向字符串位置指针）
	Screen &move(unsigned x, unsigned y)
		{ cursor  = x*width + y;   return *this;}
	// 设置内容函数
	Screen &set(unsigned r, unsigned col, char ch)
		{ contents[r*width + col] = ch; return *this;}
	Screen &set(char c)
		{ contents[cursor] = c; return *this;}
	// 显示函数
	Screen &display(std::ostream &os) 
		{do_display(os); return *this;}

private:
	void do_display(std::ostream &os) const { os << contents;}
	unsigned cursor = 0 ; // 光标位置
	unsigned height = 0, width = 0; // 长，宽
	std::string contents; // 屏幕面积
};


