/*
相比于断言适用于排除逻辑上不可能存在的状态，
异常通常是用于逻辑上可能发生的错误

从语法上讲，noexcept修饰符有两种形式:
void excpt_func() noexcept;  //相当于声明了noexcept(true)，即不会抛出异常。
void excpt_func() noexcept(常量表达式);
*/
#include<iostream>
using namespace std;

//唯一作用是抛出一个异常
void Throw() {throw 1;}
//调用Throw的普通函数
void NoBlockThrow() {Throw();}
//一个noexcept修饰的函数
void BlockThrow() noexcept {Throw();} //直接中断程序

/*
int main()
{
    try
    {
        Throw();
    }
    catch(...)
    {
        cout<<"Found throw."<<endl;
    }

    try
    {
        NoBlockThrow();
    }
    catch(...)
    {
        cout<<"Throw is not blocked."<<endl;
    }
    
    try
    {
        BlockThrow();
    }
    catch(...)
    {
        cout<<"Found Throw 1."<<endl;
    }
}

*/


/*
template＜classT＞
void fun() noexcept(noexcept(T())){}
fun函数是否是一个noexcept的函数，将由T()表达式是否会抛出异常所决定
当其参数是一个有可能抛出异常的表达式的时候，其返回值为false，反之为true
*/