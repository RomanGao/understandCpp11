/*
[[carries_dependency]]。该通用属性既可以标识 函数参数，又可以标识函数的返回值。
当标识函数 的参数时，它表示数据依赖随着参数传递进入函 数，即不需要产生内存栅栏
*/

#include<iostream>
#include<atomic>
using namespace std;

atomic<int*> p1;
atomic<int*> p2;
atomic<int*> p3;
atomic<int*> p4;

void func_in1(int *val)
{
    cout<<*val<<endl;
}

void func_in2([[carries_dependency]] int* val)
{
    p2.store(val, memory_order_release);
    cout<<*p2<<endl;
}

[[carries_dependency]] int *func_out()
{
    return (int*)p3.load(memory_order_consume);
}

void Thread()
{
    int *p_ptr1 =(int*)p1.load(memory_order_consume); //L1
    cout<<*p_ptr1<<endl;//L2
 
    func_in1(p_ptr1); //L3
    func_in2(p_ptr1); //L4

    int *p_ptr3 = func_out();//L5
    p4.store(p_ptr3, memory_order_release); //L6
    cout<<*p_ptr3<<endl;
}

/*
L1句中，p1.load采用了 memory_order_consume的内存顺序，
因此任何 关于p1或者p_ptr1的原子操作，必须发生在L1句之后;

这样一来，L2将由编译器保证其执行必须在 L1之后（通过编译器正确的指令排序和内存栅 栏）

而当编译器在处理L3时，由于func_in1对于 编译器而言并没有声明[[carries_dependency]]属 性，编译器则可能采用保守的方法，
在func_in1调 用表达式之前插入内存栅栏;

而编译器在处理L4句 时，由于函数func_in2使用了 [[carries_dependency]]，
编译器则会假设函数体 内部会正确地处理内存顺序，因此不再产生内存栅 栏指令。

事实上func_in2中也由于p2.store使用了 内存顺序memory_order_release，因而不会产生 任何的问题。
而当编译器处理L5句时，由于 func_out的返回值使用了[[carries_dependency]]，编译器也不会在返回前 为p3.load(memory_order_consume)插入内存栅 栏指令去保证正确的内存顺序.

而在L6行中，我们 看到p4.store使用了memory_order_release，
因 此func_out不产生内存栅栏也是毫无问题的.
*/