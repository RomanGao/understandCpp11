/*
不过我们还需要注意一下explicit关键字在这里可能产生的影响。
*/

class ConvType
{
public:
    ConvType(int i){}
    explicit ConvType(char c)=delete;//删除explicit的char构造函数
};

void Func(ConvType ct){}

int main()
{   
    Func(10); //调用int版本
    Func('a'); ////可以通过编译
    
    ConvType ci(3); 
    //ConvType cc('a');//无法通过编译
    return 0;
}

/*
语句explicit ConvType(char)=delete将从char explicit构造
ConvType的方式显式删除了，这导致cc变量的构 造不成功，因为其是显式构造的。
不过在函数Func 的调用中，编译器会尝试隐式地将c转换成int，从 而Func('a')的调用会导致一次ConvType(int)构造， 因而能够通过编译。
这样一来，explicit带来了令人 尴尬的效果，即没有彻底地禁止类型转换的发生。 
如果程序员发生了这样的错误，也可能会比较难找 到原因。
*/