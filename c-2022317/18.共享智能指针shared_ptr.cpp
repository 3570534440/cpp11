//在 C++ 中没有垃圾回收机制，必须自己释放分配的内存，否则就会造成内
//存泄露。解决这个问题最有效的方法是使用智能指针（smart pointer）。
//智能指针是存储指向动态分配（堆）对象指针的类，用于生存期的控制，能
//够确保在离开指针所在作用域时，自动地销毁动态分配的对象，防止内存泄露。
//智能指针的核心实现技术是引用计数，每使用它一次，内部引用计数加1，
//每析构一次内部的引用计数减1，减为0时，删除所指向的堆内存。
//C++11 中提供了三种智能指针，使用这些智能指针时需要引用头文件 <memory>：

//std::shared_ptr：共享的智能指针
//std::unique_ptr：独占的智能指针
//std::weak_ptr：弱引用的智能指针，它不共享指针，不能操作资源，是用来监视 shared_ptr 的。

// shared_ptr<T> 类模板中，提供了多种实用的构造函数, 语法格式如下:
//std::shared_ptr<T> 智能指针名字(创建堆内存);
#include <iostream>
#include <memory>
using namespace std;

int main()
{
    // 使用智能指针管理一块 int 型的堆内存
    shared_ptr<int> ptr1(new int(520));
    cout << "ptr1管理的内存引用计数: " << ptr1.use_count() << endl;
    // 使用智能指针管理一块字符数组对应的堆内存
    shared_ptr<char> ptr2(new char[12]);
    cout << "ptr2管理的内存引用计数: " << ptr2.use_count() << endl;
    // 创建智能指针对象, 不管理任何内存
    shared_ptr<int> ptr3;
    cout << "ptr3管理的内存引用计数: " << ptr3.use_count() << endl;
    // 创建智能指针对象, 初始化为空
    shared_ptr<int> ptr4(nullptr);
    cout << "ptr4管理的内存引用计数: " << ptr4.use_count() << endl;

    return 0;
//测试结果1 1 0 0
}
//如果智能指针被初始化了一块有效内存，那么这块内存的引用计数 + 1，
//如果智能指针没有被初始化或者被初始化为 nullptr 空指针，引用计数
//不会 + 1。另外，不要使用一个原始指针初始化多个 shared_ptr。
int* p = new int;
shared_ptr<int> p1(p);
shared_ptr<int> p2(p);		// error, 编译不会报错, 运行会出错

//当一个智能指针被初始化之后，就可以通过这个智能指针初始化其他新对象。
//在创建新对象的时候，对应的拷贝构造函数或者移动构造函数就被自动调用了。
#include <iostream>
#include <memory>
using namespace std;

int main()
{
    // 使用智能指针管理一块 int 型的堆内存, 内部引用计数为 1
    shared_ptr<int> ptr1(new int(520));
    cout << "ptr1管理的内存引用计数: " << ptr1.use_count() << endl;
    //调用拷贝构造函数
    shared_ptr<int> ptr2(ptr1);
    cout << "ptr2管理的内存引用计数: " << ptr2.use_count() << endl;
    shared_ptr<int> ptr3 = ptr1;
    cout << "ptr3管理的内存引用计数: " << ptr3.use_count() << endl;
    //调用移动构造函数
    shared_ptr<int> ptr4(std::move(ptr1));//move实现指针的转移
    cout << "ptr4管理的内存引用计数: " << ptr4.use_count() << endl;
    std::shared_ptr<int> ptr5 = std::move(ptr2);
    cout << "ptr5管理的内存引用计数: " << ptr5.use_count() << endl;

    return 0;
}//运行结果12333
// 通过 std::make_shared 初始化
//函数原型 
template< class T, class... Args >
shared_ptr<T> make_shared(Args&&... args);
using namespace std;

class Test
{
public:
    Test()
    {
        cout << "construct Test..." << endl;
    }
    Test(int x)
    {
        cout << "construct Test, x = " << x << endl;
    }
    Test(string str)
    {
        cout << "construct Test, str = " << str << endl;
    }
    ~Test()
    {
        cout << "destruct Test ..." << endl;
    }
};

int main()
{
    // 使用智能指针管理一块 int 型的堆内存, 内部引用计数为 1
    shared_ptr<int> ptr1 = make_shared<int>(520);
    cout << "ptr1管理的内存引用计数: " << ptr1.use_count() << endl;

    shared_ptr<Test> ptr2 = make_shared<Test>();
    cout << "ptr2管理的内存引用计数: " << ptr2.use_count() << endl;

    shared_ptr<Test> ptr3 = make_shared<Test>(520);
    cout << "ptr3管理的内存引用计数: " << ptr3.use_count() << endl;

    shared_ptr<Test> ptr4 = make_shared<Test>("我是要成为海贼王的男人!!!");
    cout << "ptr4管理的内存引用计数: " << ptr4.use_count() << endl;
    return 0;
}
//T是模板参数的数据类型

//通过reset的方式初始化
//函数原型
void reset() noexcept;

template< class Y >
void reset(Y* ptr);

template< class Y, class Deleter >
void reset(Y* ptr, Deleter d);

template< class Y, class Deleter, class Alloc >
void reset(Y* ptr, Deleter d, Alloc alloc);
//测试代码如下
#include <iostream>
#include <string>
#include <memory>
using namespace std;

int main()
{
    // 使用智能指针管理一块 int 型的堆内存, 内部引用计数为 1
    shared_ptr<int> ptr1 = make_shared<int>(520);
    shared_ptr<int> ptr2 = ptr1;
    shared_ptr<int> ptr3 = ptr1;
    shared_ptr<int> ptr4 = ptr1;
    cout << "ptr1管理的内存引用计数: " << ptr1.use_count() << endl;
    cout << "ptr2管理的内存引用计数: " << ptr2.use_count() << endl;
    cout << "ptr3管理的内存引用计数: " << ptr3.use_count() << endl;
    cout << "ptr4管理的内存引用计数: " << ptr4.use_count() << endl;

    ptr4.reset();
    cout << "ptr1管理的内存引用计数: " << ptr1.use_count() << endl;
    cout << "ptr2管理的内存引用计数: " << ptr2.use_count() << endl;
    cout << "ptr3管理的内存引用计数: " << ptr3.use_count() << endl;
    cout << "ptr4管理的内存引用计数: " << ptr4.use_count() << endl;

    shared_ptr<int> ptr5;
    ptr5.reset(new int(250));
    cout << "ptr5管理的内存引用计数: " << ptr5.use_count() << endl;

    return 0;
}

