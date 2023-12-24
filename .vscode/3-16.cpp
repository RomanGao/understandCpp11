/*
对C++程序员来说，编写C++程序有一条必须注意的规则，就是在类中包含了一个指针成员的话，那么就要特别小心拷贝构造函数的编写，
因为一不小心，就会出现内存泄露
*/
#include<iostream>
using namespace std;

class HasPtrMem
{
public:
    HasPtrMem():d(new int(0)){}

    //这里的拷贝构造函数由编译器隐式生成，其作用是执行类似于memcpy的按位拷贝
    HasPtrMem(const HasPtrMem &h):d(new int(*h.d)){}

    ~HasPtrMem(){ delete d;}
int *d;
};

/*
int main()
{
    HasPtrMem a;
    HasPtrMem b(a);
    cout<<*a.d <<endl;
    cout<<*b.d<<endl;
    return 0;
}
*/
/*
。这样的构造方式有一个问题，就是a.d和b.d都指向了同一块堆内存。
因此在main作用域结束的时候，a 和b的析构函数纷纷被调用，当其中之一完成析构之后（比如b），那么a.d就成了一个“悬挂指
针”（danglingpointer），因为其不再指向有效的内存了。那么在该悬挂指针上释放内存就会造成严重的错误。

这个问题在C++编程中非常经典。这样的拷贝构造方式，在C++中也常被称为“浅拷
贝”（shollowcopy）。而在未声明构造函数的情况下，C++也会为类生成一个浅拷贝的构造函数

解决的最佳方法是深拷贝 deep copy
*/
