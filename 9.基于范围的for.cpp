/*
for (declaration : expressin)（声明，表达式）
{

}

*/
// #include <iostream>
// #include <vector>
// using namespace std;

// int main(void)
// {
//     vector<int> t{ 1,2,3,4,5,6 };
//     for (const auto &value : t)
//     {
//         cout << value << " ";
//     }
//     cout << endl;

//     string s = "hello";

//     for (char c : s) {
//         cout << c << endl;
//     }

//     return 0;
// }

/*结果
1 2 3 4 5 6
*/

//使用普通的 for 循环方式（基于迭代器）遍历关联性容器， auto 自动推导出的是一个迭代器类型，需要使用迭代器的方式取出元素中的键值对（和指针的操作方法相同）：
//it->first
//it->second
//使用基于访问的 for 循环遍历关联性容器，auto 自动推导出的类型是容器中的 value_type，相当于一个对组（std::pair）对象，提取键值对的方式如下：
//it.first
//it.second


/*
set容器读出来是只读的const类型

*/


#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 定义一个结构体
struct Student {
    string name;
    int score;
};

int main() {
    // 定义一个学生数组
    vector<Student> students = {
        {"Luffy", 85},
        {"Zoro", 92},
        {"Nami", 78},
        {"Sanji", 88}
    };

    // 遍历所有学生，给分数低于80分的人加5分补考机会
    for (Student& stu : students) { // 引用，能修改原数据
        if (stu.score < 80) {
            cout << stu.name << " 补考，加分！原分数: " << stu.score;
            stu.score += 5;
            cout << "，新分数: " << stu.score << endl;
        }
    }

    cout << "\n最终成绩单：" << endl;
    for (const Student& stu : students) { // 只读引用，提高性能
        cout << stu.name << ": " << stu.score << " 分" << endl;
    }

    cout << "\n-------\n";

    // 嵌套范围for：二维vector
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
/*

Nami 补考，加分！原分数: 78，新分数: 83

最终成绩单：
Luffy: 85 分
Zoro: 92 分
Nami: 83 分
Sanji: 88 分

-------
1 2 3 
4 5 6 
7 8 9 
*/