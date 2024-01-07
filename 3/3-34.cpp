/*
POD是英文中Plain Old Data的缩写。
POD在 C++中是非常重要的一个概念，通常用于说明一个 类型的属性，尤其是用户自定义类型的属性.

Plain，表示了POD是个普通的 类型，在C++中常见的类型都有这样的属性，而不像一些存在着虚函数虚继承的类型那么特别。
Old则体现了其与C的兼容性，比如可以用最老的memcpy()函数进行复制，使用memset()进行初始 化等.


C++11将POD划分为两个基本概念的合集，即： 平凡的（trivial）和标准布局的（standard layout）。

一 个平凡的类或结构体应该符合以下定义：
(1)拥有平凡的默认构造函数（trivial constructor）和析构函数（trivial destructor）。
通常情况下，不定义类的构造函数，编译 器就会为我们生成一个平凡的默认构造函数。
而一 旦定义了构造函数，即使构造函数不包含参数，函数体里也没有任何的代码，那么该构造函数也不再 是“平凡”的。
在NoTrivial的定义中，构造函数就不是平凡 的.
但这样的类型声 明并非“无可救药”地“非平凡化”（non- trivial）了，使用 =default关键字来显式地声明缺省版本的构造函 数，从而使得类型恢复“平凡化”。
(2)拥有平凡的拷贝构造函数（trivial copy constructor）和移动构造函数（trivial move constructor）。
平凡的拷贝构造函数基本上等同 于使用memcpy进行类型的构造。同平凡的默认构造函数一样，不声明拷贝构造函数的话，
编译器会 帮程序员自动地生成。同样地，可以显式地使用 =default声明默认拷贝构造函数。
(3)拥有平凡的拷贝赋值运算符（trivial assignment operator）和移动赋值运算符 （trivialmove operator）。
这基本上与平凡的拷 贝构造函数和平凡的移动构造运算符类似。
(4)不能包含虚函数以及虚基类。

可以通过一些辅助的类模板来帮我们进行以上属 性的判断
template＜typename T＞struct std::is_trivial;
*/


//类模板is_trivial的成员value可以用于判断T的类 型是否是一个平凡的类型。除了类和结构体外，
// is_trivial还可以对内置的标量类型数据（比如int、 float都属于平凡类型）及数组类型（元素是平凡类 型的数组总是平凡的）进行判断。
#include <iostream>
#include <type_traits>
using namespace std;

struct Trivial1{};
struct Trivial2
{
public:
    int a;
private:
    int b;
};
struct Trivial3
{
    Trivial1 a;
    Trivial2 b;
};
struct Trivial4
{
    Trivial2 a[23];
};

struct Trivial5
{
    int x;
    static int y;
};

struct NoneTrivial1
{
    NoneTrivial1():z(42){}
    int z;
};
struct NoneTrivial2
{
    NoneTrivial2();
    int w;
};
NoneTrivial2::NoneTrivial2()=default;

struct NoneTrivial3
{
    Trivial5 c;
    virtual void f();
};

int main()
{

    cout<<is_trivial<Trivial1>::value<<endl;
    cout<<is_trivial<Trivial2>::value<<endl;
    cout<<is_trivial<Trivial3>::value<<endl;
    cout<<is_trivial<Trivial4>::value<<endl;
    cout<<is_trivial<Trivial5>::value<<endl;
    cout<<is_trivial<NoneTrivial1>::value<<endl;
    cout<<is_trivial<NoneTrivial2>::value<<endl;
    cout<<is_trivial<NoneTrivial3>::value<<endl;

    return 0;
}

