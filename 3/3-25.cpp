#include<iostream>
using namespace std;

template<typename T, typename U>
void PerfectForward(T&& t, U&Func) 
{
    cout << "T&&: " << t <<"\tforwarded..."<<endl;
    Func(forward<T>(t));
}

void RunCode(double&& m){} 
void RunHome(double&& h){} 
void RunComp(double&& c){}

int main()
{ 
    PerfectForward(1.5,RunComp);//1.5 forwarded... 
    PerfectForward(8,RunCode);//8 forwarded... 
    PerfectForward(1.5,RunHome);//1.5 forwarded... 
    return 0;
}
//无论从运行性能的提高还是从代码编写 的简化上，完美转发都堪称完美。