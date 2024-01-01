/*
移动语义

拷贝构造函数中为指针成员分配新的内存再进行内容拷贝的做法在C++编程中几乎被视为是不可违背的。
不过在一些时候，我们确实不需要这样的拷贝构造语义。
*/
#include<iostream>
using namespace std;

class HasPtrMem
{
public:
    HasPtrMem():d(new int(0))
    {
        cout<<"Construct: "<<++n_cstr<<endl;
    }

    HasPtrMem(const HasPtrMem &h):d(new int(*h.d))
    {
        cout<<"copy construct: "<<++n_cptr<<endl;
    }

    ~HasPtrMem()
    {
        cout<<"Destruct: "<<++n_dstr<<endl;
    }
    int *d;
    static int n_cstr; //construct count
    static int n_dstr; //destruct count
    static int n_cptr; //copy construct count
};

int HasPtrMem::n_cstr = 0;
int HasPtrMem::n_cptr = 0;
int HasPtrMem::n_dstr = 0;

HasPtrMem GetTemp()
{
    return HasPtrMem();
}

/*
int main()
{
    HasPtrMem a = GetTemp();
    return 0;
}
*/


/*
这里构造函数被调用了一次，这是在GetTemp 函数中HasPtrMem()表达式显式地调用了构造函数而打印出来的。
而拷贝构造函数则被调用了两次。
这两次一次是从GetTemp函数中HasPtrMem()生成的变量上拷贝构造出一个临时值，以用作GetTemp 的返回值，而另外一次则是由临时值构造出main中变量a调用的。
对应地，析构函数也就调用了3次。

编译器可能有优化
*/