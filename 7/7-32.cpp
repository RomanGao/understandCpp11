/*
我们并不能说lambda已经赢过了 内置仿函数。
而实际上，内置的仿函数应用范围很 受限制

找到vector nums中第一个值介于[low,high)间的元素。
*/

#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

vector<int> nums;

void TwoCond(int low, int high)
{
    for(auto i = nums.begin(); i!= nums.end(); ++i )
    {
        if(*i >= low && *i < high) break;
    }   
    //使用lambda
    find_if(nums.begin(), nums.end(), [low, high](int i){return i >= low && i < high;});
    //使用放生函数
//    find_if(nums.begin(), nums.end(), 
//     compose2(logical_and<bool>(), 
//    bind(greater_equal<int>(), placeholders::_1,low),
//     bind(less<int>(), placeholders::_1,high)));
}

int main()
{
    return 0;
}
/*
总结:需找到vector nums中第一个值介于[low,high)间的元素。
这里我 们看到内置仿函数变得异常复杂，而且程序员不得不接受使用非标准库函数的事实（compose2）。
 这对于需要移植性的程序来说，是非常难以让人接 受的。
 即使之前曾经很多人对内置仿函数这样的做 法点头称赞，
 但现实情况下可能人人都必须承认：
  lambda版本的实现非常的清晰，而且这一次代码 量甚至少于内置仿函数的版本，
  简直无可挑剔。
*/