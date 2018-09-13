class X;
// class X{
// 	Y* y1;
// };

// class Y{
// 	X x1;
// }

// 标准答案
class Y{
	X* x1;
}

class X{
	Y y1;
};
