template<typename T1,typename T2=int>
class DefClass1; 

template<typename T1=int,typename T2>
class DefClass2;//无法通过编译 

template<typename T,int i=0>
class DefClass3; 

template<int i=0,typename T>
class DefClass4;//无法通过编译 

template<typename T1=int,typename T2>
void DefFunc1(T1 a,T2 b); 

template<int i=0,typename T>
void DefFunc2(T a);

/*
不按照从右往左 定义默认类模板参数的模板类DefClass2和 DefClass4都无法通过编译。
而对于函数模板来 说，默认模板参数的位置则比较随意
*/