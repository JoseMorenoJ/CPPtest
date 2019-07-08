/*  C++ Advanced 2
    
    Extend class A in such a way that dynamically allocated instances will be placed inside the memory occupied by g_classPool.
    Assume instances will be freed in order opposite of the order of creation.

    Write a comment documenting what needs to be added if we want to allocate arrays as well as individual objects.
    --> To allocate arrays we should as well overload the A::operator new[]()  and A::operator delete[]()

    Write a comment explaining what needs to be added to the program so that all dynamic allocation uses memory from g_classPool.
    --> To modify the allocation for all the dynammic allocation we have to overload all this operators but
    -->   outside the class A.

    José Moreno 06 July 2019
*/

#include <iostream>

char g_classPool[1024];
int g_classPoolFreeOffset = 0;

class A
{
public:
    A(): m_data(42) {}
    ~A() {}

    //overload of new operator for A:
    void* operator new (std::size_t size)
    {
        void* ret = &g_classPool[g_classPoolFreeOffset++ * size];
        std::cout << "A::new() >" << ret << "<" << std::endl;
        return ret;
    }
    //overload of delete operator for A:
    void operator delete (void* ptr)
    {
        std::cout << "A::delete() >" << ptr << "<" << std::endl;
        ptr = nullptr;
        g_classPoolFreeOffset--;
        return;
    }

    int getData() { return m_data; }
private:
    int m_data;
};

int main(int argc, char* argv[])
{
    A* obj = new A();
    int *pi = new int(5);

    std::cout << obj->getData() << std::endl;
    std::cout << *pi << std::endl;

    std::cout << "address of the pool:" << &g_classPool << std::endl;

    delete pi;
    delete obj;

	return 0;
}