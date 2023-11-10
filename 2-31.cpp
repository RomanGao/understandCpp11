/*
，虽然匿名类型可以被模板 参数所接受了，但并不意味着以下写法可以被接受


在C/C++中，即使是匿名类型的声明，也需要独立的表达式语句
*/

template<typename T>struct MyTemplate{}; 
int main()
{ 
  //  MyTemplate<struct{int a;}>t;//无法编译通过,匿名 类型的声明不能在模板实参位置 
    return 0; 
}

