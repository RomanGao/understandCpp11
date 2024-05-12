/*
对齐描述符可以作用于各种数据。
具体来说， 可以修饰变量、类的数据成员等，
而位域（bit field）以及用register声明的变量则不可以。
*/

int main()
{
    //错误：alignas不能修饰 函数
    // alignas(double) void f();

    alignas(double)unsigned char c[sizeof(double)];//正确
    //extern unsigned char c[sizeof(double)];
   // alignas(float) extern unsigned char c[sizeof(double)];//错误： 不同对齐方式的变量定义
   
   
    return 0;
}

/*
C++11标准建议用户在 声明同一个变量的时候使用同样的对齐方式以免发 生意外。
不过C++11并没有规定声明变量采用了 不同的对齐方式就终止编译器的编译。
*/
