//由于有了扩展的friend声明，在C++11中，我们可以将2-21.cpp的Defender和Attacker类改良一下。

template<typename T>
class DefenderT
{
public:
    friend T;
    void Defence(int x,int y){} 
    void Tackle(int x,int y){}

private: 
    int pos_x=15; 
    int pos_y=0; 
    int speed=2; 
    int stamina=120;
};

template<typename T>
class AttackerT
{
public:
    friend T;
    void Move(int x,int y){} 
    void SpeedUp(float ratio){}
private: 
    int pos_x=0; 
    int pos_y=-30; 
    int speed=3; 
    int stamina=100;
};
//using来定义类型的别名，这跟使用typedef的定义类型的别名是完全一样的。
using Defender=DefenderT<int> ;//普通的类定义， 使用int做参数
using Attacker=AttackerT<int> ;

#ifdef UNIT_TEST 
class Validator
{ 
public: 
    void Validate(int x,int y,DefenderTest&d){} 
    void Validate(int x,int y,AttackerTest&a){} 
};
using DefenderTest=DefenderT<Validator>;//测试专用的定义，Validator类成为友元 
using AttackerTest=AttackerT<Validator>;

int main()
{ 
    DefenderTest d; 
    AttackerTest a; 
    a.Move(15,30); 
    d.Defence(15,30); 
    a.SpeedUp(1.5f); 
    d.Defence(15,30); 
    Validator v; 
    v.Validate(7,0,d); 
    v.Validate(1,-10,a); 
    return 0; 
}
#endif

/*
在需要进行测试的时候，我们使用 Validator为模板参数，实例化出DefenderTest及 AttackerTest版本的类，
这个版本的特点是， Validator是它们的友元，可以任意访问任何成员函数。
而另外一个版本则是使用int类型进行实例化的 Defender和Attacker，按照C++11的定义，它们不会有友元。
因此这个版本保持了良好的封装性，可以用于提供接口用于常规使用。
*/