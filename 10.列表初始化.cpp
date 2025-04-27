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

//基本的初始化：
#include <iostream>
using namespace std;

int main() {
    int a{5};           // 初始化成5
    double d{3.14};     // 初始化成3.14
    int arr[3]{1, 2, 3}; // 数组列表初始化

    cout << "a: " << a << ", d: " << d << endl;
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
/*结果
a: 5, d: 3.14
1 2 3 
*/


#include <iostream>
#include <string>
using namespace std;

// 没有构造函数，只有public成员 -> 聚合体
struct Person {
    string name;
    int age;
};

int main() {
    Person p1{"Luffy", 19};  // 用列表初始化
    cout << p1.name << " is " << p1.age << " years old." << endl;

    Person p2{.name="Zoro", .age=21}; // C++20支持【指定成员初始化】
    cout << p2.name << " is " << p2.age << " years old." << endl;

    return 0;
}
/*结果
Luffy is 19 years old.
Zoro is 21 years old.
*/


//嵌套聚合体初始化
#include <iostream>
#include <string>
using namespace std;

struct Address {
    string city;
    string street;
};

struct Student {
    string name;
    int age;
    Address addr;
};

int main() {
    Student stu{"Nami", 18, {"Cocoyashi Village", "No. 1 Road"}};

    cout << stu.name << " (" << stu.age << " years old) "
         << "lives at " << stu.addr.city << ", " << stu.addr.street << endl;

    return 0;
}
/*结果
Nami (18 years old) lives at Cocoyashi Village, No. 1 Road

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

