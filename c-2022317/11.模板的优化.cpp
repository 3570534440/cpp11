#include<iostream>
#include <string>
using namespace std;

/*
模板的右尖括号
在模板嵌套时，有时会出现<<会被误认为是右移操作符

当容器作为模板参数时 最好价格空格
*/
/*
template <typename T =long ,typename U = int >函数模板,默认类型为long和int
//也根据传入参数自动推导mytest<int ,char>(a,b);
void mytest (T t = 'A',U u = 'b');
{
	cout <<t <<u <<endl;;
}


*/