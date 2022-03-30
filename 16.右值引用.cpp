//左值可以取地址
//右值不可以取地址

//引用不占用内存空间
//左值，左值引用，右值，右值引用
//常量左值引用，常量右引用

//延长内存存活的时间

//右值引用就是对一个右值进行引用的类型。因为右值是匿名的，所以我们只能通过引用的方式找到它。
//无论声明左值引用还是右值引用都必须立即进行初始化，因为引用类型本身并不拥有所绑定对象的内存
//只是该对象的一个别名。通过右值引用的声明，该右值又“重获新生”，其生命周期与右值引用类型变
//量的生命周期一样，只要该变量还活着，该右值临时量将会一直存活下去。

#include <iostream>
using namespace std;

int&& value = 520;
class Test
{
public:
    Test()
    {
        cout << "construct: my name is jerry" << endl;
    }
    Test(const Test& a)
    {
        cout << "copy construct: my name is tom" << endl;
    }
};

Test getObj()
{
    return Test();
}

int main()
{
    int a1;
    int &&a2 = a1;        // error
    Test& t = getObj();   // error
    Test && t = getObj();
    const Test& t = getObj();
    return 0;
}

//在上面的例子中 int&& value = 520; 里面 520 是纯右值，value 是对字面量 520 这个右值的引用。

//在 int &&a2 = a1; 中 a1 虽然写在了 = 右边，但是它仍然是一个左值，使用左值初始化一个右值引用类型是不合法的。

//在 Test& t = getObj() 这句代码中语法是错误的，右值不能给普通的左值引用赋值。

//在 Test && t = getObj(); 中 getObj() 返回的临时对象被称之为将亡值，t 是这个将亡值的右值引用。

//const Test& t = getObj() 这句代码的语法是正确的，常量左值引用是一个万能引用类型，它可以接受左值、右值、常量左值和常量右值。

//优化
#include <iostream>
using namespace std;

class Test
{
public:
    Test() : m_num(new int(100))
    {
        cout << "construct: my name is jerry" << endl;
    }

    Test(const Test& a) : m_num(new int(*a.m_num))
    {
        cout << "copy construct: my name is tom" << endl;
    }

    // 添加移动构造函数
    Test(Test&& a) : m_num(a.m_num)
    //内存资源的转移/右值引用了a.num所指的值，
    //m_num指向了a.m_num指向的内存空间，这样这块内存被释放时，可以延长内存存活时间
    //构造一个匿名对象和引用一个匿名对象需要花费大量时间，如果这个类的匿名对象很大的话
    //拷贝构造时会浪费时间和内存，拷贝完之后会释放资源，这时右值引用会延长这段内存的
    //存活时间，还可以直接引用这段内存，少了拷贝构造
    {
        a.m_num = nullptr;//释放内存时，释放了一个空内存
        cout << "move construct: my name is sunny" << endl;
    }

    ~Test()
    {
        delete m_num;
        cout << "destruct Test class ..." << endl;
    }

    int* m_num;
};

Test getObj()
{
    Test t;
    return t;
}

int main()
{
    Test t = getObj();
    cout << "t.m_num: " << *t.m_num << endl;
    return 0;
};


int&& a1 = 5;
auto&& bb = a1;
auto&& bb1 = 5;

int a2 = 5;
int &a3 = a2;
auto&& cc = a3;
auto&& cc1 = a2;

const int& s1 = 100;
const int&& s2 = 100;
auto&& dd = s1;
auto&& ee = s2;

const auto&& x = 5;
//第 2 行：a1 为右值引用，推导出的 bb 为左值引用类型
//第 3 行：5 为右值，推导出的 bb1 为右值引用类型
//第 7 行：a3 为左值引用，推导出的 cc 为左值引用类型
//第 8 行：a2 为左值，推导出的 cc1 为左值引用类型
//第 12 行：s1 为常量左值引用，推导出的 dd 为常量左值引用类型
//第 13 行：s2 为常量右值引用，推导出的 ee 为常量左值引用类型
//第 15 行：x 为右值引用，不需要推导，只能通过右值初始化



void printValue(int &i)
{
    cout << "l-value: " << i << endl;
}

void printValue(int &&i)
{
    cout << "r-value: " << i << endl;
}

void forward(int &&k)
{
    printValue(k);
}

int main()
{
    int i = 520;
    printValue(i);
    printValue(1314);
    forward(250);

    return 0;
};
//结果如下
//l-value: 520
//l-value: 1314
//l-value: 250

