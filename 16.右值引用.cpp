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

