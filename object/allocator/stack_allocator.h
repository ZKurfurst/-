#pragma once
#include "object/allocator.h"
#include <array>
//栈策略的思路：每次回收时将对象放在栈中，每次分配的时候先看栈中是否有可分配的内存，若有，直接用栈分配，否则用数组分配
namespace yazi
{
    namespace object
    {
        template <typename T, int N>
        class StackAllocator : public Allocator<T>
        {
        public:
            StackAllocator()
            {
                m_allocated = 0;
                m_available = 0;
            }
            ~StackAllocator() = default;
            virtual T *allocate()
            {
                if (m_available <= 0 && m_allocated >= N)
                    throw std::bad_alloc();
                if (m_available > 0)
                {
                    return m_stack[--m_available];
                }
                else//栈里面没有可用的对象分配
                {
                    auto p = m_data + sizeof(T) * m_allocated;
                    m_allocated++;
                    return reinterpret_cast<T *>(p);
                }
            }
            virtual void deallocate(T *p)
            {
                m_stack[m_available++] = p;
            }

        private:
            unsigned char m_data[sizeof(T) * N];
            std::array<T *, N> m_stack;
            int m_allocated; // 数组中下一个未使用的位置
            int m_available; // 栈顶下标
        };
    }
}