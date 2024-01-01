
/*
int positive(const int n)
{
    static_assert(n＞0,"valuemust＞0");
}


使用了参数变量n（虽然是个
const参数），因而static_assert无法通过编译。
对于此例，如果程序员需要的只是运行时的检查，那么还是应该使用assert宏。
assert(n > 0);
*/