#include"test_array/a.h"
int main(){
    A *arr[max_size]={nullptr};
    for(int i=0;i<max_size;i++){
        A *a=new A();
        arr[i]=a;
    }
    for(int i=0;i<max_size;i++){
        delete arr[i];
    }
    return 0;
}