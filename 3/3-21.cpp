/*
std::move：强制转化为右值
在C++11中，标准库在＜utility＞中提供了一个有用的函数std::move
它唯一的功能是将一个左值强制转化为右值引用，继而我们可以通过右值引用使用该值，以用于移动语义。
从实现上讲，std::move基本等同于一个类型转换：static_cast＜T＆＆＞(lvalue);

值得一提的是，被转化的左值，其生命期并没有随着左右值的转化而改变。
*/


#include <iostream>
using namespace std;

class Moveable
{
private:
    /* data */
public:
     Moveable():i(new int(3)){}
     Moveable(const Moveable &m):i(new int(*m.i)){}  // 拷贝构造函数
     Moveable(Moveable &&m):i(m.i){m.i = nullptr;}   // 移动构造函数
     ~Moveable(){delete i;} 

    int *i;
};

int main()
{ 
    Moveable m1;
    Moveable m2(m1); // 拷贝构造函数
    cout<<*m1.i<<" "<<*m2.i<<endl;

   
    Moveable m3(std::move(m1)); // 移动构造函数
    //cout<<<*m1.i<<endl; // 报错  //这是个典型误用std::move的例子。
    //我们为类型Moveable定义了移动构造函数。
    //这个函数定义本身没有什么问题，但调用的时候，使用了Moveablec(move(a));这样的语句。
    //这里的a本来是一个左值变量，通过std::move将其转换为右值。这样一来，a.i就被c的移动构造函数设置为指针空值
    
    return 0;
}
