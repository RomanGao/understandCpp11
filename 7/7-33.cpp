#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

vector<int> nums;
void Add(const int val)
{
    auto print=[&]{
        for(auto s:nums)
        {
      
            cout<<s<<"\t";
        }
        cout<<endl;
    };

    //传统的for循环方式 
    for(auto i = nums.begin(); i != nums.end(); ++i)
    {
        *i=*i+val;
    }
    print();
    //试一试for_each及内置仿函数
    for_each(nums.begin(),nums.end(), 
    bind2nd(plus<int>(),val));
    print();

    ////实际这里需要使用STL的一个变动性算法：transform
    transform(nums.begin(),nums.end(),nums.begin(),
    bind2nd(plus<int>(),val));
    print();
    //C++11的lambda表达式
    for_each(nums.begin(),nums.end(),[&](int& s){s+=val;});
    print();
};

int main()
{
    for(int i=0;i<10;i++)
    { 
        nums.push_back(i); 
    }
    Add(10);
    return 0;
}
/*
将vector中所有的元素的数值 加10。这里我们还是使用了传统的for方式、内置 仿函数的方式，以及lambda的方式。
此外，为了 方便调试，我们使用了一个lambda函数来打印局 部运行的结果。

我们发现，内置的仿函 数plus＜int＞()仅仅将加法结果返回，
为了将返回 结果再应用于vector nums，通常情况下，我们需要使用transform这个算法。
如我们第三段代码所 示，transform会遍历nums，并将结果写入 nums.begin()出首地址的目标区（第三参数）。

*/