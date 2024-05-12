#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
using namespace std;

void Stat(vector<int> &v)
{
    int errors;
    int score;

    auto print = [&]
    {
        cout << "Errors: " << errors << endl;
        cout << "Score: " << score << endl;
    };
    
    ////使用accumulate算法，需要两次循环
    errors = accumulate(v.begin(), v.end(), 0);
    score = accumulate(v.begin(), v.end(), 0, minus<int>());
    print();

    errors=0; score=100;
    // 使用lambda则只是用一次循环
    for_each(v.begin(), v.end(), [&](int x){ errors += x; score -= x; });
    print();
}   

int main()
{
    vector<int> v(10);
    generate(v.begin(), v.end(), []{ return rand() % 10; });
    Stat(v);
    return 0;
}

/*
通常情 况下，我们可以使用STL的accumulate算法及内置 仿函数来完成这个运算。
从代码的简洁性上来看， 这样做好像也不错。
不过实际上我们产生了两次循 环，一次计算errors，一次计算score。
而使用 lambda和万能的for_each的版本的时候，我们可 以从源代码层将循环合并起来。
事实上，我们可能 在实际工作中能够合并的循环更多。
如果采用 accumulate的方式，而编译器不能合理有效地合 并循环的话，我们可能就会遭受一定的性能损失
*/