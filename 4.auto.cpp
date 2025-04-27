
// auto可以在声明变量的时候根据变量初始值的类型自动为此变量选择匹配的类型
//使用auto关键字做类型自动推导时，依次施加一下规则：如果初始化表达式是引用，则去除引用语义。

//😂  也可以用  decltype
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int main() {
    // 1. auto推导基本类型
    auto x = 10;       // x是int
    auto y = 3.14;     // y是double
    auto name = "Luffy"; // name是const char*

    cout << "x: " << x << ", y: " << y << ", name: " << name << endl;

    // 2. auto推导容器类型
    vector<int> nums = {1, 2, 3, 4, 5};
    for (auto it = nums.begin(); it != nums.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // 3. auto搭配范围for
    for (auto n : nums) {
        cout << n << " ";
    }
    cout << endl;

    // 4. auto推导复杂类型（pair）
    map<string, int> score = {{"Luffy", 90}, {"Zoro", 85}, {"Nami", 95}};
    for (auto& [key, value] : score) {  // C++17结构化绑定
        cout << key << ": " << value << endl;
    }

    // 5. auto推导函数返回值
    auto result = add(5, 7); // result是int
    cout << "5 + 7 = " << result << endl;

    // 6. auto推导引用
    int a = 100;
    auto& ref = a; // ref是int的引用
    ref = 200;
    cout << "a after ref modification: " << a << endl;

    // 7. auto推导const引用
    const int b = 500;
    auto c = b;      // c是int（b的值拷贝过来，去掉const）
    auto& cref = b;  // cref是const int&，保持常量引用

    cout << "c: " << c << ", cref: " << cref << endl;

    return 0;
}
/*执行结果
x: 10, y: 3.14, name: Luffy
1 2 3 4 5 
1 2 3 4 5 
Luffy: 90
Nami: 95
Zoro: 85
5 + 7 = 12
a after ref modification: 200
c: 500, cref: 500
*/


// //返回值后置语法
// #include <iostream>
// using namespace std;

// template <typename T, typename U>
// // 返回类型后置语法
// auto add(T t, U u) -> decltype(t+u) //返回值后置
// {
//     return t + u;
// }

// int main()
// {
//     int x = 520;
//     double y = 13.14;
//     // auto z = add<int, double>(x, y);
//     auto z = add(x, y);		// 简化之后的写法
//     cout << "z: " << z << endl;
//     return 0;
// }
// /*执行结果
// z: 533.14
// */

