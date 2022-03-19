#include<iostream>
#include <string>
using namespace std;

int main()
{
	int a = 10;
	decltype(a) b = 12;//b是int
	decltype(a+3.14) b = 12.12;//b是double类型 
	decltype(a+b*b) d = 12.24;

	//应用：泛型编程
}