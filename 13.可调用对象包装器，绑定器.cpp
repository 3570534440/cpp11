//�ʼ�ת��
//����: �ձ��X
//���� : https://subingwen.cn/cpp/bind/#3-%E7%BB%91%E5%AE%9A%E5%99%A8
//��Դ: ����̵Ĵ��
//
//


#include <iostream>
#include <vector>
using namespace std;
//�� C++ �д��� ���ɵ��ö��� ��ôһ�����׼ȷ��˵���ɵ��ö��������¼��ֶ��壺

int print(int a, double b)
{
    cout << a << b << endl;
    return 0;
}
// ���庯��ָ��
int (*func)(int, double) = &print;

//��һ������operator()��Ա����������󣨷º�����
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Test
{
    // ()����������
    void operator()(string msg)
    {
        cout << "msg: " << msg << endl;
    }
};

int main(void)
{
    Test t;
    t("����Ҫ��Ϊ������������!!!");	// �º���
    return 0;
}
//��һ���ɱ�ת��Ϊ����ָ��������
#include <iostream>
#include <string>
#include <vector>
using namespace std;

using func_ptr = void(*)(int, string);
struct Test
{
    static void print(int a, string b)
    {
        cout << "name: " << b << ", age: " << a << endl;
    }

    // �������ת��Ϊ����ָ��
    operator func_ptr()
    {
        return print;
    }
};

int main(void)
{
    Test t;
    // ����ת��Ϊ����ָ��, ������
    t(19, "Monkey D. Luffy");

    return 0;
}

//��һ�����Ա����ָ��������Աָ��

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Test
{
    void print(int a, string b)
    {
        cout << "name: " << b << ", age: " << a << endl;
    }
    int m_num;
};

int main(void)
{
    // �������Ա����ָ��ָ�����Ա����
    void (Test:: * func_ptr)(int, string) = &Test::print;
    // ���Աָ��ָ�����Ա����
    int Test::* obj_ptr = &Test::m_num;

    Test t;
    // ͨ�����Ա����ָ��������Ա����
    (t.*func_ptr)(19, "Monkey D. Luffy");
    // ͨ�����Աָ���ʼ�����Ա����
    t.*obj_ptr = 1;
    cout << "number is: " << t.m_num << endl;

    return 0;
}


//std::function�ǿɵ��ö���İ�װ��������һ����ģ�壬�������ɳ������Ա��������ָ��֮������пɵ��ö���ͨ��ָ������ģ���������������ͳһ�ķ�ʽ���������������󡢺���ָ�룬����������ӳ�ִ�����ǡ�

//#include <functional>
//std::function<����ֵ����(���������б�)> diy_name = �ɵ��ö���;



#include <iostream>
#include <functional>
using namespace std;

int add(int a, int b)
{
    cout << a << " + " << b << " = " << a + b << endl;
    return a + b;
}

class T1
{
public:
    static int sub(int a, int b)
    {
        cout << a << " - " << b << " = " << a - b << endl;
        return a - b;
    }
};

class T2
{
public:
    int operator()(int a, int b)
    {
        cout << a << " * " << b << " = " << a * b << endl;
        return a * b;
    }
};

int main(void)
{
    // ��һ����ͨ����
    function<int(int, int)> f1 = add;
    // ���Ծ�̬���Ա����
    function<int(int, int)> f2 = T1::sub;
    // ��һ���º���
    T2 t;
    function<int(int, int)> f3 = t;

    // ��������
    f1(9, 3);
    f2(9, 3);
    f3(9, 3);

    return 0;
}


//2.2 ��Ϊ�ص�����ʹ��
//��Ϊ�ص������������ͨ������ָ��ʵ�ֵģ�ʹ�ö����װ������ȡ������ָ������ã�����һ����������ӣ�
//

#include <iostream>
#include <functional>
using namespace std;

class A
{
public:
    // ���캯��������һ����װ������
    A(const function<void()>& f) : callback(f)
    {
    }

    void notify()
    {
        callback(); // ����ͨ�����캯���õ��ĺ���ָ��
    }
private:
    function<void()> callback;
};

