/*
委派构造的一个很实际的应用就是使用构造模 板函数产生目标构造函数
*/
#include <list>
#include<vector>
#include<deque>
using namespace std;

class TDConstructed
{
    template<class T> 
    TDConstructed(T first, T last):l(first, last){}
    list<int> l;
public:
    TDConstructed(vector<short> &v):
    TDConstructed(v.begin(), v.end()){}

    TDConstructed(deque<int> &d):
    TDConstructed(d.begin(), d.end()){}

};

/*
而通过两个委派构造函数的委托，构造函数模板会被实例化。
T会分别被推导为vector＜short＞::iterator和deque＜int＞::iterator两种类型。
这样一来，我们的TDConstructed类就可以很容易地接受多种容器对其进行初始化。
这无疑比罗列不同类型的构造函数方便了很多。可以说，委托构造使得构造函数的泛型编程也成为了一种可能
*/