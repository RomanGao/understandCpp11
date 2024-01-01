//为了帮助程序员写继承结构复杂的类型，引入了虚函数描述符override，
//如果派生类 在虚函数声明时使用了override描述符，那么该函数必须重载其基类中的同名函数，
//否则代码将无法通过编译。

struct Base
{
    virtual void Turing()=0; 
    virtual void Dijkstra()=0; 
    virtual void VNeumann(int g)=0; 
    virtual void DKnuth()const; 
    void Print(); 
};

struct DerivedMid:public Base
{
    //void VNeumann(double g); //(该处代码为注释)
    //接口被隔离了，曾想多一个版本的VNeumann函数
};
/*
基类的Base的 接口都没有重载，不过通过注释可以发现， 
DerivedMid的作者曾经想要重载出一个“void VNeumann(double g)”的版本。
这行注释显然迷 惑了编写DerivedTop的程序员
*/
struct DerivedTop:public DerivedMid{
    void Turing()override; 
   // void Dikjstra()override;//无法通过编译，拼写错误， 并非重载 
   // void VNeumann(double g)override;//无法通过编译， 参数不一致，并非重载 
   // void DKnuth()override;//无法通过编译，常量性不一 致，并非重载 
   // void Print()override;//无法通过编译，非虚函数重载

};
/*
DerivedTop
的作者在重载所有Base类的接口的时候，犯下了3 种不同的错误：
 ❑函数名拼写错，Dijkstra误写作了Dikjstra。 
 ❑函数原型不匹配，VNeumann函数的参数类 型误做了double类型，而DKnuth的常量性在派生 类中被取消了。
 ❑重写了非虚函数Print。
*/

/*
如果没有override修饰符，DerivedTop的作者可能在编译后都没有意识到自己犯了这么多错误。 
因为编译器对以上3种错误不会有任何的警示。这里override修饰符则可以保证编译器辅助地做一些检查。
我们可以看到，在代码清中， DerivedTop作者的4处错误都无法通过编译
*/

/*
因此编译器也就没 有必要提供检查“非重载”的状况。
而检查“一定 重载”的override关键字，对程序员的实际应用则 会更有意义。
*/