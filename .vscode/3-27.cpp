/*
不过同样的机制并没有出现在自定义的类型转 换符上。
这就允许了一个逆向的过程，从自定义类 型转向一个已知类型。
*/

#include <iostream>
#include <string>
using  namespace std;

template <typename T>
class Ptr 
{
public:
    Ptr(T* ptr = nullptr) : m_ptr{ ptr } {}
    operator  bool() const 
    { 
        if (m_ptr !=0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

private:
    T* m_ptr;
};

int main()
{
    int a;
    Ptr<int> p1(&a);
    if (p1)
    {
        cout<<"valid pointer"<<endl;
    }
    else
    {
        cout<<"invalid pointer"<<endl;
    }
    Ptr<double> p2(0);
    cout<<p1+p2<<endl;
    
}

//为了方便判断指针是否有效，我们为指针 编写了自定义类型转换到bool类型的函数，
//这样一 来，我们就可以通过if(p)这样的表达式来轻松地判 断指针是否有效。