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
	函数模板调用函数时，可根据返回值类型设置auto，不需要指定多个类型、
	*/
}