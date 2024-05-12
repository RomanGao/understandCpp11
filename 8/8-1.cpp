/*
数据对齐


*/

#include<iostream>
using namespace std;

struct HowManyBytes{ char a; int b; };
int main()
{

    cout<<"sizeof(char):"<<sizeof(char)<<endl;
    cout<<"sizeof(int):"<<sizeof(int)<<endl;
    cout<<"sizeof(HowManyBytes):"<< sizeof(HowManyBytes)<<endl; 
    cout<<endl;
    cout<<"offset of char a:"<< offsetof(HowManyBytes,a)<<endl;
    cout<<"offset of int b:"<< offsetof(HowManyBytes,b)<<endl;
    return 0;
}

/*
a和b两个数据
的长度分别为1字节和4字节，不过当我们使用 sizeof来计算HowManyBytes这个结构体所占用的 内存空间时，看到其值为8字节。
其中似乎多出来 了3字节没有使用的空间。

出现这个现象主要是由于数据对齐要求导致 的。
通常情况下，C/C++结构体中的数据会有一定 的对齐要求.

在这个例子中，可以通过offsetof查 看成员的偏移的方式来检验数据的对齐方式。
这里，成员b的偏移是4字节，而成员a只占用了1字节 内存空间，这意味着b并非紧邻着a排列。

事实上， 在我们的平台定义上，C/C++的int类型数据要求 对齐到4字节，即要求int类型数据必须放在一个能 够整除4的地址上；而char要求对齐到1字节。这就
造成了成员a之后的3字节空间被空出，通常我们也 称因为对齐而造成的内存留空为填充数据 （padding data）。


在C++中，每个类型的数据除去长度等属性之 外，都还有一项“被隐藏”属性，那就是对齐方 式

对于每个内置或者自定义类型，都存在一个特 定的对齐方式。
对齐方式通常是一个整数，它表示 的是一个类型的对象存放的内存地址应满足的条 件。
在这里，我们简单地将其称为对齐值。

在程序设计时，保证数据对齐是 保证正确有效读写数据的一个基本条件。


*/