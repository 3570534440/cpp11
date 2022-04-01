//左值（L-value）：表示存储在计算机内存的对象，可寻址，相当于地址值

//右值（R-value）：代表的为真实值，可读，即数据值

//int a,b;
//a=5;//为合法的操作，因为a是个地址值；
//b=a;//这个也是个合法操作，在这里b为地址值，a取其数据值即5(注意这里不是取地址值，因为a是作为一个右值)
//5=5;//这是一个非法操作，因为左值是个数据值，右值也是个数据值

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
// sum的类型就是函数f返回的类型
decltype(f()) sum = x;
