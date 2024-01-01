#include<iostream>
using namespace std;

class HasPtrMem
{
public:
    HasPtrMem():d(new int(0)){}

    //我们为HasPtrMem添加了一个拷贝构造函数
    HasPtrMem( HasPtrMem &h):d(new int(*h.d)){}

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
我们为HasPtrMem添加了一个拷贝构造函数。拷贝构造函数从堆中分配新内存，将该分配来的内存的指针交还给d，又使用*(h.d)对*d进行了初始化。
通过这样的方法，就避免了悬挂指针的困扰。
*/