/*
不建议使用

在代码实践时，读者可能还会被一些C++的语言特性迷惑，
比较典型的是所谓“参数关联名称查找”（Argument Dependent Lookup，简称ADL）.
这个特性允许编译器在名字空间内找不到函数名称的时候，在参数的名字空间内查找函数名字。
*/

namespace ns_adl
{
    struct A{};
    void ADLFunc(A a){}//ADLFunc定义在namespace ns_adl中
}

int main()
{
    ns_adl::A a; //a定义在namespace ns_adl中
    ADLFunc(a);//ADLFunc无需声明名字空间，编译器在参数a的名字空间中查找ADLFunc
}


/*
ADL带来了一些使用上的便利性，不过也在一 定程度上破坏了namespace的封装性。
很多人认为 使用ADL会带来极大的负面影响[1]。
因此，比较好 的使用方式，
还是在使用任何名字前打开名字空 间，或者使用“::”列出变量、函数完整的名字空 间。
*/


