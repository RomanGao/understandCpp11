//编译器根据自己写的提示给出错误提示

//static_assert(sizeof(int)==8,"This64-bit machineshouldfollowthis!");

//int main(){return 0;}

/*
因此将static_assert写在函数体外通常是较好的选择，
这让代码阅读者可以较容易发现static_assert 为断言而非用户定义的函数。而反过来讲，
必须注意的是，static_assert的断言表达式的结果必须是在编译时期可以计算的表达式，即必须是常量表达式。
*/