//用户想声明一个自定义类 型的“字面量”（literal）的时候

#include<iostream>
using namespace std;

typedef unsigned char uin8;

struct RGBA
{
    RGBA(uin8 r, uin8 g, uin8 b, uin8 a):r(r), g(g), b(b), a(a){}
    uin8 r, g, b, a;
    friend ostream& operator<<(ostream &os, const RGBA &c)
    {
        os << "(" << c.r << "," << c.g << "," << c.b << "," << c.a << ")";
        return os;
    }
};
void blend(const RGBA &c, RGBA &dst)
{
    cout<<"blend"<<endl<<c<<dst<<endl;
}

int main()
{
    RGBA c(255, 0, 0, 1);
    RGBA d({0, 255, 0, 1});
    blend(c, d);
    return 0;
}
