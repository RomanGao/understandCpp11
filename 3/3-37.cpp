/*
我们现在回到POD来，对于POD而言， 在C++11中的定义就是平凡的和标准布局的两个 方面。
同样地，要判定某一类型是否是POD，标准 库中的＜type_traits＞头文件也为程序员提供了如 下模板类：
template＜typename T＞struct std::is_pod;
*/

#include <iostream>
#include <type_traits>
using namespace std;

union U{};
union U1{U1(){}};
enum E{};
typedef double *DA;
typedef void (*PF)(int ,double);

int main()
{
    cout<<is_pod<U>::value<<endl;
    cout<<is_pod<U1>::value<<endl;
    cout<<is_pod<E>::value<<endl;
    cout<<is_pod<DA>::value<<endl;
    cout<<is_pod<PF>::value<<endl;
    cout<<is_pod<int>::value<<endl;
    return 0;
}
/*
使用POD有什么好处呢？我们看得 到的大概有如下3点：
1）字节赋值，代码中我们可以安全地使用 memset和memcpy对POD类型进行初始化和拷贝 等操作。
2)提供对C内存布局兼容。C++程序可以与C 函数进行相互操作，因为POD类型的数据在C与 C++间的操作总是安全的。
3)保证了静态初始化的安全有效。静态初始化 在很多时候能够提高程序的性能，而POD类型的对 象初始化往往更加简单（比如放入目标文件的.bss 段，在初始化中直接被赋0）。


*/