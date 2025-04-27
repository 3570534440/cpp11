//std::bind用来将可调用对象与其参数一起进行绑定。绑定后的结果可以使用std::function进行保存，
//并延迟调用到任何我们需要的时候。通俗来讲，它主要有两大作用：

//将可调用对象与其参数一起绑定成一个仿函数。
//将多元（参数个数为n，n > 1）可调用对象转换为一元或者（n - 1）元可调用对象，即只绑定部分参数。


// 绑定非类成员函数/变量
//auto f = std::bind(可调用对象地址, 绑定的参数 / 占位符);
// 绑定类成员函/变量
//auto f = std::bind(类函数 / 成员地址, 类实例对象地址, 绑定的参数 / 占位符);

#include <iostream>
#include <functional>
using namespace std;

void callFunc(int x, const function<void(int)>& f)
//与callFunc(i, f1);相对应
{
    if (x % 2 == 0)
    {
        f(x);
    }
}

void output(int x)
{
    cout << x << " ";
}

void output_add(int x)
{
    cout << x + 10 << " ";
}

int main(void)
{
    // 使用绑定器绑定可调用对象和参数
    auto f1 = bind(output, placeholders::_1);
    for (int i = 0; i < 10; ++i)
    {
        callFunc(i, f1);//placeholders::_1占位符，对应第一个参数i
    }
    cout << endl;

    auto f2 = bind(output_add, placeholders::_1);
    for (int i = 0; i < 10; ++i)
    {
        callFunc(i, f2);
    }
    cout << endl;

    return 0;
}


//绑定类的成员函数
//placeholders::_1 是一个占位符，代表这个位置将在函数调用时被传入的第一个
//参数所替代。同样还有其他的占位符 placeholders::_2、placeholders::_3、
//placeholders::_4、placeholders::_5 等……

//有了占位符的概念之后，使得 std::bind 的使用变得非常灵活 :

void output(int x, int y)
{
    cout << x << " " << y << endl;
}

//int main(void)
//{
//    // 使用绑定器绑定可调用对象和参数, 并调用得到的仿函数
//    bind(output, 1, 2)();
//    bind(output, placeholders::_1, 2)(10);
//    bind(output, 2, placeholders::_1)(10);
//
// 
//    // error, 调用时没有第二个参数
//    // bind(output, 2, placeholders::_2)(10);
//    // 调用时第一个参数10被吞掉了，没有被使用
//    bind(output, 2, placeholders::_2)(10, 20);
//
//    bind(output, placeholders::_1, placeholders::_2)(10, 20);
//    bind(output, placeholders::_2, placeholders::_1)(10, 20);
//
//
//    return 0;
//   
//}
//


//绑定类的成员函数
//和绑定类的成员变量

class Test
{
public:
    void output(int x, int y)
    {
        cout << "x: " << x << ", y: " << y << endl;
    }
    int m_number = 100;
};

int main(void)
{
    Test t;
    // 绑定类成员函数
    function<void(int, int)> f1 =
        bind(&Test::output, &t, placeholders::_1, placeholders::_2);
    // 绑定类成员变量(公共)
    function<int& (void)> f2 = bind(&Test::m_number, &t);

    // 调用
    f1(520, 1314);
    f2() = 2333;
    cout << "t.m_number: " << t.m_number << endl;

    return 0;
}









