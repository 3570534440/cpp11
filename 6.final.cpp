#include<iostream>
#include <string>
using namespace std;

class Base
{
public:
    virtual void test()//在虚函数的后面不能写
    {
        cout << "Base class...";
    }
};

class Child : public Base
{
public:
    void test() final//在继承虚函数的后面写
    {
        cout << "Child class...";
    }
};

class GrandChild : public Child
{
public:
    // 语法错误, 不允许重写
    void test()
    {
        cout << "GrandChild class...";
    }
};

//修饰类时
class Base
{
public:
    virtual void test()
    {
        cout << "Base class...";
    }
};

class Child final: public Base
{
public:
    void test()
    {
        cout << "Child class...";
    }
};

// error, 语法错误
class GrandChild : public Child
{
public:
};


//用来限制某个类不能被继承，或者某个虚函数不能被重写
//修饰函数或类
//只能修饰虚函数，这样就能阻止子类重写父类这个函数了
/*
在后面写final，只能修饰虚函数，在子类继承父类的虚函数
之后写，在虚函数后面不写

修饰类时，在后面直接写final就行，防止类被继承
*/
class Child final: public Base



/*
overeide重写父类的函数，写在函数的后面用来说明这个函数是
重写了父类的函数，以便检查错误是否写错了寒暑表，降低错误的概率
*/

class Base
{
public:
    virtual void test()
    {
        cout << "Base class...";
    }
};

class Child : public Base
{
public:
    void test() override
    {
        cout << "Child class...";
    }
};

class GrandChild : public Child
{
public:
    void test() override
    {
        cout << "Child class...";
    }
};
