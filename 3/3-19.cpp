/*
我们是否可以在临时对象构造a的时候不分配内
存，即不使用所谓的拷贝构造语义呢？

在C++11中，答案是肯定的


在C++11中，这样的“偷走”临时变量中资源的构造函数，就被称为“移动构造函数”。而这样的“偷”的行为，则称之为“移动语义”（move
semantics）。
*/

#include<iostream>
using namespace std;

class HasPtrMem
{
public:
    HasPtrMem():d(new int(3))
    {
        cout<<"Construct: "<<++n_cstr<<endl;
    }

    HasPtrMem(const HasPtrMem &h):d(new int(*h.d))
    {
        cout<<"copy construct: "<<++n_cptr<<endl;
    }

    HasPtrMem(HasPtrMem &&h):d(h.d) //移动构造韩式
    {
        h.d=nullptr;//将临时值的指针成员函数值为空
        cout<< "Move construct: "<<++n_mvtr<<endl;
    }

    ~HasPtrMem()
    {
        delete d;
        cout<<"Destruct: "<<++n_dstr<<endl;
    }
    int *d;
    static int n_cstr; //construct count
    static int n_dstr; //destruct count
    static int n_mvtr; //move construct 
    static int n_cptr; //copy construct count
};

int HasPtrMem::n_cstr = 0;
int HasPtrMem::n_cptr = 0;
int HasPtrMem::n_mvtr = 0;
int HasPtrMem::n_dstr = 0;

HasPtrMem GetTemp()
{
   HasPtrMem h;
   cout<<"Resource from "<< __func__<<":"<<hex<<h.d<<endl;
   return h;
}

int main()
{
    HasPtrMem a = GetTemp();
    cout<<"Resource from "<<__func__<<":"<<hex<<a.d<<endl;
    return 0;
}

/*
与拷贝构造函数不同的是，移动构造函数接受一个所谓的“右值引用”的参数，


可以看到，移动构造函数使用了参数h的成员d初始化了本对象的成员d
（而不是像拷贝构造函数一样需要分配内存，然后将内容依次拷贝到新分配的内存中），
而h的成员d随后被置为指针空值nullptr（请参见7.1节，这里等同于NULL）。
这就完成了移动构造的全过程。

这里所谓的“偷”堆内存，就是指将本对象d指向h.d所指的内存这一条语句，
相应地，我们还将h 的成员d置为指针空值。这其实也是我们“偷”内存时必须做的。
这是因为在移动构造完成之后，临时对象会立即被析构。如果不改变h.d（临时对象的指针成员）的话，则临时对象会析构掉本是我
们“偷”来的堆内存。这样一来，本对象中的d指针也就成了一个悬挂指针，如果我们对指针进行解引用，就会发生严重的运行时错误.



可以看到，这里没有调用拷贝构造函数，而是调用了两次移动构造函数，移动构造的结果是，
GetTemp中的h的指针成员h.d和main函数中的a的指针成员a.d的值是相同的，即h.d和a.d都指向了相
同的堆地址内存。该堆内存在函数返回的过程中，成功地逃避了被析构的“厄运”，取而代之地，成为了赋值表达式中的变量a的资源

那就是移动构造函数何时会被触发。之前我们只是提到了临时对象，
一旦我们用到的是个临时变量，那么移动构造语义就可以得到执行。
*/

