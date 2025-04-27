//constexpr表达式是指值不会改变并且在编译过程就能得到计算结果的表达式。
//声明为constexpr的变量一定是一个const变量，而且必须用常量表达式初始化

//对于这条语句：const int sz = get_size();sz本身是常量，但它的具体值直到运行时才能获得，不是常量表达式
//const int sz = get_size();         //重要！！！sz本身是常量，但它的具体值直到运行时才能获得，不是常量表达式

//C++11新标准规定，允许将变量声明为constexpr类型以便由编译器来验证变量的值是否是一个常量表达式。
//声明为constexpr的变量一定是一个常量，而且必须用常量表达式初始化：

#include <iostream>
#include <string>
using namespace std;

// struct T
// {
// 	int a = 100;
// };

// constexpr int func2()
// {
//     using mytype = int;
//     constexpr mytype a = 100;
//     constexpr mytype b = 10;
//     constexpr mytype c = a * b;
//     return c - (a + b);
// }

// int main()
// {
// 	constexpr T t = {100};
// 	// t.a = 10; // 错误，不能修改

// 	cout << "func2(): " << func2() << endl;

// 	return 0;
// }
/*
执行结果：
func2(): 890

*/
/*
在constexpr函数里，只能写很简单的东西：
不允许有for循环、if语句（C++20之前）
不允许有cout（输出操作是运行时的，不是编译期能做的）
*/

// // error，不是常量表达式函数
// constexpr void func1()
// {
//     int a = 100;
//     cout << "a: " << a << endl;
// }


// // error 不能有for循环
// constexpr int func1()
// {
//     constexpr int a = 100;
//     constexpr int b = 10;
//     for (int i = 0; i < b; ++i)
//     {
//         cout << "i: " << i << endl;
//     }
//     return a + b;
// }

// // ok
// constexpr int func2()
// {
//     using mytype = int;
//     constexpr mytype a = 100;
//     constexpr mytype b = 10;
//     constexpr mytype c = a * b;
//     return c - (a + b);
// }

//修饰模板函数

struct Person {
    const char* name;
    int age;
};

// 定义函数模板
template<typename T>
constexpr T dispaly(T t) {
    return t;
}

int main()
{
    struct Person p { "luffy", 19 };
    //普通函数
    struct Person ret = dispaly(p);
    cout << "luffy's name: " << ret.name << ", age: " << ret.age << endl;

    //常量表达式函数
    constexpr int ret1 = dispaly(250);
    cout << ret1 << endl;

    constexpr struct Person p1 { "luffy", 19 };
    constexpr struct Person p2 = dispaly(p1);
    cout << "luffy's name: " << p2.name << ", age: " << p2.age << endl;
    return 0;
}

/*
执行结果：
luffy's name: luffy, age: 19
250
luffy's name: luffy, age: 19
*/