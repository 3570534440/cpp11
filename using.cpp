#include<iostream>
#include <string>
using namespace std;

int main()
{
	return 0;
}

/*
using定义别名
using 新的类型 = 旧的类型

using t2= int ;
t2 a =10;

typedef 与using
typedef int (* func)(int ,string);
using func = int (*)(int ,string);
很明显using定义的可读性好
func f = mytest;指针f指向一个返回值为ing参数为int和string的函数

using语法和typedef一样，并不会创建新的类型，他们只是
给某些类型定义了新的别名，using看起来更加直观

*/