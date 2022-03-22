/*
for (declaration : expressin)
{

}

*/
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector<int> t{ 1,2,3,4,5,6 };
    for (const auto &value : t)
    {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
//使用普通的 for 循环方式（基于迭代器）遍历关联性容器， auto 自动推导出的是一个迭代器类型，需要使用迭代器的方式取出元素中的键值对（和指针的操作方法相同）：
//it->first
//it->second
//使用基于访问的 for 循环遍历关联性容器，auto 自动推导出的类型是容器中的 value_type，相当于一个对组（std::pair）对象，提取键值对的方式如下：
//it.first
//it.second


/*
set容器读出来是只读的const类型

*/