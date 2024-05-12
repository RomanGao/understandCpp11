/*
使用内敛函数，lambda函数对比
*/
#include<vector>
#include <algorithm>
using namespace std;

vector<int> nums;
vector<int> largeNums;
const int ubound = 10;

class LNums
{
public:
    LNums(int u):ubound(u){}
    void operator()(int i) const
    {
        if(i > ubound)
        {
            largeNums.push_back(i);
        }
    }  
private:
    int ubound;
};

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
    for_each(nums.begin(), nums.end(), LNums(ubound));

    for_each(nums.begin(),nums.end(),
    [=](int i){ if(i>ubound) largeNums.push_back(i); });

    return 0;
}
