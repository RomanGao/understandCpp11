/*
所谓完美转发（perfect forwarding），是指 在函数模板中，完全依照模板的参数的类型，将参 数传递给函数模板中调用的另外一个函数

template＜typename T＞ void IamForwording(T t){IrunCodeActually(t);}
IamForwording是一个转 发函数模板。而函数IrunCodeActually则是真正执 行代码的目标函数。
对于目标函数 IrunCodeActually而言，它总是希望转发函数将参 数按照传入Iamforwarding时的类型传递（即传入 IamForwording的是左值对象，IrunCodeActually
就能获得左值对象，传入IamForwording的是右值 对象，IrunCodeActually就能获得右值对象），而 不产生额外的开销，就好像转发者不存在一样.


所以通常程序员需要的是一个引用类型，引用 类型不会有拷贝的开销。
其次，则需要考虑转发函 数对类型的接受能力。因为目标函数可能需要能够 既接受左值引用，又接受右值引用。那么如果转发
函数只能接受其中的一部分，我们也无法做到完美 转发。


我们会想到“万能”的常量左 值类型。不过以常量左值为参数的转发函数却会遇 到一些尴尬,比如：
void IrunCodeActually(int t){}
template＜typename T＞ void IamForwording(const T& t){IrunCodeActually(t);}
由于目标函数的参数类型是非常量左值 引用类型，因此无法接受常量左值引用作为参数，
 这样一来，虽然转发函数的接受能力很高，但在目 标函数的接受上却出了问题。
 如果我们的目标函 数的参数是个右值引用的话，同样无法接受任何左 值类型作为参数，间接地，也就导致无法使用移动 语义


实 际上，C++11是通过引入一条所谓“引用折叠”（reference collapsing）的新语言规则，并结合新的模板推导规则来完成完美转发

typedef const int T; 
typedef T＆TR; 
TR＆v=1;//该声明在C++98中会导致编译错误
其中TR＆v=1这样的表达式会被编译器认为是 不合法的表达式，而在C++11中，一旦出现了这
样的表达式，就会发生引用折叠，即将复杂的未知表达式折叠为已知的简单表达式。

一旦定义中出现了左值引用，引用折叠总是优先将其折叠为左值引用。
而模板对类型的推导规则就比较简单，
当转发 函数的实参是类型X的一个左值引用，那么模板参数被推导为X＆类型，
而转发函数的实参是类型X的 一个右值引用的话，那么模板的参数被推导为X＆＆类型。
我们可以把转发函数写成 如下形式：
template＜typename T＞ void IamForwording(T＆＆t)
{ IrunCodeActually(static_cast＜T＆＆＞(t)); }
这里的static_cast是留给传递右值用的


，对于一个右值而言， 当它使用右值引用表达式引用的时候，该右值引用 却是个不折不扣的左值，
那么我们想在函数调用中 继续传递右值，就需要使用std::move来进行左右 值的转换。
而std::move通常就是一个 static_cast。
不过在C++11中，用于完美转发的函 数却不再叫作move，而是另外一个名字：forward。
template＜typename T＞ 
void IamForwording(T＆＆t){ IrunCodeActually(forward(t)); }


move和forward在实际实现上差别并不大。
不 过标准库这么设计，也许是为了让每个名字对应于不同的用途。
*/

#include <iostream>
using namespace std;

void RunCode(int && m)
{cout<<"rvalue ref"<< endl;}
void RunCode(int & m)
{cout<<"lvalue ref"<< endl;}
void RunCode(const int& m)
{
    cout<<"const lvalue ref"<< endl;
}
void RunCode(const int&& m)
{
    cout<<"const rvalue ref"<< endl;
}
template<typename T>
void Forwarding(T&& t)
{
    RunCode(forward<T>(t));
}

int main()
{
    int a = 1;
    int b = 2;
    const int c = 3;
    const  int d = 4;

    Forwarding(a);  
    Forwarding(move(b));
    Forwarding(c);
    Forwarding(move(d));
    return 0;
}
//完美转发的一个作用就是做包装函数，这是一 个很方便的功能。

