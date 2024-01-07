/*
POD包含的另外一个概念是标准布局。标准布 局的类或结构体应该符合以下定义：
1）所有非静态成员有相同的访问权限 （public,private,protected）。
2）在类或者结构体继承时，满足以下两种情况 之一：
    ❑派生类中有非静态成员，且只有一个仅包含 静态成员的基类。 
    ❑基类有非静态成员，而派生类没有非静态成 员。

    struct B1{static int a;}; 
    struct D1:B1{int d;}; 
    struct B2{int a;}; 
    struct D2:B2{static int d;}; 
    struct D3:B2,B1{static int d;}; 
    struct D4:B2{int d;}; 
    struct D5:B2,D1{};
    D1、D2和D3都是标准布局的，而D4和D5则 不属于标准布局的。
    //这实际上使得非静态成员只要 同时出现在派生类和基类间，其即不属于标准布局的。（d4）
    //而多重继承也会导致类型布局的一些变化，所 以一旦非静态成员出现在多个基类中，派生类也不 属于标准布局的(d5)
3）类中第一个非静态成员的类型与其基类不同
*/

#include <iostream>
using namespace std;
struct B1{}; 
struct B2{};

struct D1:B1
{
    B1 b;//第一个非静态变量跟基类相同 
    int i; 
};
struct D2:B1
{ 
    B2 b; 
    int i; 
};
int main()
{
    D1 d1;
    D2 d2;
    cout<<hex;
    cout<<reinterpret_cast<long long>(&d1)<<endl;
    cout<<reinterpret_cast<long long>(&d1.b)<<endl;
    cout<<reinterpret_cast<long long>(&d1.i)<<endl;
    cout<<reinterpret_cast<long long>(&d2)<<endl;
    cout<<reinterpret_cast<long long>(&d2.b)<<endl;
    cout<<reinterpret_cast<long long>(&d2.i)<<endl;
    return 0;
}
//D1和D2唯一的区别是第一个 非静态成员的类型。
//在D1中，第一个非静态成员的 类型是B1，这跟它的基类相同；
//而D2中，第一个非静态成员的类型则是B2。
//直观地看，D1和D2应 该是“布局相同”的，程序员应该可以使用 memcpy这样的函数在这两种类型间进行拷贝，但 实际上却并不是这样
//在C++标准中，如果基类没有成员， 标准允许派生类的第一个成员与基类共享地址。
//因为派生类的地址总是“堆叠”在基类之上的，所以 这样的地址共享，表明了基类并没有占据任何的实 际空间（可以节省一点数据）。
//但是如果基类的第 一个成员仍然是基类，在我们的例子中可以看到， 编译器仍然会为基类分配1字节的空间。
//分配为1字 节空间是由于C++标准要求类型相同的对象必须地 址不同（基类地址及派生类中成员d的地址必须不 同），
//而导致的结果是，对于D1和D2两种类型而 言，其“布局”也就是不同的了
//所以在标准布局的解释中，C++11标准强制要 求派生类的第一个非静态成员的类型必须不同于基 类


/*
4）没有虚函数和虚基类。
5）所有非静态数据成员均符合标准布局类型， 其基类也符合标准布局。
以上5点构成了标准布局的含义，最为重要的应 该是前两条。
*/
