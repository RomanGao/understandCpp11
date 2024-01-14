//C++11标准允许了这种想象，即我们可以通过 定一个后缀标识的操作符，将声明了该后缀标识的 字面量转化为需要的类型。
 
 #include<cstdlib>
 #include<iostream>
 using namespace  std;

typedef unsigned char uint8;

struct RGBA
{
    uint8 r;
    uint8 g;
    uint8 b;
    uint8 a;
    RGBA(uint8 r, uint8 g, uint8 b, uint8 a=0)
    :r(r), g(g), b(b), a(a){}
};
RGBA operator""_C(const char *col, size_t n)
{
    const char *p = col;
    const char* end = col + n;
    const char *r, *g, *b, *a;
    r = g = b = a = nullptr;
    for(; p!=end; ++p)
    {
        if(*p == 'r')
            r = p;
        else if(*p == 'g')
            g = p;
        else if(*p == 'b')
            b = p;
        else if(*p == 'a')
            a = p;
    }
    if(r == nullptr || g == nullptr || b == nullptr)
        throw;
    else if (a == nullptr)
    {
        return RGBA(atoi(r + 1), atoi(g + 1), atoi(b + 1));
    }
    else
    {
        return RGBA(atoi(r + 1), atoi(g + 1), atoi(b + 1), atoi(a +1));
    }
}


std::ostream& operator <<(std::ostream &os, RGBA& c)
{
    return os << "RGB(" << (int)c.r << ", " 
    << (int)c.g << ", " 
    <<(int) c.b << ","<<(int)c.a
    <<")"<<endl;
}

void blend(RGBA &&col, RGBA &&col2)
{
    cout<<"blend"<<endl<<col<<col2<<endl;
}

int main()
{
    blend("r255 g240 b155"_C,"r15 g255 b10 a7"_C);
    return 0;
}


 