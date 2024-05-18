/*
事实上，C++11还在标准库中提供了 aligned_storage及aligned_union供程序员使用。
两者的原型如下： 
template＜std::size_t Len,std::size_t Align=default-alignment＞
 struct aligned_storage; 
 template＜std::size_t Len,class...Types＞ 
 struct aligned_union; 
 aligned_storage的第一个参数规定了 aligned_storage的大小，
 第二个参数则是其对齐 值。
*/

#include <iostream>
#include <type_traits>
#include <cstddef>
using namespace std;

struct IntAligned
{
    int a;
    char b;
};

typedef aligned_storage<
sizeof(IntAligned), alignof(long double)>::type StrickAligned;

int main()
{
    StrickAligned sa;
    IntAligned* pia = new (&sa) IntAligned;

    cout<<alignof(IntAligned)<<endl;//4 
    cout<<alignof(StrickAligned)<<endl;//8 
    cout<<alignof(*pia)<<endl;//4 
    cout<<alignof(sa)<<endl;//8

    
}

/*
我们使用了一个placement new来使得StrictAligned存储了本来应该只需要按
照4字节对齐的IntAligned对象。

虽然 StrictAligned对象sa的内容与IntAligned类型指针 pia所指向的对象完全相同，
但通过这样的声明，却 产生了比*pia更加严格的类型对齐要求;

因此虽然最后IntAligned对象的对齐方式没 有发生改变，但实际上却被更严格地对齐了

aligned_storage可以在产生对象的实例时对对齐方式做出一定的保证。
这无疑对“有历史”的代码的 重用、维护很有意义。

aligned_union的用法也基本与此相同。只不过 aligned_union使用了变长模板参数，
程序员可以 根据需要填入多种类型，最后aligned_union对象 的对齐要求会是多个类型中要求最为严格的一个。


*/