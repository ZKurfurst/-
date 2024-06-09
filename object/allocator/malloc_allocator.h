//最普通的策略，用于测试
#pragma once
#include "object/allocator.h"
namespace yazi
{
    namespace object
    {
        template <typename T>
        class MallocAllocator : public Allocator<T>
        {
        public:
            MallocAllocator() = default;
            ~MallocAllocator() = default;

            virtual T *allocate()
            {
                auto p = ::malloc(sizeof(T));
                return reinterpret_cast<T *>(p);//将p转换为T*
            }

            virtual void deallocate(T *p)
            {
                ::free(p);
            }
        };
    }
}