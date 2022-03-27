//std::bind�������ɵ��ö����������һ����а󶨡��󶨺�Ľ������ʹ��std::function���б��棬
//���ӳٵ��õ��κ�������Ҫ��ʱ��ͨ������������Ҫ���������ã�

//���ɵ��ö����������һ��󶨳�һ���º�����
//����Ԫ����������Ϊn��n > 1���ɵ��ö���ת��ΪһԪ���ߣ�n - 1��Ԫ�ɵ��ö��󣬼�ֻ�󶨲��ֲ�����


// �󶨷����Ա����/����
//auto f = std::bind(�ɵ��ö����ַ, �󶨵Ĳ��� / ռλ��);
// �����Ա��/����
//auto f = std::bind(�ຯ�� / ��Ա��ַ, ��ʵ�������ַ, �󶨵Ĳ��� / ռλ��);

#include <iostream>
#include <functional>
using namespace std;

void callFunc(int x, const function<void(int)>& f)
//��callFunc(i, f1);���Ӧ
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
        callFunc(i, f1);//placeholders::_1ռλ������Ӧ��һ������i
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


//����ĳ�Ա����
//placeholders::_1 ��һ��ռλ�����������λ�ý��ں�������ʱ������ĵ�һ��
//�����������ͬ������������ռλ�� placeholders::_2��placeholders::_3��
//placeholders::_4��placeholders::_5 �ȡ���

//����ռλ���ĸ���֮��ʹ�� std::bind ��ʹ�ñ�÷ǳ���� :

void output(int x, int y)
{
    cout << x << " " << y << endl;
}

//int main(void)
//{
//    // ʹ�ð����󶨿ɵ��ö���Ͳ���, �����õõ��ķº���
//    bind(output, 1, 2)();
//    bind(output, placeholders::_1, 2)(10);
//    bind(output, 2, placeholders::_1)(10);
//
// 
//    // error, ����ʱû�еڶ�������
//    // bind(output, 2, placeholders::_2)(10);
//    // ����ʱ��һ������10���̵��ˣ�û�б�ʹ��
//    bind(output, 2, placeholders::_2)(10, 20);
//
//    bind(output, placeholders::_1, placeholders::_2)(10, 20);
//    bind(output, placeholders::_2, placeholders::_1)(10, 20);
//
//
//    return 0;
//   
//}
//


//����ĳ�Ա����
//�Ͱ���ĳ�Ա����

class Test
{
public:
    void output(int x, int y)
    {
        cout << "x: " << x << ", y: " << y << endl;
    }
    int m_number = 100;
};

int main(void)
{
    Test t;
    // �����Ա����
    function<void(int, int)> f1 =
        bind(&Test::output, &t, placeholders::_1, placeholders::_2);
    // �����Ա����(����)
    function<int& (void)> f2 = bind(&Test::m_number, &t);

    // ����
    f1(520, 1314);
    f2() = 2333;
    cout << "t.m_number: " << t.m_number << endl;

    return 0;
}









