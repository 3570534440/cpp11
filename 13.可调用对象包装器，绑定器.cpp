//笔记转载
//作者: 苏丙榅
//链接 : https://subingwen.cn/cpp/bind/#3-%E7%BB%91%E5%AE%9A%E5%99%A8
//来源: 爱编程的大丙
//
//


#include <iostream>
#include <vector>
using namespace std;
//在 C++ 中存在 “可调用对象” 这么一个概念。准确来说，可调用对象有如下几种定义：

int print(int a, double b)
{
    cout << a << b << endl;
    return 0;
}
// 定义函数指针
int (*func)(int, double) = &print;

//是一个具有operator()成员函数的类对象（仿函数）
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Test
{
    // ()操作符重载
    void operator()(string msg)
    {
        cout << "msg: " << msg << endl;
    }
};

int main(void)
{
    Test t;
    t("我是要成为海贼王的男人!!!");	// 仿函数
    return 0;
}
//是一个可被转换为函数指针的类对象
#include <iostream>
#include <string>
#include <vector>
using namespace std;

using func_ptr = void(*)(int, string);
struct Test
{
    static void print(int a, string b)
    {
        cout << "name: " << b << ", age: " << a << endl;
    }

    // 将类对象转换为函数指针
    operator func_ptr()
    {
        return print;
    }
};

int main(void)
{
    Test t;
    // 对象转换为函数指针, 并调用
    t(19, "Monkey D. Luffy");

    return 0;
}

//是一个类成员函数指针或者类成员指针

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Test
{
    void print(int a, string b)
    {
        cout << "name: " << b << ", age: " << a << endl;
    }
    int m_num;
};

int main(void)
{
    // 定义类成员函数指针指向类成员函数
    void (Test:: * func_ptr)(int, string) = &Test::print;
    // 类成员指针指向类成员变量
    int Test::* obj_ptr = &Test::m_num;

    Test t;
    // 通过类成员函数指针调用类成员函数
    (t.*func_ptr)(19, "Monkey D. Luffy");
    // 通过类成员指针初始化类成员变量
    t.*obj_ptr = 1;
    cout << "number is: " << t.m_num << endl;

    return 0;
}


//std::function是可调用对象的包装器。它是一个类模板，可以容纳除了类成员（函数）指针之外的所有可调用对象。通过指定它的模板参数，它可以用统一的方式处理函数、函数对象、函数指针，并允许保存和延迟执行它们。

//#include <functional>
//std::function<返回值类型(参数类型列表)> diy_name = 可调用对象;



#include <iostream>
#include <functional>
using namespace std;

int add(int a, int b)
{
    cout << a << " + " << b << " = " << a + b << endl;
    return a + b;
}

class T1
{
public:
    static int sub(int a, int b)
    {
        cout << a << " - " << b << " = " << a - b << endl;
        return a - b;
    }
};

class T2
{
public:
    int operator()(int a, int b)
    {
        cout << a << " * " << b << " = " << a * b << endl;
        return a * b;
    }
};

int main(void)
{
    // 绑定一个普通函数
    function<int(int, int)> f1 = add;
    // 绑定以静态类成员函数
    function<int(int, int)> f2 = T1::sub;
    // 绑定一个仿函数
    T2 t;
    function<int(int, int)> f3 = t;

    // 函数调用
    f1(9, 3);
    f2(9, 3);
    f3(9, 3);

    return 0;
}


//2.2 作为回调函数使用
//因为回调函数本身就是通过函数指针实现的，使用对象包装器可以取代函数指针的作用，来看一下下面的例子：
//

#include <iostream>
#include <functional>
using namespace std;

class A
{
public:
    // 构造函数参数是一个包装器对象
    A(const function<void()>& f) : callback(f)
    {
    }

    void notify()
    {
        callback(); // 调用通过构造函数得到的函数指针
    }
private:
    function<void()> callback;
};

class B
{
public:
    void operator()()
    {
        cout << "我是要成为海贼王的男人!!!" << endl;
    }
};
int main(void)
{
    B b;
    A a(b); // 仿函数通过包装器对象进行包装
    a.notify();

    return 0;
}
//
//通过上面的例子可以看出，使用对象包装器 std::function 可以非常方便的将仿函数转换为一个函数指针
// ，通过进行函数指针的传递，在其他函数的合适的位置就可以调用这个包装好的仿函数了。
//
//另外，使用 std::function 作为函数的传入参数，可以将定义方式不相同的可调用对象进行统一
// 的传递，这样大大增加了程序的灵活性。
//
//
//3. 绑定器
//std::bind用来将可调用对象与其参数一起进行绑定。绑定后的结果可以使用std::function进行保存，并延迟调用到任何我们需要的时候。通俗来讲，它主要有两大作用：
//
//将可调用对象与其参数一起绑定成一个仿函数。
//将多元（参数个数为n，n > 1）可调用对象转换为一元或者（n - 1）元可调用对象，即只绑定部分参数。

// 绑定非类成员函数/变量
auto f = std::bind(可调用对象地址, 绑定的参数 / 占位符);
// 绑定类成员函/变量
auto f = std::bind(类函数 / 成员地址, 类实例对象地址, 绑定的参数 / 占位符);


#include <iostream>
#include <functional>
using namespace std;

void callFunc(int x, const function<void(int)>& f)
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
        callFunc(i, f1);
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
//在上面的程序中，使用了 std::bind 绑定器，在函数外部通过绑定不
// 同的函数，控制了最后执行的结果。std::bind绑定器返回的是一个仿
// 函数类型，得到的返回值可以直接赋值给一个std::function，在使用
// 的时候我们并不需要关心绑定器的返回值类型，使用auto进行自动类型推导就可以了。
//
//placeholders::_1 是一个占位符，代表这个位置将在函数调用时被传入
// 的第一个参数所替代。同样还有其他的占位符 placeholders::_
// 2、placeholders::_3、placeholders::_4、placeholders::_5 等……
//
//有了占位符的概念之后，使得 std::bind 的使用变得非常灵活 :

#include <iostream>
#include <functional>
using namespace std;

void output(int x, int y)
{
    cout << x << " " << y << endl;
}

int main(void)
{
    // 使用绑定器绑定可调用对象和参数, 并调用得到的仿函数
    bind(output, 1, 2)();
    bind(output, placeholders::_1, 2)(10);
    bind(output, 2, placeholders::_1)(10);

    // error, 调用时没有第二个参数
    // bind(output, 2, placeholders::_2)(10);
    // 调用时第一个参数10被吞掉了，没有被使用
    bind(output, 2, placeholders::_2)(10, 20);

    bind(output, placeholders::_1, placeholders::_2)(10, 20);
    bind(output, placeholders::_2, placeholders::_1)(10, 20);


    return 0;
}




