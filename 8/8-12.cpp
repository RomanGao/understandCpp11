/*
不过程序员还是应该小心使用[[noreturn]]，
也 尽量不要对可能会有返回值的函数使用 [[noreturn]]。

一个错误使 用[[noreturn]]的例子:
*/

#include <iostream>
using namespace std;   

[[noreturn]] void Func(int i) 
{
    if(i<0)
        throw "negative";
    else if(i>0)
        throw "postive";
};
int main()
{
  //  Func(0); // 不会执行到这里
    cout << "Hello, world!" << endl;
    return 0;
}


/*
Func调用后的打印语 句永远不会被执行，因为Func被声明为[[noreturn]]。

不过由于函数作者的疏忽，忘记了 i==0时的状况，因此在i==0时，Func运行结束时 还是会返回main的。
在我们的实验机上，编译运行 该例子会在运行时没有发生“段错误”。
当然，具体的 错误情况可能会根据编译器和运行时环境的不同而 有所不同。
不过总的来说，程序员必须审慎使用 [[noreturn]]。
*/

/*
另外一个通用属性[[carries_dependency]]则跟 并行情况下的编译器优化有关。
事实上， [[carries_dependency]]主要是为了解决弱内存模
型平台上使用memory_order_consume内存顺序 枚举问题。


memory_order_consume的主要作用是保证对当 前原子类型数据的读取操作先于所有之后关于该原 子变量的操作完成，
但它不影响其他原子操作的顺 序。
要保证这样的“先于发生”的关系，编译器往 往需要根据memory_model枚举值在原子操作间构 建一系列的依赖关系，
以减少在弱一致性模型的平 台上产生内存栅栏。
不过这样的关系则往往会由于 函数的存在而被破坏。
*/