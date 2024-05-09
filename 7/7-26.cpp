/*
从C++11标准的定义上可以发现，lambda的 类型被定义为“闭包”（closure）的类，而每个 lambda表达式则会产生一个闭包类型的临时对象 （右值）。
因此，严格地讲，lambda函数并非函数指针。

不过C++11标准却允许lambda表达是向 函数指针的转换，
但前提是lambda函数 [没有捕捉任何变量]，且函数指针所示的函数原型，必须跟 lambda函数有着相同的调用方式。
*/


int main()
{
    int girls = 3, boys = 4;
    auto totalChild=[](int x, int y)->int
    {return x+y;};

    typedef int(*allChild)(int x, int y);
    typedef int(*oneChild)(int x);

    allChild p;
    p = totalChild;
    
   // q=totalChild;//编译失败，参数必须一致 
    decltype(totalChild)allPeople=totalChild;//需通过decltype获得lambda的类型 
   // decltype(totalChild)totalPeople=p;//编译失败，指 针无法转换为lambda 
    return 0;
}

/*
程序员也可以通过decltype的 方式来获得lambda函数的类型。
其方式如同代码 清单7-26中声明allPeople一样，虽然使用decltype 来获得lambda函数类型的做法不是很常见，
但在 实例化一些模板的时候使用该方法会较为有用。
*/