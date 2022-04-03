//C++11 ���ṩ����������ָ�룬ʹ����Щ����ָ��ʱ��Ҫ����ͷ�ļ� ��

//std::shared_ptr�����������ָ��
//std::unique_ptr����ռ������ָ��
//std::weak_ptr�������õ�����ָ�룬��������ָ�룬���ܲ�����Դ������������ shared_ptr �ġ�
//����������ָ�� std::weak_ptr ���Կ����� shared_ptr �����֣��������� shared_ptr �ڲ���ָ�롣std::weak_ptr û�����ز�����* ��->����Ϊ��������ָ�룬���ܲ�����Դ���������Ĺ��첻���������ü���������Ҳ����������ü�����������Ҫ���þ�����Ϊһ���Թ��߼��� shared_ptr �й������Դ�Ƿ���ڡ�

//1.1 ��ʼ��
// Ĭ�Ϲ��캯��
constexpr weak_ptr() noexcept;
// ��������
weak_ptr(const weak_ptr& x) noexcept;
template <class U> weak_ptr(const weak_ptr<U>& x) noexcept;
// ͨ��shared_ptr������
template <class U> weak_ptr(const shared_ptr<U>& x) noexcept;

//ʹ�÷���
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



// ����������������Դ�����ü���
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

//ͨ������ std::weak_ptr ���ṩ�� expired() �������жϹ�
//�����Դ�Ƿ��Ѿ����ͷţ�����ԭ�����£�

// ����true��ʾ��Դ�Ѿ����ͷ�, ����false��ʾ��Դû�б��ͷ�
bool expired() const noexcept;
//ͨ������ std::weak_ptr ���ṩ�� lock() ��������ȡ������
//�����Դ�� shared_ptr ����


//���ع��� this �� shared_ptr
//�����һ�����б�д��һ��������ͨ������õ�����ǰ����Ĺ�������ָ�룬
//���ǿ��ܻ�д�����´���

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
//������Ľ�����Կ���һ���������������Σ���ԭ������i
//���ģ������������ʹ��ͬһ��ָ�� this ��������������
//ָ����� sp1 �� sp2�������֮����û���κι�ϵ�ģ���Ϊ
//sp2 ������ͨ�� sp1 ��ʼ���õ���ʵ���������뿪������
//֮�� this �����������������ָ����������������ظ������Ĵ���
//
//����������ͨ�� weak_ptr �������ͨ�� wek_ptr ���ع��� 
//this ��Դ�Ĺ�������ָ����� shared_ptr��C++11 ��Ϊ������
//����һ��ģ������� std::enable_shared_from_this<T>�����
//������һ���������� shared_from_this()��ͨ������������Է�
//��һ����������ָ�룬�ں������ڲ�����ʹ�� weak_ptr ����� 
//this ���󣬲�ͨ������ weak_ptr �� lock() ��������һ�� 
//shared_ptr ����
//

//�޸Ĵ�������
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

//���Խ��
//use_count: 1
//use_count : 2
//class Test is disstruct ...

//�ȵ�
