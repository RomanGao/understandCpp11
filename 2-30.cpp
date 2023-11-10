/*
局部和匿名类型作模板实参

在C++98中，标准对模板实参的类型还有一些限制。
具体地讲，局部的类型和匿名的类型在 C++98中都不能做模板类的实参
*/

template<typename T>class X{}; 
template<typename T>void TempFun(T t){}; 
struct A{}a; 

struct{int i;}b;//b是匿名类型变量
typedef struct{int i;}B;//B是匿名类型 
void Fun() {
    struct C{}c;//C是局部类型 
    X<A>x1;//C++98通过，C++11通过
    X<B>x2;//C++98错误，C++11通过 
    X<C>x3;//C++98错误，C++11通过 
    TempFun(a);//C++98通过，C++11通过 
    TempFun(b);//C++98错误，C++11通过 
    TempFun(c);//C++98错误，C++11通过 
}

