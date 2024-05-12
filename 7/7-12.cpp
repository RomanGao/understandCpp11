/*
关于显式删除，正如我们在上一节中看到，显 式删除可以避免用户使用一些不应该使用的类的成 员函数。
不过显式删除也并非局限于成员函数，使 用显式删除还可以避免编译器做一些不必要的隐式 数据类型转换。
*/

class ConvType
{
public:
    ConvType(int i){}
    ConvType(char c)=delete;//删除char版本
};

void Func(ConvType ct){}

int main()
{   
    Func(10); //调用int版本
   // Func('a'); //调用char版本，编译器会报错，提示该函数已被删除
    
    ConvType ci(3); 
    //ConvType cc('a');//无法通过编译
    return 0;
}

/*
我们显式删除了 ConvType(char)版本的构造函数。则在调用 Func('a')及构造变量cc的时候，编译器会给出错误 提示并停止编译。这是因为编译器发现从char构造 ConvType的方式是不被允许的。
不过如果读者将 ConvType(char c)=delete;这一句注释掉，代码就可以通过编译了。

编译器会 隐式地将a转换为整型，并调用整型版本的构造函 数。
这样一来，我们就可以对一些危险的、不应该 发生的隐式类型转换进行适当的控制。
*/

