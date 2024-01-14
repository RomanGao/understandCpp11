/*
我们可以看看代码 清单3-53所示的这个来自于C++11标准提案中的 例子。
*/

template<int I>
struct A{};

char xxx(int);
char xxx(double);

template<class T>
A<sizeof(xxx((T)0))> f(T){};
int main()
{
    f(0);
}

/*
我们在定义函数模板f的时 候，其返回值则定义为一个以sizeof(xxx((T)0))为参 数的类模板A

这里值得注意的是，我们使用了sizeof表达式，以及强制的类型转换。

*/