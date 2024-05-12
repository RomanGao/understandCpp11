/*
C++11标准不仅定义了指针空值常量nullptr， 也定义了其指针空值类型nullptr_t，也就表示了指 针空值类型并非仅有nullptr一个实例。
通常情况 下，也可以通过nullptr_t来声明一个指针空值类型 的变量（即使看起来用途不大）。


除去nullptr及nullptr_t以外，C++中还存在各 种内置类型。
C++11标准严格规定了数据间的关 系。
大体上常见的规则简单地列在了下面：
❑所有定义为nullptr_t类型的数据都是等价 的，行为也是完全一致
❑nullptr_t类型数据可以隐式转换成任意一个 指针类型。
❑nullptr_t类型数据不能转换为非指针类型， 即使使用reinterpret_cast＜nullptr_t＞()的方式也 是不可以的。
❑nullptr_t类型数据不适用于算术运算表达 式。
❑nullptr_t类型数据可以用于关系运算表达 式，
但仅能与nullptr_t类型数据或者指针类型数据 进行比较，
当且仅当关系运算符为==、＜=、＞= 等时返回true
*/
#include<iostream>
#include<typeinfo>
using namespace std;

int main()
{
    //nullptr可以隐式转换为char*
    char* cp = nullptr; 

    //不可转换为整型，而任何类型也不能转换为nullptr_t，以 下代码不能通过编译 
    //int n1=nullptr; 
    //int n2=reinterpret_cast＜int＞(nullptr);

    //nullptr与nullptr_t类型变量可以作比较，
    // 当使用==、 ＜=、＞=符号比较时返回true
    nullptr_t nptr;
    if(nptr == nullptr)
    {
        cout<<"nullptr_t nptr==nullptr"<<endl;
    }
    else
    {
        cout<<"nullptr_t nptr!=nullptr"<<endl;
    }

    //error invalid operands to binary expression 
   //('nullptr_t' (aka 'std::nullptr_t') and 'std::nullptr_t')
    //if(nptr <= nullptr)
    //{
    //    cout<<"nullptr_t nptr < nullptr"<<endl;
    //}
    //else
    //{
    //   cout<<"nullptr_t nptr !< nullptr"<<endl;
    //}

    //不能转换为整型或bool类型,以下代码不能通过编译 
    //if(0==nullptr); 
    //if(nullptr);
    //不可以进行算术运算,以下代码不能通过编译 
    //nullptr+=1; 
    //nullprt*5; 
   
    //以下操作均可以正常进行 
    sizeof(nullptr); 
    typeid(nullptr); 
    //throw(nullptr);

    return 0;
}
