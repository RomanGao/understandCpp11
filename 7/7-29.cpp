/*
lambda与STL


通过for_each，我们可以完成各种循环操作。
*/

#include<vector>
#include <algorithm>
using namespace std;

vector<int> nums;
vector<int> largeNums;
const int ubound = 10;

inline void LargeNumsFunc(int i)
{
    if(i > ubound)
    {
        largeNums.push_back(i);
    }
}

void Above()
{
    for(auto itr = nums.begin(); itr!=nums.end(); itr++)
    {
        if(*itr > ubound)
        largeNums.push_back(*itr);
    }
}

int main()
{
    for_each(nums.begin(), nums.end(), LargeNumsFunc);

    for_each(nums.begin(),nums.end(),[=](int i){ if(i>ubound) largeNums.push_back(i); });
    return 0;
}
/*
第一种是传统的for循环；
第二 种，则更泛型地使用了for_each算法以及函数指 针；
第三种同样使用了for_each，但是第三个参数传入的是lambda函数。


那么我们再比较一下函数指针方式以及lambda 方式。
函数指针的方式看似简洁，不过却有很大的 缺陷。
第一点是函数定义在别的地方，比如很多行 以前（后）或者别的文件中，这样的代码阅读起来并不方便。
第二点则是出于效率考虑，使用函数指针很可能导致编译器不对其进行inline优化（inline 对编译器而言并非强制），
在循环次数较多的时候，内联的lambda和没有能够内联的函数指针可能存在着巨大的性能差别。
因此，相比于函数指 针，lambda拥有无可替代的优势。


首先必须指出的是使用for_each的好处。
使用for_each算法相较于手写的循环在效 率、正确性、可维护性上都具有一定优势。
最典型 的，程序员不用关心iterator，或者说循环的细 节，只需要设定边界，作用于每个元素的操作，
就 可以在近似“一条语句”内完成循环，正如函数指 针版本和lambda版本完成的那样

此外，函数指针的应用范围相对狭小，尤其是 我们需要具备一些运行时才能决定的状态的时候， 函数指针就会捉襟见肘了。

内联函数介绍：
https://www.geeksforgeeks.org/inline-functions-cpp/
*/


