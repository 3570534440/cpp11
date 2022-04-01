//lambda 表达式是 C++11 最重要也是最常用的特性之一，这是现代编程语言的一个特点，lambda 表达式有如下的一些优点：
//
//声明式的编程风格：就地匿名定义目标函数或函数对象，不需要额外写一个命名函数或函数对象。
//简洁：避免了代码膨胀和功能分散，让开发更加高效。
//在需要的时间和地点实现功能闭包，使程序更加灵活
//

//[capture](params) opt->ret{ body; };

//其中 capture 是捕获列表，params 是参数列表，opt 是函数选项，ret 是返回值类型，body 是函数体。

//捕获列表[]: 捕获一定范围内的变量
//
//参数列表() : 和普通函数的参数列表一样，如果没有参数参数列表可以省略不写。
//
//auto f = []() {return 1; }	// 没有参数, 参数列表为空
//auto f = [] {return 1; }		// 没有参数, 参数列表省略不写
//opt 选项， 不需要可以省略
//
//mutable: 可以修改按值传递进来的拷贝（注意是能修改拷贝，而不是值本身）
//exception : 指定函数抛出的异常，如抛出整数类型的异常，可以使用 throw ();


/*

[] - 不捕捉任何变量
[&] - 捕获外部作用域中所有变量，并作为引用在函数体内使用(按引用捕获)
[=] - 捕获外部作用域中所有变量，并作为副本在函数体内使用(按值捕获)
拷贝的副本在匿名函数体内部是只读的
[=, &foo] - 按值捕获外部作用域中所有变量，并按照引用捕获外部变量 foo
[bar] - 按值捕获 bar 变量，同时不捕获其他变量
[&bar] - 按引用捕获 bar 变量，同时不捕获其他变量
[this] - 捕获当前类中的 this 指针
让 lambda 表达式拥有和当前类成员函数同样的访问权限
如果已经使用了 & 或者 =, 默认添加此选项

*/
#include <iostream>
#include <functional>
using namespace std;

class Test
{
public:
    void output(int x, int y)
    {
        auto x1 = [] {return m_number; };                      // error
        auto x2 = [=] {return m_number + x + y; };        //copy所有的外部变量     // ok
        auto x3 = [&] {return m_number + x + y; };             // ok
        auto x4 = [this] {return m_number; };                  // ok
        auto x5 = [this] {return m_number + x + y; };          // error
        auto x6 = [this, x, y] {return m_number + x + y; };    // ok
        auto x7 = [this] {return m_number++; };                // ok
    }
    int m_number = 100;
};
// = copy进来的变量是只读的不能++操作，可读不可写
// & 可以使用&来引用传递参数来改变变量
int main(void)
{
    int a = 10, b = 20;
    auto f1 = [] {return a; };                        // error
    auto f2 = [&] {return a++; };                     // ok
    auto f3 = [=] {return a; };                       // ok
    auto f4 = [=] {return a++; };    //只读的变量a                 // error
    auto f5 = [a] {return a + b; };  //没有捕获变量b                 // error
    auto f6 = [a, &b] {return a + (b++); };           // ok
    auto f7 = [=, &b] {return a + (b++); };           // ok

    return 0;
}
// 完整的lambda表达式定义
auto f = [](int a) -> int
{
    return a + 10;
};

// 忽略返回值的lambda表达式定义
auto f = [](int a)
{
    return a + 10;
};

// ok，可以自动推导出返回值类型
auto f = [](int i)
{
    return i;
}

// error，不能推导出返回值类型
auto f1 = []()
{
    return { 1, 2 };	// 基于列表初始化推导返回值，错误
}
//lambda表达式的类型在C++11中会被看做是一个带operator()的类，即仿函数。
//按照C++标准，lambda表达式的operator()默认是const的，一个const成员函数是无法修改成员变量值的。
//mutable 选项的作用就在于取消 operator () 的 const 属性。
//
//因为 lambda 表达式在 C++ 中会被看做是一个仿函数，
//因此可以使用std::function和std::bind来存储和操作lambda表达式：
//

#include <iostream>
#include <functional>
using namespace std;

int main(void)
{
    // 包装可调用函数
    std::function<int(int)> f1 = [](int a) {return a; };
    // 绑定可调用函数
    std::function<int(int)> f2 = bind([](int a) {return a; }, placeholders::_1);

    //匿名函数，这样可以提高代码的可读性，提高开发效率，
    // 绑定或包装函数之后可以使函数的参数变少，降元操作
    // 函数调用
    cout << f1(100) << endl;
    cout << f2(200) << endl;
    return 0;
}



