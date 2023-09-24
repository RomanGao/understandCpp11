/*
一个类A中声明的虚函数fun在其派生类B中再次被定义，且B中的函数fun跟A中fun的原型一样（函 数名、参数列表等一样），
那么我们就称B重载 （overload）了A的fun函数。对于任何B类型的变量，调用成员函数fun都是调用了B重载的版本。
而如果同时有A的派生类C，却并没有重载A的fun函数，那么调用成员函数fun则会调用A中的版本。这在C++中就实现多态。
*/

//有的时候我 们并不想fun在B类型派生类中被重载，那么， C++98没有方法对此进行限制。
#include<iostream>
using namespace std;

class MathObject
{
public:
    virtual double Arith() = 0;
    virtual void Print() = 0;
};
class Printable:public MathObject
{
public:
//就是对于基类声 明为virtual的函数，之后的重载版本都不需要再声 明该重载函数为virtual。
//即使在派生类中声明了 virtual，该关键字也是编译器可以忽略的。
    double Arith() = 0;
  /*
   void Print()    //在C++98中我们无法阻止该接口被重写
    {
        cout<<"Output is"<<Arith()<<endl;
    }
  */ 
    //c++11中，final关键字的作用是使派生类不可覆盖它所修饰的虚函数，阻止派生类重载Print函数
    void Print() final
    {
        cout<<"Output is"<<Arith()<<endl;
    }
};

class Add2:public Printable
{
public:
    Add2(double a, double b):x(a), y(b) {}
    double Arith()
    {
        return x+y;
    }
private:
    double x, y;
};

class Mul3:public Printable
{
public:
    Mul3(double a, double b, double c):x(a),y(b),z(c){}
    double Arith()
    {
        return x*y *z;
    }
private:
    int x, y, z;
};