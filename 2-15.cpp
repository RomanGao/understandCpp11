#include<string>
using namespace std;

//在C++11中，标准允许非静态成员变量的初始化有多种形式。
//具体而言，除了初始化列表外，在C++11中，标准还允许使用等号=或者花括号{}进行就地的非静态成员变量初始化。
//struct init{int a=1; double b{1.2};};


struct C
{
    C(int i):c(i){}
    int c;
};
//c++11 中的{}与c++98种的()并非等价的
struct init{
    int a=1;
  //  string b("hello");//无法通过编译
  //  C c(1);//无法通过编译
};
/*
int main()
{
    return 0;
}
*/
