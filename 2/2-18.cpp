#include<iostream>
using namespace std;
struct People
{
    public:
    int hand;
    static People *all;
};


/*
int main()
{
    People p;
    cout<<sizeof(p.hand)<<endl;//C++98中通过,C++11中通过
    cout<<sizeof(People::all)<<endl;//C++98中通过,C++11中通过
    cout<<sizeof(People::hand)<<endl;//C++98中错误,C++11中通过
    cout<<sizeof(int*)<<endl;

    cout<<sizeof(((People*)0)->hand)<<endl; ///C++98中在没有定义类实例的时候，要获得类成员的大小
    return 0;
}
*/


