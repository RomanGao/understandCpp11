/*
比较一下这些内置仿函数与lambda使用 上的特点。
*/
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
vector<int> nums;

void OneCond(int val)
{
    //传统的for循环
    for(auto i= nums.begin(); i!=nums.end(); i++)
    {
        if(*i == val) break;
    }
    //内置的仿函数(template)equal_to,通过bind使其 成为单参数调用的仿函数
    find_if(nums.begin(), nums.end(),bind(equal_to<int>(), placeholders::_1,val));
    find_if(nums.begin(), nums.end(), [=](int i ){
        return i==val;
        });
}

int main()
{
    return 0;
}

/*
占位符：
https://cplusplus.com/reference/functional/placeholders/?kw=placeholders
*/

/*
列出了3种方式来寻找vector nums中第一个值等于val的元素。
我 们可以看一下使用内置仿函数的方式。
没有太多接 触过STL算法的人可能对bind(equal_to＜int＞ (),val)这段代码相当迷惑，
但简单地说，就是定义 了一个功能是比较i==val的仿函数，并通过一定方 式（bind）使其函数调用接口只需要一个参数 即可。
反观lambda函数，其意义简洁明了，使用 者使用的时候，也不需要有太多的背景知识。

*/