/*
还有一个问题是关于lambda函数的常量性及mutable关键字的。
我们来看看代码清单 
*/
int main()
{
    int val;
    //编译失败,在const的lambda中修改常量 
    //auto const_val_lambda=[=](){val=3;};
    //非const的lambda,可以修改常量数据 
    auto mutable_val_lambda=[=]()mutable{val=3;};

    //依然是const的lambda，不过没有改动引用本身 
    auto const_ref_lambda=[&]{val=3;};
    //依然是const的lambda，通过参数传递val 
    auto const_param_lambda=[&](int v){v=3;};
    const_param_lambda(val);
    return 0;
}

/*
这4种lambda函数本身的 行为都是一致的，
即修改父作用域中传递而来的val参数的值。
*/