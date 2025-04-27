
// auto可以在声明变量的时候根据变量初始值的类型自动为此变量选择匹配的类型
//使用auto关键字做类型自动推导时，依次施加一下规则：如果初始化表达式是引用，则去除引用语义。
//😂  也可以用  decltype
#include<iostream>
#include <string>
using namespace std;

int main()
{
	auto x = 3.33;
	auto y = 12;
	auto z = 'z';
	auto a;//错误
	auto double b;//错误

	int temp = 100;
	auto* a = &temp;
	auto b = &temp;

	//auto有些地方不能用
	/*
	
	如不能做函数的形参
	不能用于类的非静态成员的初始化
	不能用于定义数组
	不能用于推到模板参数


	*/
	/*
	auto的应用
	用于遍历stl容器中迭代器定义很长
int main()
{
    std::vector<std::string> vs;
    for (std::vector<std::string>::iterator i = vs.begin(); i != vs.end(); i++)
    {
        //...
    }
}
替换为
for (auto i = vs.begin(); i != vs.end(); i++)
    {
        //..
    }

	函数模板调用函数时，可根据返回值类型设置auto，不需要指定多个类型、
	
    
    使用auto关键字做类型自动推导时，依次施加一下规则：
    如果初始化表达式是引用，则去除引用语义。
    */
}



// //返回值后置语法
// #include <iostream>
// using namespace std;

// template <typename T, typename U>
// // 返回类型后置语法
// auto add(T t, U u) -> decltype(t+u) //返回值后置
// {
//     return t + u;
// }

// int main()
// {
//     int x = 520;
//     double y = 13.14;
//     // auto z = add<int, double>(x, y);
//     auto z = add(x, y);		// 简化之后的写法
//     cout << "z: " << z << endl;
//     return 0;
// }
// /*执行结果
// z: 533.14
// */

