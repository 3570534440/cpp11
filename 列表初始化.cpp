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
//double b = double{ 52.134 };//统一的初始化方式
//int* array = new int[3]{ 1,2,3 };


/*
聚合体
初始化聚合类型
*/
//struct T2
//{
//    int x;
//    long y;
//protected:
//    static int z;
//}t1{ 1, 100 };		// ok
// 静态成员的初始化
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
//    T3 t{ 520, 13.14, {6,7,8} };		// error, c++11不支持,从c++14开始就支持了
//    return 0;
//}
//


/*
非聚合类
*/


/*
在 C++ 的 STL 容器中，可以进行任意长度的数据的初始化，使用初始化列表也只能进行固定参数的初始化，如果想要做到和 STL 一样有任意长度初始化的能力，可以使用 std::initializer_list 这个轻量级的类模板来实现。

先来介绍一下这个类模板的一些特点：

它是一个轻量级的容器类型，内部定义了迭代器 iterator 等容器必须的概念，遍历时得到的迭代器是只读的。
对于 std::initializer_list<T> 而言，它可以接收任意长度的初始化列表，但是要求元素必须是同种类型 T
在 std::initializer_list 内部有三个成员接口：size(), begin(), end()。
std::initializer_list 对象只能被整体初始化或者赋值。
3.1 作为普通函数参数
*/

