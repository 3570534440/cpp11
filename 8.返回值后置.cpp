#include<iostream>
#include <string>
using namespace std;

template <typename T,typename U>
auto add(T t, U u);
{
	return t + u;
}
//auto可自动推导返回值类型，这样可以少写一种返回类型
