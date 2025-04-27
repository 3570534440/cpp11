#include <iostream>
#include <map>
#include <string>

using namespace std;
 // using 比 typedef更好
// int main()
// {
// // 使用typedef定义函数指针
// typedef int(*func_ptr)(int, double);

// // 使用using定义函数指针
// using func_ptr1 = int(*)(int, double);

// 	return 0;
// }

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


 using 来为一个模板定义别名，对于上面的需求可以写成这样：
*/

// 给 map<int, T> 起个别名
template <typename T>
using mymap = map<int, T>;

int main(void)
{
    // map 的 value 为 string
    mymap<string> m;
    m.insert(make_pair(1, "luffy"));
    m.insert(make_pair(2, "ace"));

    for (const auto &pair : m)
    {
        cout << pair.first << ": " << pair.second << endl;
    }

    // map 的 value 为 int
    mymap<int> m1;
    m1.insert(make_pair(1, 100)); // ❗需要使用 make_pair 或 pair<int, int>
    m1.insert(make_pair(2, 200));

    for (const auto &pair : m1)
    {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}

/*结果
1: luffy
2: ace
1: 100
2: 200
*/