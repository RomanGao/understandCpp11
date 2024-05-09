extern int z; 
extern float c;
void Calc(int &, int, float&, float);
void TestCalc()
{
    int x,y=3;
    float a,b = 4.0;
    int success=0;

    //可以看到，lambda函数直接访问了TestCal中的局部的变量来完成这个工作
    auto validate=[&]()->bool
    {
        if((x == y+z)&&(a == b+c))
            return 1;
        else
            return 0;
    };
    Calc(x, y ,a, b);
    success += validate();
    y=1024; b=1e13; 
    Calc(x,y,a,b); 
    success+=validate();
}

/*
必须指出的是，相比于在函数外定义的static inline函数，
或者是自定义的宏，本例中lambda函 数并没有实际运行时的性能优势（但也不会差， lambda函数在C++11标准中默认是内联的）

同局部函数一样，lambda函数在代码的作用域上仅 属于其父作用域，
*/