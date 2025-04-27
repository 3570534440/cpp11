#include<iostream>
#include <string>
using namespace std;

// template <typename T,typename U>//模板函数
// auto add(T t, U u);
// {
// 	return t + u;
// }
// //auto可自动推导返回值类型，这样可以少写一种返回类型
// //-------------------------------------------------

// #include <iostream>
// using namespace std;
// // R->返回值类型, T->参数1类型, U->参数2类型
// template <typename R, typename T, typename U>
// R add(T t, U u)
// {
//     return t + u;
// }

// int main()
// {
//     int x = 520;
//     double y = 13.14;
//     // auto z = add<decltype(x + y), int, double>(x, y);
//     auto z = add<decltype(x + y)>(x, y);	// 简化之后的写法
//     cout << "z: " << z << endl;
//     return 0;
// }

/*
执行结果：z: 533.14
*/

// template <typename T, typename U>//简化后的模板函数
// auto z = add(x, y);//简化版，此时用到返回值后置


// //-------------------------------------------------

//返回值后置语法
#include <iostream>
using namespace std;

template <typename T, typename U>
// 返回类型后置语法
auto add(T t, U u) -> decltype(t+u) //返回值后置
{
    return t + u;
}

int main()
{
    int x = 520;
    double y = 13.14;
    // auto z = add<int, double>(x, y);
    auto z = add(x, y);		// 简化之后的写法
    cout << "z: " << z << endl;
    return 0;
}
/*执行结果
z: 533.14
*/
