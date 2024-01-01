//为了方便测试，进行了危险的定义
#ifdef UNIT_TEST
#define private public
#endif

class Defender
{
public:
    void Defence(int x, int y){}
    void Tackle(int x, int y){}
private:
    int pox_x = 15;
    int pox_y = 0;
    int speed = 2;
    int stamina = 120;
};

class Attacker
{
public:
    void Move(int x, int y){}
    void SpeedUp(float ratio){}
private:
    int pox_x = 0;
    int pox_y = -30;
    int speed = 3;
    int stamina = 100;
};

#ifdef UNIT_TEST
class Validator  
{
public:
    void Validate(int x, int y, Defender &d){}
    void Validate(int x, int y ,Attacker &a){}
};

int main()
{ 
    Defender d; 
    Attacker a; 
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
//按照封装的思想，所有成员变量被声明为private的。
//此处，采用了比较危险的做法，即使用宏将private关键字统一替换为public关键字。

/*
这样的做法存在4个缺点：
一是如果侥 幸程序中没有变量包含private字符串，该方法可以正常工作，但反之，则有可能导致严重的编译时错误；
二是这种做法会降低代码可读性，因为改变了一个常见关键字的意义，没有注意到这个宏的程序员可能会非常迷惑程序的行为；
三是如果在类的成 员定义时不指定关键字（如public、private、 protect等），而使用默认的private成员访问限制，那么该方法也不能达到目的；
四则很简单，这样的做法看起来也并不漂亮。
*/