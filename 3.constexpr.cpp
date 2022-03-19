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