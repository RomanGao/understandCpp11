/*
此外，在异常处理方面，如果在委派构造函数中使用try的话，
那么从目标构造函数中产生的异常，都可以在委派构造函数中被捕捉到
委托构造仅支持cpp 11
*/
#include<iostream>
using namespace std;

class DCExcept
{
public:
    DCExcept(double d)
    try:DCExcept(1, d)
    {
        cout<<"run the body."<<endl;
    }
    catch(...)
    {
        cout<<"caught exception."<<endl;
    }
private:
    DCExcept(int i, double d)
    {
        cout<<"going to throw!"<<endl;
        throw 0;
    }
   int type;
   double data;
};

/*
int main()
{
    DCExcept a(1.2);
    return 0;
}
*/
