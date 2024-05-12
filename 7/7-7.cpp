/*
在C++中声明自定义的类，编译器会默认帮助程序员生成一些他们未自定义的成员函数。
这样的函数版本被称为“默认函数”。
这包括了以下一些自定义类型的成员函数：
❑构造函数
❑拷贝构造函数
❑拷贝赋值函数（operator=）
❑移动构造函数
❑移动拷贝函数
❑析构函数

此外，C++编译器还会为以下这些自定义类型提供全局默认操作符函数：
❑operator,
❑operator＆
❑operator＆＆
❑operator*
❑operator-＞
❑operator-＞*
❑operatornew 
❑operatordelete
*/

/*
但更为严重的问题是，一旦声明了自定义版本的构造函
数，则有可能导致我们定义的类型不再是POD的。
*/
#include <iostream>
#include<type_traits>
using namespace std;

class TwoCstor
{
public:
    //提供了带参数版本的构造函数，则必须自行提供
    //不带参数版本，且TwoCstor不再是POD类型
    TwoCstor(){};
    TwoCstor(int i):data(i){}
private:
    int data;
};

int main()
{
    cout<<is_pod<TwoCstor>::value<<endl;
}

/*
程序员虽然提供了TwoCstor()构造函数，它与默认的构造函数接口和使用方式也完全一致，不过按照3.6节我们对“平凡的构造函数”的定义，
该构造函数却不是平凡的，因此TwoCstor也就不再是POD的了。
使用is_pod模板类查看TwoCstor，也会发现程序输出为0。
对于形如TwoCstor这样只是想增加一些构造方式的简单类型而言，变为非POD类型带来一系列负面影响有时是程序员所不希望的


因此客观上我们需要一些方式来使得这样的简单类型“恢复”POD的特质。
*/