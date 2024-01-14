/*
在C++模板中，有一条著名的规则，即 SFINEA-Substitution failure is not an error，
中文直译即是“匹配失败不是错误”

这条规则表示的是对重载的模板的参数进行展 开的时候，如果展开导致了一些类型不匹配，编译 器并不会报错
*/

struct Test
{
    typedef int foo;
};
template<typename T>
void f(typename T::foo){} ////第一个模板定义-#1

template<typename T>
void f(T){}                ////第二个模板定义-#2


int main()
{
    f<Test>(0); //调用第一个模板定义-#1
    f<int>(10) ; //调用第二个模板定义-#2
    return 0;
}

/*
我们重载了函数模板f的定 义。
第一个模板f接受的参数类型为T::foo，这里我 们通过typename来使编译器知道T::foo是一个类 型。
而第二个模板定义则接受一个T类型的参数。


，对于f＜int＞来讲， 虽然不存在int::foo这样的类型，编译器依然不会报 错，
相反地，编译器会找到第二个模板定义并对其 进行实例化。
*/
