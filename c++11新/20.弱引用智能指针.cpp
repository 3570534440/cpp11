//C++11 中提供了三种智能指针，使用这些智能指针时需要引用头文件 ：

//std::shared_ptr：共享的智能指针
//std::unique_ptr：独占的智能指针
//std::weak_ptr：弱引用的智能指针，它不共享指针，不能操作资源，是用来监视 shared_ptr 的。
//弱引用智能指针 std::weak_ptr 可以看做是 shared_ptr 的助手，它不管理 shared_ptr 内部的指针。std::weak_ptr 没有重载操作符* 和->，因为它不共享指针，不能操作资源，所以它的构造不会增加引用计数，析构也不会减少引用计数，它的主要作用就是作为一个旁观者监视 shared_ptr 中管理的资源是否存在。

//1.1 初始化
// 默认构造函数
constexpr weak_ptr() noexcept;
// 拷贝构造
weak_ptr(const weak_ptr& x) noexcept;
template <class U> weak_ptr(const weak_ptr<U>& x) noexcept;
// 通过shared_ptr对象构造
template <class U> weak_ptr(const shared_ptr<U>& x) noexcept;

//使用方法
#include <iostream>
#include <memory>
using namespace std;

int main()
{
    shared_ptr<int> sp(new int);

    weak_ptr<int> wp1;
    weak_ptr<int> wp2(wp1);
    weak_ptr<int> wp3(sp);
    weak_ptr<int> wp4;
    wp4 = sp;
    weak_ptr<int> wp5;
    wp5 = wp3;

    return 0;
}



// 函数返回所监测的资源的引用计数
long int use_count() const noexcept;
#include <iostream>
#include <memory>
using namespace std;

int main()
{
    shared_ptr<int> sp(new int);

    weak_ptr<int> wp1;
    weak_ptr<int> wp2(wp1);
    weak_ptr<int> wp3(sp);
    weak_ptr<int> wp4;
    wp4 = sp;
    weak_ptr<int> wp5;
    wp5 = wp3;

    cout << "use_count: " << endl;
    cout << "wp1: " << wp1.use_count() << endl;
    cout << "wp2: " << wp2.use_count() << endl;
    cout << "wp3: " << wp3.use_count() << endl;
    cout << "wp4: " << wp4.use_count() << endl;
    cout << "wp5: " << wp5.use_count() << endl;
    return 0;
}

//通过调用 std::weak_ptr 类提供的 expired() 方法来判断观
//测的资源是否已经被释放，函数原型如下：

// 返回true表示资源已经被释放, 返回false表示资源没有被释放
bool expired() const noexcept;
//通过调用 std::weak_ptr 类提供的 lock() 方法来获取管理所
//监测资源的 shared_ptr 对象


//返回管理 this 的 shared_ptr
//如果在一个类中编写了一个函数，通过这个得到管理当前对象的共享智能指针，
//我们可能会写出如下代码

#include <iostream>
#include <memory>
using namespace std;

struct Test
{
    shared_ptr<Test> getSharedPtr()
    {
        return shared_ptr<Test>(this);
    }

    ~Test()
    {
        cout << "class Test is disstruct ..." << endl;
    }

};

int main()
{
    shared_ptr<Test> sp1(new Test);
    cout << "use_count: " << sp1.use_count() << endl;
    shared_ptr<Test> sp2 = sp1->getSharedPtr();
    cout << "use_count: " << sp1.use_count() << endl;
    return 0;
}
//过输出的结果可以看到一个对象被析构了两次，其原因是这i
//样的：在这个例子中使用同一个指针 this 构造了两个智能
//指针对象 sp1 和 sp2，这二者之间是没有任何关系的，因为
//sp2 并不是通过 sp1 初始化得到的实例对象。在离开作用域
//之后 this 将被构造的两个智能指针各自析构，导致重复析构的错误。
//
//这个问题可以通过 weak_ptr 来解决，通过 wek_ptr 返回管理 
//this 资源的共享智能指针对象 shared_ptr。C++11 中为我们提
//供了一个模板类叫做 std::enable_shared_from_this<T>，这个
//类中有一个方法叫做 shared_from_this()，通过这个方法可以返
//回一个共享智能指针，在函数的内部就是使用 weak_ptr 来监测 
//this 对象，并通过调用 weak_ptr 的 lock() 方法返回一个 
//shared_ptr 对象。
//

//修改代码如下
#include <iostream>
#include <memory>
using namespace std;

struct Test : public enable_shared_from_this<Test>
{
    shared_ptr<Test> getSharedPtr()
    {
        return shared_from_this();
    }
    ~Test()
    {
        cout << "class Test is disstruct ..." << endl;
    }
};

int main()
{
    shared_ptr<Test> sp1(new Test);
    cout << "use_count: " << sp1.use_count() << endl;
    shared_ptr<Test> sp2 = sp1->getSharedPtr();
    cout << "use_count: " << sp1.use_count() << endl;
    return 0;
}

//测试结果
//use_count: 1
//use_count : 2
//class Test is disstruct ...

//等等
