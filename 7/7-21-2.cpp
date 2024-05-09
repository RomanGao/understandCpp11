/*
相比于函数，仿函数可以拥有初始状 态，
一般通过class定义私有成员，并在声明对象的 时候对其进行初始化。
私有成员的状态就成了仿函 数的初始状态。
而由于声明一个仿函数对象可以拥有多个不同初始状态的实例，
因此可以借由仿函数 产生多个功能类似却不同的仿函数实例
*/

#include<iostream>
using namespace std;

class Tax
{
private:
    float rate;
    int base;
public:
    Tax(float r, int b):rate(r),base(b){}
    float operator()(float money)
    {
        return (money - base)*rate;
    }
};

int main()
{
    Tax high(0.4, 30000);
    Tax middle(0.25, 20000);
    cout<<"tax over 3w: "<<high(38000)<<endl;
    cout<<"tax over 2w: " << middle(26000)<<endl;
}