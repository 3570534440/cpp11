//constexpr表达式是指值不会改变并且在编译过程就能得到计算结果的表达式。
//声明为constexpr的变量一定是一个const变量，而且必须用常量表达式初始化

//对于这条语句：const int sz = get_size();sz本身是常量，但它的具体值直到运行时才能获得，不是常量表达式
//const int sz = get_size();         //重要！！！sz本身是常量，但它的具体值直到运行时才能获得，不是常量表达式

//C++11新标准规定，允许将变量声明为constexpr类型以便由编译器来验证变量的值是否是一个常量表达式。
//声明为constexpr的变量一定是一个常量，而且必须用常量表达式初始化：

#include<iostream>
#include <string>
using namespace std;

//const
struct T
{
	int a = 100;
};
int main()
{
	constexpr T t={100};
	t.a = 10;//错误,因为a被修饰为常量
	//constexpr,修饰函数，成为常量表达
	//函数return的返回值必 须是常量
	// 
	//声明必须在main函数的前面
	/*
	在整个函数的主体中，不能出现常量表达式之外的语句
	也就是说这个函数是比较简单的

	如果修饰的是模板函数，则会根据传进的参数来分情况

	修饰构造函数
	*/
	
}