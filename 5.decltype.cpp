#include<iostream>
#include <string>
using namespace std;

int main()
{
	int a = 10;
	decltype(a) b = 12;//b��int
	decltype(a+3.14) b = 12.12;//b��double���� 
	decltype(a+b*b) d = 12.24;

	//Ӧ�ã����ͱ��
}