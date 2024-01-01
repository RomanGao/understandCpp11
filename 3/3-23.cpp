/*
移动语义一定是要修改 临时变量的值,否则，左引用就够了

此程序员在实现移动语义一 定要注意排除不必要的const关键字

，拷贝/移动构造函数实际上有以 下3个版本：
T Object(T＆) 
T Object(const T＆) 
T Object(T＆＆)
其常量左值引用的版本是一个拷贝构造版本，而右值引用版本是一个移动构造版本。

默认情况下，编译器会为程序员隐式地生成一个（隐式表 示如果不被使用则不生成）移动构造函数。

默认 的移动构造函数实际上跟默认的拷贝构造函数一 样，只能做一些按位拷贝的工作。
这对实现移动语义来说是不够的。通常情况下，如果需要移动语 义，程序员必须自定义移动构造函数。

对一 些简单的、不包含任何资源的类型来说，实现移动 语义与否都无关紧要，因为对这样的类型而言，移 动就是拷贝，拷贝就是移动。

声明了移动构造函数、移动赋值函 数、拷贝赋值函数和析构函数中的一个或者多个， 编译器也不会再为程序员生成默认的拷贝构造函 数

所以在C++11中，拷贝构造/赋值和移动构造/ 赋值函数必须同时提供，或者同时不提供，程序员 才能保证类同时具有拷贝和移动语义。
只声明其中 一种的话，类都仅能实现一种语义。


只实现一种语义在类的编写中也是非常
常见的。比如说只有拷贝语义的类型——事实上在 C++11之前我们见过大多数的类型的构造都是只 使用拷贝语义的。
而只有移动语义的类型则非常有 趣，因为只有移动语义表明该类型的变量所拥有的 资源只能被移动，而不能被拷贝。
那么这样的资源 必须是唯一的。

在标准库的头文件＜type_traits＞里，我们还 可以通过一些辅助的模板类来判断一个类型是否是可以移动的。
比如is_move_constructible、 is_trivially_move_constructible、 is_nothrow_move_constructible，使用方法仍然 是使用其成员value。
比如：cout＜＜is_move_constructible＜UnknownType ＞::value;
就可以打印出UnknowType是否可以移动，这 在一些情况下还是非常有用的。


而有了移动语义，还有一个比较典型的应用是 可以实现高性能的置换（swap）函数。
template＜class T＞ 
void swap(T＆a,T＆b) 
{
    T tmp(move(a));
    a=move(b); 
    b=move(tmp); 
}
如果T是可以移动的，那么移动构造和移动赋值 将会被用于这个置换。
a先将自己的资源 交给tmp，随后b再将资源交给a，tmp随后又将从 a中得到的资源交给b，从而完成了一个置换动作。

整个过程，代码都只会按照移动语义进行指针交 换，不会有资源的释放与申请。
而如果T不可移动 却是可拷贝的，那么拷贝语义会被用来进行置换。 这就跟普通的置换语句是相同的了。



另外一个关于移动构造的话题是异常。
对于移 动构造函数来说，抛出异常有时是件危险的事情。 因为可能移动语义还没完成，一个异常却抛出来 了，这就会导致一些指针就成为悬挂指针。

因此程 序员应该尽量编写不抛出异常的移动构造函数，通 过为其添加一个noexcept关键字，
可以保证移动构 造函数中抛出来的异常会直接调用terminate程序 终止运行，而不是造成指针悬挂的状态。

我们还可以用一个std::move_if_noexcept的 模板函数替代move函数。
该函数在类的移动构造 函数没有noexcept关键字修饰时返回一个左值引用 从而使变量可以使用拷贝语义，
而在类的移动构造 函数有noexcept关键字时，返回一个右值引用，从而使变量可以使用移动语义。
*/

#include <iostream>
#include <utility>
using namespace std;

struct Maythrow
{
    Maythrow(){}
    Maythrow(const Maythrow&)
    {
        cout<<"Maythrow copy constructor"<<endl;
    }
    Maythrow(Maythrow&&){
        cout<<"Maythrow move constructor"<<endl;
    }
};

struct Nothrow
{
    Nothrow(){}
    Nothrow(const Nothrow&)
    {
        cout<<"Nothrow copy constructor"<<endl;
    }
    Nothrow(Nothrow&&) noexcept
    {
        cout<<"Nothrow move constructor"<<endl;
    }
};

int main() 
{
    Maythrow m;
    Nothrow n;
    Maythrow mt = move_if_noexcept(m);
    Nothrow nt = move_if_noexcept(n);
    return 0;
}

//move_if_noexcept是以牺牲性能保证安全的一种 做法，
//而且要求类的开发者对移动构造函数使用 noexcept进行描述，否则就会损失更多的性能

//RVO/NRVO的优化 （RVO,Return Value Optimization，返回值优化，或者NRVO，Named Return Value optimization)
//RVO/NRVO是C++14中引入的一个优化技术，它允许编译器在函数返回时，将临时对象的内容直接拷贝到调用者的变量中。
//，一旦打开g++/clang++的RVO/NRVO，从 ReturnValue函数中a变量拷贝/移动构造临时变 量，以及从临时变量拷贝/移动构造b的二重奏就通 通没有了。

