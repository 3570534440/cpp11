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
	t.a = 10;//����,��Ϊa������Ϊ����
	//constexpr,���κ�������Ϊ�������
	//����return�ķ���ֵ�� ���ǳ���
	// 
	//����������main������ǰ��
	/*
	�����������������У����ܳ��ֳ������ʽ֮������
	Ҳ����˵��������ǱȽϼ򵥵�

	������ε���ģ�庯���������ݴ����Ĳ����������

	���ι��캯��
	*/
	
}