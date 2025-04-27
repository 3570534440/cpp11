#include<iostream>
#include <string>
using namespace std;

class Test
{
public:
    Test() {};
    Test(int max)
    {
        this->m_max = max > 0 ? max : 100;
    }

    Test(int max, int min)
    {
        this->m_max = max > 0 ? max : 100;              // 冗余代码
        this->m_min = min > 0 && min < max ? min : 1;
    }

    Test(int max, int min, int mid)
    {
        this->m_max = max > 0 ? max : 100;             // 冗余代码
        this->m_min = min > 0 && min < max ? min : 1;  // 冗余代码
        this->m_middle = mid < max&& mid > min ? mid : 50;
    }

    //优化上面的代码：
    //Test(int max, int min) :Test(max)委托函数
    //{
    //    this->m_min = min > 0 && min < max ? min : 1;
    //}

    //Test(int max, int min, int mid) :Test(max, min)//在初始化列表后面可调用函数
    //{
    //    this->m_middle = mid < max&& mid > min ? mid : 50;
    //}



    int m_min;
    int m_max;
    int m_middle;
};

int main()
{
    Test t(90, 30, 60);
    cout << "min: " << t.m_min << ", middle: "
        << t.m_middle << ", max: " << t.m_max << endl;
    return 0;
}

/*
                                   继承构造函数
*/
class Base
{
public:
    Base(int i) :m_i(i) {}
    Base(int i, double j) :m_i(i), m_j(j) {}
    Base(int i, double j, string k) :m_i(i), m_j(j), m_k(k) {}

    void func(int i)
    {
        cout << "base class: i = " << i << endl;
    }

    void func(int i, string str)
    {
        cout << "base class: i = " << i << ", str = " << str << endl;
    }

    int m_i;
    double m_j;
    string m_k;
};

class Child : public Base
{
public:
    using Base::Base;
    using Base::func;
    void func()
    {
        cout << "child class: i'am luffy!!!" << endl;
    }
};

int main()
{
    Child c(250);
    c.func();
    c.func(19);
    c.func(19, "luffy");
    return 0;
}
