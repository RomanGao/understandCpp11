/*
虽然nullptr_t看起来像是个指针类型， 用起来更是，但在把nullptr_t应用于模板中时候， 
我们会发现模板却只能把它作为一个普通的类型来 进行推导（并不会将其视为T*指针）
*/
#include<iostream>
using namespace std;

template<typename T> void g(T* t){}
template<typename T> void h(T t){}

int main()
{
   // g(nullptr); //编译失败,nullptr的类型是nullptr_t,而 不是指针
    h(nullptr); // 正确：//推导出T=nullptr_t
    g((float*)nullptr); // 正确：nullptr 可以被显式转换为 float* 指针类型,推导出T=float
    h(0); // 正确：推导出T=int
    return 0;
}
/*
g(nullptr)并不会被编译 器“智能”地推导成某种基本类型的指针（或者 void*指针），
因此要让编译器成功推导出nullptr 的类型，必须做显式的类型转换。
*/