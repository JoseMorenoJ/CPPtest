/*  C++ Advanced 2
    
    Extend class A in such a way that dynamically allocated instances will be placed inside the memory occupied by g_classPool.
    Assume instances will be freed in order opposite of the order of creation.

    Write a comment documenting what needs to be added if we want to allocate arrays as well as individual objects.
        Overload also the new[] and delete[] operators in the class A.

    Write a comment explaining what needs to be added to the program so that all dynamic allocation uses memory from g_classPool.
        Overload the new, new[], delete and delete[] operators outside the class A.
            -- http://www.modernescpp.com/index.php/overloading-operator-new-and-delete
    
*/

#include <iostream>

char g_classPool[1024];
int g_classPoolFreeOffset = 0;

class A
{
public:
    A(): m_data(42) {}
    ~A() {}

    void* operator new (std::size_t size){
        return &g_classPool[g_classPoolFreeOffset++ * size];
    }

    void operator delete (void* ptr){
        ptr = nullptr;
        g_classPoolFreeOffset--;
    }

    int getData() { return m_data; }
private:
    int m_data;
};

int main(int argc, char* argv[])
{
    A* obj = new A();

    std::cout << g_classPool << std::endl;
    std::cout << obj << std::endl;
    
    int *pi = new int(5);

    std::cout << obj << std::endl;
    std::cout << *pi << std::endl;

    delete obj;

    obj = new A();
    std::cout << obj << std::endl;
    delete pi;
    delete obj;

	return 0;
}