class B
{
public:
    void operator()()
    {
        cout << "����Ҫ��Ϊ������������!!!" << endl;
    }
};
int main(void)
{
    B b;
    A a(b); // �º���ͨ����װ��������а�װ
    a.notify();

    return 0;
}
//
//ͨ����������ӿ��Կ�����ʹ�ö����װ�� std::function ���Էǳ�����Ľ��º���ת��Ϊһ������ָ��
// ��ͨ�����к���ָ��Ĵ��ݣ������������ĺ��ʵ�λ�þͿ��Ե��������װ�õķº����ˡ�
//
//���⣬ʹ�� std::function ��Ϊ�����Ĵ�����������Խ����巽ʽ����ͬ�Ŀɵ��ö������ͳһ
// �Ĵ��ݣ�������������˳��������ԡ�
//
//
//3. ����
//std::bind�������ɵ��ö����������һ����а󶨡��󶨺�Ľ������ʹ��std::function���б��棬���ӳٵ��õ��κ�������Ҫ��ʱ��ͨ������������Ҫ���������ã�
//
//���ɵ��ö����������һ��󶨳�һ���º�����
//����Ԫ����������Ϊn��n > 1���ɵ��ö���ת��ΪһԪ���ߣ�n - 1��Ԫ�ɵ��ö��󣬼�ֻ�󶨲��ֲ�����

// �󶨷����Ա����/����
auto f = std::bind(�ɵ��ö����ַ, �󶨵Ĳ��� / ռλ��);
// �����Ա��/����
auto f = std::bind(�ຯ�� / ��Ա��ַ, ��ʵ�������ַ, �󶨵Ĳ��� / ռλ��);


#include <iostream>
#include <functional>
using namespace std;

void callFunc(int x, const function<void(int)>& f)
{
    if (x % 2 == 0)
    {
        f(x);
    }
}

void output(int x)
{
    cout << x << " ";
}

void output_add(int x)
{
    cout << x + 10 << " ";
}

int main(void)
{
    // ʹ�ð����󶨿ɵ��ö���Ͳ���
    auto f1 = bind(output, placeholders::_1);
    for (int i = 0; i < 10; ++i)
    {
        callFunc(i, f1);
    }
    cout << endl;

    auto f2 = bind(output_add, placeholders::_1);
    for (int i = 0; i < 10; ++i)
    {
        callFunc(i, f2);
    }
    cout << endl;

    return 0;
}
//������ĳ����У�ʹ���� std::bind �������ں����ⲿͨ���󶨲�
// ͬ�ĺ��������������ִ�еĽ����std::bind�������ص���һ����
// �������ͣ��õ��ķ���ֵ����ֱ�Ӹ�ֵ��һ��std::function����ʹ��
// ��ʱ�����ǲ�����Ҫ���İ����ķ���ֵ���ͣ�ʹ��auto�����Զ������Ƶ��Ϳ����ˡ�
//
//placeholders::_1 ��һ��ռλ�����������λ�ý��ں�������ʱ������
// �ĵ�һ�������������ͬ������������ռλ�� placeholders::_
// 2��placeholders::_3��placeholders::_4��placeholders::_5 �ȡ���
//
//����ռλ���ĸ���֮��ʹ�� std::bind ��ʹ�ñ�÷ǳ���� :

#include <iostream>
#include <functional>
using namespace std;

void output(int x, int y)
{
    cout << x << " " << y << endl;
}

int main(void)
{
    // ʹ�ð����󶨿ɵ��ö���Ͳ���, �����õõ��ķº���
    bind(output, 1, 2)();
    bind(output, placeholders::_1, 2)(10);
    bind(output, 2, placeholders::_1)(10);

    // error, ����ʱû�еڶ�������
    // bind(output, 2, placeholders::_2)(10);
    // ����ʱ��һ������10���̵��ˣ�û�б�ʹ��
    bind(output, 2, placeholders::_2)(10, 20);

    bind(output, placeholders::_1, placeholders::_2)(10, 20);
    bind(output, placeholders::_2, placeholders::_1)(10, 20);


    return 0;
}




