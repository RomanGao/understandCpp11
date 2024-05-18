/*
，C++11预定义的通用属性包括 [[noreturn]]和[[carries_dependency]]两种。

[[noreturn]]是用于标识不会返回的函数的。
这 里必须注意，不会返回和没有返回值的（void）函 数的区别。
没有返回值的void函数在调用完成后， 调用者会接着执行函数后的代码；
而不会返回的函 数在被调用完成后，后续代码不会再被执行

[[noreturn]]主要用于标识那些不会将控制流返 回给原调用函数的函数，典型的例子有：
有终止应 用程序语句的函数、有无限循环语句的函数、有异 常抛出的函数等。

*/

void DoSomething1(){};
void DoSomething2(){};
[[noreturn]] void ThrowAway()
{
    throw "expection"; // 控制流跳转到异常处理
}
void Func()
{
    DoSomething1();
    ThrowAway();
    DoSomething2(); // 该函数不可到达
}

int main()
{
    // Func();
}

/*
由于ThrowAway抛出了异 常，DoSomething2永远不会被执行。这个时候将
ThrowAway标记为noreturn的话，编译器会不再 为ThrowAway之后生成调用DoSomething2的代 码。
当然，编译器也可以选择为Func函数中的 DoSomething2做出一些警告以提示程序员这里有 不可到达的代码
*/

/*
不返回的函数除了是有异常抛出的函数外，还 有可能是有终止应用程序语句的函数，或是有无限 循环语句的函数等。
事实上，在C++11的标准库 中，我们都能看到形如：
 [[noreturn]]void abort(void)noexcept;

这样的函数声明。这里声明的是最常见的abort 函数。
abort总是会导致程序运行的停止，甚至连 自动变量的析构函数以及本该在atexit()时调用的函数全都不调用就直接退出了。
因此声明为 [[noreturn]]是有利于编译器优化的。
*/