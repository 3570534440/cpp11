#include<iostream>
#include <string>
using namespace std;

//Test t1(520);
//Test t2 = 520;
//Test t3 = { 520 };
//Test t4{ 520 };
//int a1 = { 1314 };
//int a2{ 1314 };
//int arr1[] = { 1, 2, 3 };
//int arr2[]{ 1, 2, 3 };
//int* p = new int{ 520 };
//double b = double{ 52.134 };//ͳһ�ĳ�ʼ����ʽ
//int* array = new int[3]{ 1,2,3 };


/*
�ۺ���
��ʼ���ۺ�����
*/
//struct T2
//{
//    int x;
//    long y;
//protected:
//    static int z;
//}t1{ 1, 100 };		// ok
// ��̬��Ա�ĳ�ʼ��
//int T2::z = 2;
//
//
//
//struct T3
//{
//    int x;
//    double y = 1.34;
//    int z[3]{ 1,2,3 };
//};
//
//int main(void)
//{
//    T3 t{ 520, 13.14, {6,7,8} };		// error, c++11��֧��,��c++14��ʼ��֧����
//    return 0;
//}
//


/*
�Ǿۺ���
*/


/*
�� C++ �� STL �����У����Խ������ⳤ�ȵ����ݵĳ�ʼ����ʹ�ó�ʼ���б�Ҳֻ�ܽ��й̶������ĳ�ʼ���������Ҫ������ STL һ�������ⳤ�ȳ�ʼ��������������ʹ�� std::initializer_list �������������ģ����ʵ�֡�

��������һ�������ģ���һЩ�ص㣺

����һ�����������������ͣ��ڲ������˵����� iterator ����������ĸ������ʱ�õ��ĵ�������ֻ���ġ�
���� std::initializer_list<T> ���ԣ������Խ������ⳤ�ȵĳ�ʼ���б�����Ҫ��Ԫ�ر�����ͬ������ T
�� std::initializer_list �ڲ���������Ա�ӿڣ�size(), begin(), end()��
std::initializer_list ����ֻ�ܱ������ʼ�����߸�ֵ��
3.1 ��Ϊ��ͨ��������
*/

