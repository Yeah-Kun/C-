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
    std::cout << "compare s1 and s2: " << (s1 != s2) << "\n"
         << "compare s1 and s3: " << (s1 == s3) << "\n";
    return 0;
}