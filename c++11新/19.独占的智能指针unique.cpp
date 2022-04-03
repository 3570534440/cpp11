//std::unique_ptr ��һ����ռ�͵�����ָ�룬������������������
//ָ�빲�����ڲ���ָ�룬����ͨ�����Ĺ��캯����ʼ��һ����ռ��
//��ָ����󣬵��ǲ�����ͨ����ֵ��һ�� unique_ptr ��ֵ����һ
//�� unique_ptr��


// ͨ�����캯����ʼ������
unique_ptr<int> ptr1(new int(10));
// error, ������һ��unique_ptr��ֵ����һ��unique_ptr
unique_ptr<int> ptr2 = ptr1;
std::unique_ptr
//�������ƣ����ǿ���ͨ���������ظ������� std::unique_ptr��
//������ͨ�� std::move ��ת��������� std::unique_ptr������
//ԭʼָ�������Ȩ�ͱ�ת���ˣ����ԭʼָ�뻹�Ǳ���ռ�ġ�
#include <iostream>
#include <memory>
using namespace std;

unique_ptr<int> func()
{
    return unique_ptr<int>(new int(520));
}

int main()
{
    // ͨ�����캯����ʼ��
    unique_ptr<int> ptr1(new int(10));
    // ͨ��ת������Ȩ�ķ�ʽ��ʼ��
    unique_ptr<int> ptr2 = move(ptr1);
    unique_ptr<int> ptr3 = func();

    return 0;
}
void reset(pointer ptr = pointer()) noexcept;
//ʹ�� reset ���������� unique_ptr �����ԭʼ�ڴ�Ĺ���
//��Ҳ����������ʼ��һ����ռ������ָ�롣

int main()
{
    unique_ptr<int> ptr1(new int(10));
    unique_ptr<int> ptr2 = move(ptr1);

    ptr1.reset();
    ptr2.reset(new int(250));

    return 0;
}
ptr1.reset();// �����ԭʼ�ڴ�Ĺ���
ptr2.reset(new int(250));// ����ָ������ָ������ԭʼ�ڴ�


pointer get() const noexcept;
int main()
{
    unique_ptr<int> ptr1(new int(10));
    unique_ptr<int> ptr2 = move(ptr1);

    ptr2.reset(new int(250));
    cout << *ptr2.get() << endl;	// �õ��ڴ��ַ�д洢��ʵ����ֵ 250

    return 0;
}
