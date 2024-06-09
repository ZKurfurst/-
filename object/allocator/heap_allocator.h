// 堆策略
#pragma once
#include"object/allocator.h"
#include <algorithm>
namespace yazi
{
    namespace object
    {
        template <typename T, int N>
        class HeapAllocator : public Allocator<T>
        {
        public:
            enum State
            {
                FREE = 1,
                USED = 0
            };
            struct Entry
            {
                State state; // 状态
                T *p;        // 对象指针
                bool operator<(const Entry &other) const
                {
                    return state < other.state;
                }
            };
            HeapAllocator()
            {
                m_available = N;
                for (int i = 0; i < N; i++)
                {
                    m_entry[i].state = FREE;
                    m_entry[i].p = reinterpret_cast<T *>(&m_data[sizeof(T) * i]);
                }
                // 调用生成大堆算法
                std::make_heap(m_entry, m_entry + N);
            }
            ~HeapAllocator() = default;
            virtual T *allocate()
            {
                if (m_available <= 0)
                    throw std::bad_alloc();
                Entry e = m_entry[0];
                std::pop_heap(m_entry, m_entry + N);
                m_available--;
                m_entry[m_available].state = USED;
                m_entry[m_available].p = nullptr;
                return e.p;
            }
            virtual void deallocate(T *p)
            {
                if (p == nullptr || m_available >= N)
                    return;
                m_entry[m_available].state = FREE;
                m_entry[m_available].p = reinterpret_cast<T *>(p);
                m_available++;
                std::push_heap(m_entry, m_entry + N);
            }
        private:
            unsigned char m_data[sizeof(T) *N];
            Entry m_entry[N]; // 堆数组
            int m_available;  // 数组中未使用的元素个数
        };
    }
}