//lambda ���ʽ�� C++11 ����ҪҲ����õ�����֮һ�������ִ�������Ե�һ���ص㣬lambda ���ʽ�����µ�һЩ�ŵ㣺
//
//����ʽ�ı�̷�񣺾͵���������Ŀ�꺯���������󣬲���Ҫ����дһ������������������
//��ࣺ�����˴������ͺ͹��ܷ�ɢ���ÿ������Ӹ�Ч��
//����Ҫ��ʱ��͵ص�ʵ�ֹ��ܱհ���ʹ����������
//

//[capture](params) opt->ret{ body; };

//���� capture �ǲ����б�params �ǲ����б�opt �Ǻ���ѡ�ret �Ƿ���ֵ���ͣ�body �Ǻ����塣

//�����б�[]: ����һ����Χ�ڵı���
//
//�����б�() : ����ͨ�����Ĳ����б�һ�������û�в��������б����ʡ�Բ�д��
//
//auto f = []() {return 1; }	// û�в���, �����б�Ϊ��
//auto f = [] {return 1; }		// û�в���, �����б�ʡ�Բ�д
//opt ѡ� ����Ҫ����ʡ��
//
//mutable: �����޸İ�ֵ���ݽ����Ŀ�����ע�������޸Ŀ�����������ֵ����
//exception : ָ�������׳����쳣�����׳��������͵��쳣������ʹ�� throw ();


/*

[] - ����׽�κα���
[&] - �����ⲿ�����������б���������Ϊ�����ں�������ʹ��(�����ò���)
[=] - �����ⲿ�����������б���������Ϊ�����ں�������ʹ��(��ֵ����)
�����ĸ����������������ڲ���ֻ����
[=, &foo] - ��ֵ�����ⲿ�����������б��������������ò����ⲿ���� foo
[bar] - ��ֵ���� bar ������ͬʱ��������������
[&bar] - �����ò��� bar ������ͬʱ��������������
[this] - ����ǰ���е� this ָ��
�� lambda ���ʽӵ�к͵�ǰ���Ա����ͬ���ķ���Ȩ��
����Ѿ�ʹ���� & ���� =, Ĭ����Ӵ�ѡ��

*/
#include <iostream>
#include <functional>
using namespace std;

class Test
{
public:
    void output(int x, int y)
    {
        auto x1 = [] {return m_number; };                      // error
        auto x2 = [=] {return m_number + x + y; };        //copy���е��ⲿ����     // ok
        auto x3 = [&] {return m_number + x + y; };             // ok
        auto x4 = [this] {return m_number; };                  // ok
        auto x5 = [this] {return m_number + x + y; };          // error
        auto x6 = [this, x, y] {return m_number + x + y; };    // ok
        auto x7 = [this] {return m_number++; };                // ok
    }
    int m_number = 100;
};
// = copy�����ı�����ֻ���Ĳ���++�������ɶ�����д
// & ����ʹ��&�����ô��ݲ������ı����
int main(void)
{
    int a = 10, b = 20;
    auto f1 = [] {return a; };                        // error
    auto f2 = [&] {return a++; };                     // ok
    auto f3 = [=] {return a; };                       // ok
    auto f4 = [=] {return a++; };    //ֻ���ı���a                 // error
    auto f5 = [a] {return a + b; };  //û�в������b                 // error
    auto f6 = [a, &b] {return a + (b++); };           // ok
    auto f7 = [=, &b] {return a + (b++); };           // ok

    return 0;
}
// ������lambda���ʽ����
auto f = [](int a) -> int
{
    return a + 10;
};

// ���Է���ֵ��lambda���ʽ����
auto f = [](int a)
{
    return a + 10;
};

// ok�������Զ��Ƶ�������ֵ����
auto f = [](int i)
{
    return i;
}

// error�������Ƶ�������ֵ����
auto f1 = []()
{
    return { 1, 2 };	// �����б��ʼ���Ƶ�����ֵ������
}
//lambda���ʽ��������C++11�лᱻ������һ����operator()���࣬���º�����
//����C++��׼��lambda���ʽ��operator()Ĭ����const�ģ�һ��const��Ա�������޷��޸ĳ�Ա����ֵ�ġ�
//mutable ѡ������þ�����ȡ�� operator () �� const ���ԡ�
//
//��Ϊ lambda ���ʽ�� C++ �лᱻ������һ���º�����
//��˿���ʹ��std::function��std::bind���洢�Ͳ���lambda���ʽ��
//

#include <iostream>
#include <functional>
using namespace std;

int main(void)
{
    // ��װ�ɵ��ú���
    std::function<int(int)> f1 = [](int a) {return a; };
    // �󶨿ɵ��ú���
    std::function<int(int)> f2 = bind([](int a) {return a; }, placeholders::_1);

    //��������������������ߴ���Ŀɶ��ԣ���߿���Ч�ʣ�
    // �󶨻��װ����֮�����ʹ�����Ĳ������٣���Ԫ����
    // ��������
    cout << f1(100) << endl;
    cout << f2(200) << endl;
    return 0;
}



