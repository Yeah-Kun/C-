#include <iostream>
#include <vector>
#include <string>
#include <memory>



class String
{
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


int main()
{
    String s("good job");
    return 0;
}