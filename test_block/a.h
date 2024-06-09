#pragma once
#include <iostream>
#include "object/object_pool.h"
#include "object/allocator/block_allocator.h"
using namespace yazi::object;
const int chunk_per_block=4;
class A
{
private:
    typedef ObjectPool<A, BlockAllocator<A,chunk_per_block>> Pool;
    static Pool pool;
    int m_a;
    int m_b;
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