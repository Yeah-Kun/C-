#include <iostream>
#include <vector>
#include <string>
#include <memory>



class String
{
    friend bool operator==(const String& s1, const String& s2);
    friend bool operator!=(const String& s1, const String& s2);

public:
    String() = default;
    String(const char *cp) : size(std::strlen(cp))
	          {   string_ptr = alloc.allocate(size);
                  std::uninitialized_copy(cp, cp + size, string_ptr); }
    ~String(){
        alloc.destroy(string_ptr);
        alloc.deallocate(string_ptr, size);
    }

    char& operator[](std::size_t n) // 小括号后为什么没有const 
    {
        if(n < size){
            return string_ptr[n];
        }
        else{
            return string_ptr[size-1];
        }
    }

    const char& operator[](std::size_t n) const
    {
        return (*this)[n];
    }

private:
    static std::allocator<char> alloc;
    char* string_ptr;
    size_t size;
};
std::allocator<char> String::alloc;

bool operator==(const String& s1, const String& s2)
{
    if(s1.size != s2.size){
        return false;
    }
    else{
        for(int i = 0; i < s1.size; i++){
            if(s1.string_ptr[i] != s2.string_ptr[i])
                return false;
        }
        return true;
    }
}

bool operator!=(const String& s1, const String& s2)
{
    return ! (s1 == s2);
}


int main()
{
    String s1("good job"), s2("bad job"), s3("good job");
    char c1 = s1[3];
    const char c2 = s2[1];
    std::cout << c1 << " " << c2;
    return 0;
}