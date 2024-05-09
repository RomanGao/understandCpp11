#include<iostream>
using namespace std;
class AirportPrice
{
private:
    float _dutyfreerate;
public:
    AirportPrice(float rate):_dutyfreerate(rate){}

    float operator()(float price)
    {
        return price*(1-_dutyfreerate/100);
    }
};

int main()
{
    float tax_rate=5.5f;
    AirportPrice Changi(tax_rate);
    auto Changi2 =
    [tax_rate](float price)->float
    {
        return price*(1-tax_rate/100);
    };
    float purchased = Changi(3888);
    float purchased2 = Changi2(8999); 
    cout<<purchased<<"; "<<purchased2;
}

/*
该例 中，分别使用了仿函数和lambda两种方式来完成 扣税后的产品价格计算。
在这里我们看到， lambda函数捕捉了tax_rate变量，而仿函数则以 tax_rate初始化类。
其他的，如在参数传递上，两 者保持一致。可以看到，除去在语法层面上的不 同，
lambda和仿函数却有着相同的内涵——都可 以捕捉一些变量作为初始状态，并接受参数进行运算.

仿函数是编译器实现lambda的一种 方式。
在现阶段，通常编译器都会把lambda函数 转化为成为一个仿函数对象。
因此，在C++11 中，lambda可以视为仿函数的一种等价形式了， 或者更动听地说，lambda是仿函数的“语法甜 点
*/