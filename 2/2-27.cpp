/*
函数模板在C++98中与类模板一起被引入，不过在模板类声明的时候，c++11标准允许其有默认模板参数。
*/

void DefParm(int m = 3){}  ////c++98编译通过，c++11编 译通过

template<typename T =int >
class DefClass{}; //;//c++98编译通过，c++11编译通过

template<typename T=int>
void DefTempParm(){};//c++98编译失败，c++11编译 通过

#if 0
int main()
{
    return 0;
}
#endif