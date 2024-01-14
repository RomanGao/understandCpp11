/*
静态类型和动态类型的主要区别在于对变量进行类 型检查的时间点。
对于所谓的静态类型，类型检查 主要发生在编译阶段；
而对于动态类型，类型检查 主要发生在运行阶段

形如Python等语言中变 量“拿来就用”的特性，则需要归功于一个技术， 即类型推导。


C++11中类型推导的实现的方式之一就是重
定义了auto关键字。另外一个现实是decltype，
*/

#include<iostream>
 using namespace std; 
 int main()
{ 
    auto name="world.\n"; 
    cout<<"hello,"<<name; 
    return 0; 
}


/*
事实上，auto关键字在早期的C/C++标准中有 着完全不同的含义。
声明时使用auto修饰的变量， 按照早期C/C++标准的解释，是具有自动存储期的 局部变量。
不过现实情况是该关键字几乎无人使 用，因为一般函数内没有声明为static的变量总是 具有自动存储期的局部变量。

因此在C++11中， 标准委员会决定赋予auto全新的含义，即auto不再 是一个存储类型指示符（storage-class- specifier，如static、extern、thread_local等都是 存储类型指示符），
而是作为一个新的类型指示符 （type-specifier，如int、float等都是类型指示 符）来指示编译器，
auto声明变量的类型必须由编译器在编译时期推导而得。
*/