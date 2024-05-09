int main()
{ 
    int girls=3,boys=4; 
    //该函数接受两个参数(int x,int y)，并且返回其和。
    auto totalChild=[](int x,int y)->int{return x+y;}; 
    return totalChild(girls,boys); 
}
/*
[capture](parameters)mutable-＞return-type{statement}
其中
❑[capture]：捕捉列表。捕捉列表总是出现在 lambda函数的开始处。
事实上，[]是lambda引出 符。编译器根据该引出符判断接下来的代码是否是 lambda函数。捕捉列表能够捕捉上下文中的变量以供lambda函数使用。具体的方法在下文中会再 描述。
❑(parameters)：参数列表。与普通函数的参 数列表一致。如果不需要参数传递，则可以连同括 号()一起省略。
❑mutable：mutable修饰符。默认情况下， lambda函数总是一个const函数，mutable可以取 消其常量性。在使用该修饰符时，参数列表不可省 略（即使参数为空）。
❑-＞return-type：返回类型。用追踪返回类 型形式声明函数的返回类型。出于方便，不需要返 回值的时候也可以连同符号-＞一起省略。
此外， 在返回类型明确的情况下，也可以省略该部分，让编译器对返回类型进行推导。
❑{statement}：函数体。内容与普通函数一 样，不过除了可以使用参数之外，还可以使用所有 捕获的变量。

 在lambda函数的定义中，参数列表和返还类型 都是可选的部分，而捕捉列表和函数体都可能为 空。

*/