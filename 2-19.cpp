//友元类或友元函数都可以访问

class Poly;
typedef Poly P;

class LiLei
{
    friend class Poly;  //C++98通过,C++11通过
};

class Jim
{ 
    friend Poly;//C++98失败,C++11通过 
};
class HanMeiMei
{ 
    friend P;//C++98失败,C++11通过 
};