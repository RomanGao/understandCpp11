/*
C++11在新标准 中为了支持对齐，
主要引入两个关键字：
操作符 alignof、
对齐描述符（alignment-specifier） alignas
*/

/*
操作符alignof的操作数表示一个定义完整的自 定义类型或者内置类型或者变量，返回的值是一个 std::size_t类型的整型常量。
如同sizeof操作符一 样，alignof获得的也是一个与平台相关的值。
*/

#include<iostream>
using namespace std;

class InComplete;
struct Completed{};

int main()
{
    int a;
    long long b;
    auto &c = b;
    //对内置类型和完整类型使用alignof
    cout<<alignof(int)<<endl;
    cout<<alignof(long long)<<endl;
    cout<<alignof(Completed)<<endl;  //1

    ////对变量、引用或者数组使用alignof
    cout<<alignof(a)<<endl;
    cout<<alignof(b)<<endl;
    cout<<alignof(c)<<endl;
    //本句无法通过编译，Incomplete类型不完整
    //cout<<alignof(InComplete)<<endl;
    return 0;
}

/*
类型定义不完整的 class InComplete是无法通过编译的。
其他的规则 则基本跟大多数人想象的相同：
引用c与其引用的数据b对齐值相同，数组的对齐值由其元素决定。
*/

/*
我们再来看看对齐描述符alignas。事实上， alignas既可以接受常量表达式，也可以接受类型作 为参数;
alignas(double)char c;
也是合法的描述符。其使用效果跟
alignas(alignof(double))char c;
是一样的。
*/

/*

我们在使用常量表达式作为alignas的操作符的 时候，其结果必须是以2的自然数幂次作为对齐 值。
对齐值越大，我们称其对齐要求越高；而对齐 值越小，其对齐要求也越低。
由于2的幂次的关 系，能够满足严格对齐要求的对齐方式也总是能够 满足要求低的对齐值的。
*/

/*
在C++11标准中规定了一个“基本对齐 值”（fundamental alignment）。
一般情况下其 值通常等于平台上支持的最大标量类型数据的对齐 值（常常是long double）。
我们可以通过 alignof(std::max_align_t)来查询其值。

不过即使使用了扩展对齐，也并非 意味着程序员可以随心所欲。
对于每个平台，系统 能够支持的对齐值总是有限的，
程序中如果声明了 超过平台要求的对齐值，则按照C++标准该程序是 不规范的（ill-formed），这可能会导致未知的编 译时或者运行时错误。
因此程序员应该定义合理的 对齐值，否则可能会遇到一些麻烦。
*/

