//std::unique_ptr 是一个独占型的智能指针，它不允许其他的智能
//指针共享其内部的指针，可以通过它的构造函数初始化一个独占智
//能指针对象，但是不允许通过赋值将一个 unique_ptr 赋值给另一
//个 unique_ptr。


// 通过构造函数初始化对象
unique_ptr<int> ptr1(new int(10));
// error, 不允许将一个unique_ptr赋值给另一个unique_ptr
unique_ptr<int> ptr2 = ptr1;
std::unique_ptr
//不允许复制，但是可以通过函数返回给其他的 std::unique_ptr，
//还可以通过 std::move 来转译给其他的 std::unique_ptr，这样
//原始指针的所有权就被转移了，这个原始指针还是被独占的。
#include <iostream>
#include <memory>
using namespace std;

unique_ptr<int> func()
{
    return unique_ptr<int>(new int(520));
}

int main()
{
    // 通过构造函数初始化
    unique_ptr<int> ptr1(new int(10));
    // 通过转移所有权的方式初始化
    unique_ptr<int> ptr2 = move(ptr1);
    unique_ptr<int> ptr3 = func();

    return 0;
}
void reset(pointer ptr = pointer()) noexcept;
//使用 reset 方法可以让 unique_ptr 解除对原始内存的管理
//，也可以用来初始化一个独占的智能指针。

int main()
{
    unique_ptr<int> ptr1(new int(10));
    unique_ptr<int> ptr2 = move(ptr1);

    ptr1.reset();
    ptr2.reset(new int(250));

    return 0;
}
ptr1.reset();// 解除对原始内存的管理
ptr2.reset(new int(250));// 重新指定智能指针管理的原始内存


pointer get() const noexcept;
int main()
{
    unique_ptr<int> ptr1(new int(10));
    unique_ptr<int> ptr2 = move(ptr1);

    ptr2.reset(new int(250));
    cout << *ptr2.get() << endl;	// 得到内存地址中存储的实际数值 250

    return 0;
}
