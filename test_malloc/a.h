#pragma once
#include <iostream>
#include "object/object_pool.h"
#include "object/allocator/malloc_allocator.h"
using namespace yazi::object;
class A
{
private:
    typedef ObjectPool<A, MallocAllocator<A>> Pool;
    static Pool pool;
public:
    A()
    {
        std::cout << "A construct from object pool" << std::endl;
    }
    ~A()
    {
        std::cout << "A destruct from object pool" << std::endl;
    }
    void *operator new(size_t n)
    {
        std::cout << "A new" << std::endl;
        return pool.allocate(n);
    }

    void operator delete(void *n)
    {
        std::cout << "A delete" << std::endl;
        pool.deallocate(n);
    }
};
A::Pool A::pool;//初始化pool