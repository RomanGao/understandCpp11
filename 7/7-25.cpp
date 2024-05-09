#include<iostream>
using namespace std;

int main()
{
    int j = 12;
    auto by_val_lambda=[=]{return j+1;};
    auto by_ref_lambda =[&]{return j+1;};

    cout<<"by_val: "<<by_val_lambda()<<endl;
    cout<<"by_ref: "<<by_ref_lambda()<<endl;

    j++;
    cout<<"by_val: "<<by_val_lambda()<<endl;
    cout<<"by_ref: "<<by_ref_lambda()<<endl;

    /*
    by_val: 13
    by_ref: 13
    by_val: 13
    by_ref: 14
    */
}

/*
这个结果的原因是由于在by_val_lambda中，j被视为了一个 常量，一
旦初始化后不会再改变（可以认为之后只是一个跟父作用域中j同名的常量）
而在 by_ref_lambda中，j仍在使用父作用域中的值。



在使用lambda函数的时候，如果需要捕捉的值成为lambda函数的常量， 我们通常会使用按 [值] 传递的方式捕捉；
反之，需要捕捉的值成为lambda函数运行时的变量（类似于 参数的效果），则应该采用按 [引用] 方式进行捕捉。
*/


