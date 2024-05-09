int Prioritize(int); 
int AllWorks(int times)
{ 
    int i; 
    int x;
    try
    { 
        for(i=0;i<times;i++) 
        x+=Prioritize(i); 
    }
    catch(...)
    {
        x=0; 
    }

    const int y=[=]
    { 
        int i,val;
        try
        { 
            for(i=0;i<times;i++) 
            val+=Prioritize(i);
        }
        catch(...){ val=0; }
        return val; 
    }();
};
/*
我们对x和y的 初始化实际是完全一致的。
可以看到，x（或y）的 初始化需要循环调用函数Prioritize，并且在 Prioritize抛出异常的时候对x（或y）赋默认值0


在不使用函数的情况下，由于初始化要在运行 时修改x的值，因此，虽然x在初始化之后对于程序 而言是个常量，却不能被声明为const。
而在定义y 的时候，由于我们就地定义lambda函数并且调
用，y仅需使用其返回值，于是常量性得到了保 证。
*/
