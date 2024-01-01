/*
C++11标准中让类的析构函数默认也是noexcept(true)的。
如果程序员显式地为析构函数指定了noexcept，或者类的基类或成员有noexcept(false)的析构函数，析构函数就不会再保持默认值。
*/
/*
#include<iostream>
using namespace std;

struct A
{
    ~A () {throw 1;}
};

struct B
{
    ~B() noexcept(false) {throw 2;}
};

struct C
{
    B b;
};

int funA() {A a;}
int funB() {B b;}
int funC() {C c;}




int main()
{
    try
    {
        funB();
    }
    catch(...)
    {
       cout<<"caught funB."<<endl;
    }
    
    try
    {
        funC();
    }
    catch(...)
    {
       cout<<"caught funC."<<endl;
    }
    try
    {
        funA();   //libc++abi: terminating due to uncaught exception of type int
    }
    catch(...)
    {
       cout<<"caught funA."<<endl;
    }
}
*/
