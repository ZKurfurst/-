#pragma once
#include<iostream>
class A
{
public:
    A(){
        std::cout<<"A construct"<<std::endl;
    }
    ~A(){
        std::cout<<"A destruct"<<std::endl;
    }
    void * operator new(size_t n){
        std::cout<<"A new"<<std::endl;
        return ::malloc(n);
    }

    void operator delete(void *n){
        std::cout<<"A delete"<<std::endl;
        ::free(n);
    }
};