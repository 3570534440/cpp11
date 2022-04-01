//在 C++11 添加了右值引用，并且不能使用左值初始化右值引用，如果想要使用左值初始化一个右值引
//用需要借助 std::move () 函数，使用std::move方法可以将左值转换为右值。使用这个函数并不能移
//动任何东西，而是和移动构造函数一样都具有移动语义，将对象的状态或者所有权从一个对象转移到
//另一个对象，只是转移，没有内存拷贝。

//从实现上讲，std::move 基本等同于一个类型转换：static_cast<T&&>(lvalue);，函数原型如下:

template<class _Ty>
_NODISCARD constexpr remove_reference_t<_Ty>&& move(_Ty&& _Arg) _NOEXCEPT
{	// forward _Arg as movable
    return (static_cast<remove_reference_t<_Ty>&&>(_Arg));
}
class Test
{
public：
    Test(){}
    ......
}
int main()
{
    Test t;
    Test && v1 = t;          // error
    Test && v2 = move(t);    // ok
    return 0;
}
list<string> ls;
ls.push_back("hello");
ls.push_back("world");
......
list<string> ls1 = ls;        // 需要拷贝, 效率低
list<string> ls2 = move(ls);


//右值引用类型是独立于值的，一个右值引用作为函数参数的形参时，在函数内部转
//发该参数给内部其他函数时，它就变成一个左值，并不是原来的类型了。如果需要
//按照参数原来的类型转发到另一个函数，可以使用 C++11 提供的 std::forward () 函数
//该函数实现的功能称之为完美转发。

// 函数原型
template <class T> T&& forward (typename remove_reference<T>::type& t) noexcept;
template <class T> T&& forward (typename remove_reference<T>::type&& t) noexcept;

// 精简之后的样子
std::forward<T>(t);
//fordward的使用方法
#include <iostream>
using namespace std;

template<typename T>
void printValue(T& t)
{
    cout << "l-value: " << t << endl;
}

template<typename T>
void printValue(T&& t)
{
    cout << "r-value: " << t << endl;
}

template<typename T>
void testForward(T && v)//传递参数时，右值引用会变为左值引用，但左值引用不会变为右值引用
{
    printValue(v);
    printValue(move(v));
    printValue(forward<T>(v));
    cout << endl;
}

int main()
{
    testForward(520);//先右值引用 然后左值引用 然后右值引用， 然后右值引用
    int num = 1314;
    testForward(num);
    testForward(forward<int>(num));//int是右值引用
    testForward(forward<int&>(num));
    testForward(forward<int&&>(num));

    return 0;
}

