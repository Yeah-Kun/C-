#include <iostream>
#include <string>
#include <memory>
#include<algorithm> 
using namespace std;


template <typename T>
class Vec{
public:
    Vec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
	Vec(const Vec&);
    Vec(std::initializer_list<T> ls);
	Vec &operator=(const Vec&);
	~Vec(){ free(); }

    void push_back(const T&);

	// 已用空间
	size_t size() const {
		return first_free - elements;
	}

	// 总空间（容量）
	size_t capacity() const {
		return cap - elements;
	}

	// 这里模仿vector
	T *begin() const {
		return elements;
	}
	T *end() const {
		return first_free;
	}

    void reserve(const size_t& n) {
		// 申请一块cap + n的内存空间
		auto new_data_size = n + capacity();
		auto new_elements = alloc.allocate(n);
		auto new_first_free = new_elements;
		auto old_elements = elements;

		// 将原来的内容迁移到新的内存上
		for (size_t i = 0; i < size(); i++)
		{
			alloc.construct(new_first_free++, std::move(*old_elements++));
		}

		// 释放原来的内存
		free();

		// 更新类内成员
		elements = new_elements;
		first_free = new_first_free;
		cap = new_elements + new_data_size;

		std::cout << "reserve total size: " << new_data_size << "\n";
	}

    void resize(const size_t& n, const T& value = T());
private:
	static std::allocator<T> alloc;

	// 检查空间是否耗尽，如果耗尽则再申请
	void check_n_alloc()
	{
		if (size() == capacity())
			reallocate();
	}

	std::pair<T*, T*> allocate_n_copy(const T*, const T*);
	void free();
	void reallocate();
	T *elements; // 分配内存的首元素
	T *first_free; // 指向最后一个实际元素之后的位置
	T *cap; // 指向分配的内存末尾

};

template <typename T>
std::allocator<T> Vec<T>::alloc;

template <typename T>
Vec<T>::Vec(std::initializer_list<T> ls)
{
    // 获取size && 申请内存空间
    size_t data_size = ls.size();
    elements = alloc.allocate(data_size);
    first_free = elements;
    // 移动元素
    for(auto item : ls)
    {
        alloc.construct(first_free++, std::move(item));
    }

    // 修改成员变量
    cap = first_free;
}

template <typename T>
void Vec<T>::resize(const size_t& n, const T& value)
{
	unsigned total_size = size();
	// 需要填充值
	if (total_size < n)
	{
		// 申请空间
		auto new_data_size = n;
		auto first_element = alloc.allocate(new_data_size);
		auto new_first_free = first_element;
		auto old_elements = elements;

		// 填充默认值
		for (size_t i = 0; i < size(); i++)
			alloc.construct(new_first_free, std::move(*old_elements++));
		for (size_t i = size(); i < n; i++)
			alloc.construct(new_first_free++, value);
		free();

		// 更新成员
		elements = first_element;
		first_free = new_first_free;
		cap = elements + new_data_size;
	}
	// 需要裁减值
	else if (total_size > n)
	{
		// 重新分配内存空间
		auto new_data_size = n;
		auto first_element = alloc.allocate(new_data_size);
		auto new_first_free = first_element;
		// 移动元素
		for (size_t i = 0; i < n; i++)
			alloc.construct(new_first_free++, std::move(*elements++));
		free();
		// 更新成员
		elements = first_element;
		first_free = new_first_free;
		cap = elements + new_data_size;
	}
	// 等于不需要进行操作
	std::cout << "resize total size: " << capacity() << "\n";
}

template <typename T>
void Vec<T>::push_back(const T& s)
{
	check_n_alloc();
	alloc.construct(first_free++, s); // 构造string s
}

template <typename T>
std::pair<T*, T*> Vec<T>::allocate_n_copy(const T *b, const T *e)
{
	auto data = alloc.allocate(e - b);
	return { data, uninitialized_copy(b, e, data) };
}


template <typename T>
void Vec<T>::free()
{
	if (elements != nullptr) {
		for_each(elements, first_free, [](string& s){alloc.destroy(&s);});
		alloc.deallocate(elements, cap - elements); // 释放所有内存空间
	}
}

template <typename T>
Vec<T>::Vec(const Vec<T>&s)
{
	auto newdata = allocate_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

template <typename T>
Vec<T>& Vec<T>::operator=(const Vec<T>& rhs)
{
	auto data = allocate_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

template <typename T>
void Vec<T>::reallocate()
{
	// 申请内存空间
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto old_elements = elements;
	// 将原容器内容搬到新容器
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*old_elements++));
	// 释放原容器内容
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}



int main()
{
	Vec<std::string> v = {"good", "good", "study", "day", "day", "up"};
    std::cout << "v size: " << v.size() << "\n";
	return 0;
}