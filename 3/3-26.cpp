/*
显式转换操作符
*/

#include <iostream>
using  namespace std;

struct Rational1
{
    Rational1(int n = 0, int d = 1):num(n), den(d)
    {
        cout << __func__<<"("<<num<<"/"<<den<<")"<<endl;
    }
    int num;
    int den;
};

struct Rational2
{
    explicit Rational2(int n = 0, int d = 1):num(n), den(d)
    {
        cout << __func__<<"("<<num<<"/"<<den<<")"<<endl;
    }
    int num;
    int den;
};

void Display1(Rational1 r)
{
    cout << r.num<<"/"<<r.den<<endl;
}

void Display2(Rational2 r)
{
    cout<<r.num<<"/"<<r.den<<endl;
}

int main()
{
    Rational1 r1_1 = 11;
    Rational1 r1_2(12);
   // Rational2 r2_1=21;//无法通过编译
   Rational2 r2_2(31);
   Display1(1);
  // Display2(2);//无法通过编译
    Display2(Rational2(2));
}

/*
只不过 Rational1的构造函数Rational1(int,int)没有explicit 关键字修饰，这意味着该构造函数可以被隐式调 用。因此，在定义变量r1_1的时候，字面量11就会 成功地构造出Rational1(11,1)这样的变量， Rational2却不能从字面量21中构造，
这是因为其 构造函数由于使用了关键字explicit修饰，禁止被隐 式构造，因此会导致编译失败。


因此，使用了 explicit这个关键字保证对象的显式构造在一些情况 下都是必须的
*/