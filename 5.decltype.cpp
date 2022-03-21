#include<iostream>
#include <string>
using namespace std;

int main()
{
	int a = 10;
	decltype(a) b = 12;//b是int
	decltype(a+3.14) b = 12.12;//b是double类型 
	decltype(a+b*b) d = 12.24;

	//如果括号内的是一个函数，其返回值是什么类型修饰的数字就是什么类型
	//应用：泛型编程
}