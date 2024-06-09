//分配策略的模板类
#pragma once
#include<stdexcept>
namespace yazi
{
    namespace object
    {
        template <typename T>
        class Allocator
        {
        public:
            virtual T *allocate() = 0; //=0表示纯虚函数,分配内存
            virtual void deallocate(T *p) = 0;//释放内存
        };
    }
}