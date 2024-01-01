/*
标准将explicit的使用范围扩展到 了自定义的类型转换操作符上，以支持所谓的“显 式类型转换”。
explicit关键字作用于类型转换操作符上，意味着只有在直接构造目标类型或显式类型 转换的时候可以使用该类型。\
*/

class ConvertTo{}; 

//explicit关键字的作用是防止隐式类型转换 
class Convertable
{ 
public: 
//Convertable定义了一 个显式转换到ConvertTo类型的类型转换符
    explicit operator ConvertTo()const
    {return ConvertTo();} 
};
void Func(ConvertTo ct){}

void test()
{ 
    Convertable c; 
    ConvertTo ct(c);//直接初始化，通过 
   // ConvertTo ct2=c;//拷贝构造初始化，编译失败 
    ConvertTo ct3=static_cast<ConvertTo>(c);//强 制转化，通过 
    //Func(c);//拷贝构造初始化，编译失败 
}

//而ct2由于需要从c中拷贝构造，因而不能通过 编译。
//此外，我们使用函数Func的时候，传入 Convertable的变量c的也会导致参数的拷贝构造， 因此也不能通过编译。