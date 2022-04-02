//�� C++ ��û���������ջ��ƣ������Լ��ͷŷ�����ڴ棬����ͻ������
//��й¶����������������Ч�ķ�����ʹ������ָ�루smart pointer����
//����ָ���Ǵ洢ָ��̬���䣨�ѣ�����ָ����࣬���������ڵĿ��ƣ���
//��ȷ�����뿪ָ������������ʱ���Զ������ٶ�̬����Ķ��󣬷�ֹ�ڴ�й¶��
//����ָ��ĺ���ʵ�ּ��������ü�����ÿʹ����һ�Σ��ڲ����ü�����1��
//ÿ����һ���ڲ������ü�����1����Ϊ0ʱ��ɾ����ָ��Ķ��ڴ档
//C++11 ���ṩ����������ָ�룬ʹ����Щ����ָ��ʱ��Ҫ����ͷ�ļ� <memory>��

//std::shared_ptr�����������ָ��
//std::unique_ptr����ռ������ָ��
//std::weak_ptr�������õ�����ָ�룬��������ָ�룬���ܲ�����Դ������������ shared_ptr �ġ�

// shared_ptr<T> ��ģ���У��ṩ�˶���ʵ�õĹ��캯��, �﷨��ʽ����:
//std::shared_ptr<T> ����ָ������(�������ڴ�);
#include <iostream>
#include <memory>
using namespace std;

int main()
{
    // ʹ������ָ�����һ�� int �͵Ķ��ڴ�
    shared_ptr<int> ptr1(new int(520));
    cout << "ptr1������ڴ����ü���: " << ptr1.use_count() << endl;
    // ʹ������ָ�����һ���ַ������Ӧ�Ķ��ڴ�
    shared_ptr<char> ptr2(new char[12]);
    cout << "ptr2������ڴ����ü���: " << ptr2.use_count() << endl;
    // ��������ָ�����, �������κ��ڴ�
    shared_ptr<int> ptr3;
    cout << "ptr3������ڴ����ü���: " << ptr3.use_count() << endl;
    // ��������ָ�����, ��ʼ��Ϊ��
    shared_ptr<int> ptr4(nullptr);
    cout << "ptr4������ڴ����ü���: " << ptr4.use_count() << endl;

    return 0;
//���Խ��1 1 0 0
}
//�������ָ�뱻��ʼ����һ����Ч�ڴ棬��ô����ڴ�����ü��� + 1��
//�������ָ��û�б���ʼ�����߱���ʼ��Ϊ nullptr ��ָ�룬���ü���
//���� + 1�����⣬��Ҫʹ��һ��ԭʼָ���ʼ����� shared_ptr��
int* p = new int;
shared_ptr<int> p1(p);
shared_ptr<int> p2(p);		// error, ���벻�ᱨ��, ���л����

//��һ������ָ�뱻��ʼ��֮�󣬾Ϳ���ͨ���������ָ���ʼ�������¶���
//�ڴ����¶����ʱ�򣬶�Ӧ�Ŀ������캯�������ƶ����캯���ͱ��Զ������ˡ�
#include <iostream>
#include <memory>
using namespace std;

int main()
{
    // ʹ������ָ�����һ�� int �͵Ķ��ڴ�, �ڲ����ü���Ϊ 1
    shared_ptr<int> ptr1(new int(520));
    cout << "ptr1������ڴ����ü���: " << ptr1.use_count() << endl;
    //���ÿ������캯��
    shared_ptr<int> ptr2(ptr1);
    cout << "ptr2������ڴ����ü���: " << ptr2.use_count() << endl;
    shared_ptr<int> ptr3 = ptr1;
    cout << "ptr3������ڴ����ü���: " << ptr3.use_count() << endl;
    //�����ƶ����캯��
    shared_ptr<int> ptr4(std::move(ptr1));//moveʵ��ָ���ת��
    cout << "ptr4������ڴ����ü���: " << ptr4.use_count() << endl;
    std::shared_ptr<int> ptr5 = std::move(ptr2);
    cout << "ptr5������ڴ����ü���: " << ptr5.use_count() << endl;

    return 0;
}//���н��12333
// ͨ�� std::make_shared ��ʼ��
//����ԭ�� 
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
    // ʹ������ָ�����һ�� int �͵Ķ��ڴ�, �ڲ����ü���Ϊ 1
    shared_ptr<int> ptr1 = make_shared<int>(520);
    cout << "ptr1������ڴ����ü���: " << ptr1.use_count() << endl;

    shared_ptr<Test> ptr2 = make_shared<Test>();
    cout << "ptr2������ڴ����ü���: " << ptr2.use_count() << endl;

    shared_ptr<Test> ptr3 = make_shared<Test>(520);
    cout << "ptr3������ڴ����ü���: " << ptr3.use_count() << endl;

    shared_ptr<Test> ptr4 = make_shared<Test>("����Ҫ��Ϊ������������!!!");
    cout << "ptr4������ڴ����ü���: " << ptr4.use_count() << endl;
    return 0;
}
//T��ģ���������������

//ͨ��reset�ķ�ʽ��ʼ��
//����ԭ��
void reset() noexcept;

template< class Y >
void reset(Y* ptr);

template< class Y, class Deleter >
void reset(Y* ptr, Deleter d);

template< class Y, class Deleter, class Alloc >
void reset(Y* ptr, Deleter d, Alloc alloc);
//���Դ�������
#include <iostream>
#include <string>
#include <memory>
using namespace std;

int main()
{
    // ʹ������ָ�����һ�� int �͵Ķ��ڴ�, �ڲ����ü���Ϊ 1
    shared_ptr<int> ptr1 = make_shared<int>(520);
    shared_ptr<int> ptr2 = ptr1;
    shared_ptr<int> ptr3 = ptr1;
    shared_ptr<int> ptr4 = ptr1;
    cout << "ptr1������ڴ����ü���: " << ptr1.use_count() << endl;
    cout << "ptr2������ڴ����ü���: " << ptr2.use_count() << endl;
    cout << "ptr3������ڴ����ü���: " << ptr3.use_count() << endl;
    cout << "ptr4������ڴ����ü���: " << ptr4.use_count() << endl;

    ptr4.reset();
    cout << "ptr1������ڴ����ü���: " << ptr1.use_count() << endl;
    cout << "ptr2������ڴ����ü���: " << ptr2.use_count() << endl;
    cout << "ptr3������ڴ����ü���: " << ptr3.use_count() << endl;
    cout << "ptr4������ڴ����ü���: " << ptr4.use_count() << endl;

    shared_ptr<int> ptr5;
    ptr5.reset(new int(250));
    cout << "ptr5������ڴ����ü���: " << ptr5.use_count() << endl;

    return 0;
}
//ָ��ɾ����
//������ָ�������ڴ��Ӧ�����ü�����Ϊ 0 ��ʱ������ڴ�ͻᱻ����
//ָ���������ˡ����⣬�����ڳ�ʼ������ָ���ʱ��Ҳ�����Լ�ָ��ɾ��������
//���ɾ��������Ӧ�ĺ�������֮Ϊɾ���������ɾ��������������һ���ص���
//��������ֻ��Ҫ����ʵ�֣��������������ָ����ɵġ�


#include <iostream>
#include <memory>
using namespace std;

// �Զ���ɾ�����������ͷ�int���ڴ�
void deleteIntPtr(int* p)
{
    delete p;
    cout << "int ���ڴ汻�ͷ���...";
}

int main()
{
    shared_ptr<int> ptr(new int(250), deleteIntPtr);
    return 0;
}
//ɾ��������Ҳ������ lambda ���ʽ����˴���Ҳ����д������������
int main()
{
    shared_ptr<int> ptr(new int(250), [](int* p) {delete p; });
    return 0;
}
//��ɾ�������ڴ�ʱ�������Լ���дɾ������Ҳ����ʹ�� C++ �ṩ�� 
//std::default_delete<T>() ������Ϊɾ��������������ڲ���ɾ������
//Ҳ��ͨ������ delete ��ʵ�ֵģ�Ҫ�ͷ�ʲô���͵��ڴ�ͽ�ģ������ T 
// ָ��Ϊʲô���ͼ��ɡ����崦��������£�
//



//����ԭ��

int main()
{
    shared_ptr<int> ptr(new int[10], default_delete<int[]>());
    return 0;
}
//���⣬���ǻ������Լ���װһ�� make_shared_array �������� 
//shared_ptr ֧�����飬�������� :
#include <iostream>
#include <memory>
using namespace std;

template <typename T>
shared_ptr<T> make_share_array(size_t size)
{
    // ������������
    return shared_ptr<T>(new T[size], default_delete<T[]>());
}

int main()
{
    shared_ptr<int> ptr1 = make_share_array<int>(10);
    cout << ptr1.use_count() << endl;
    shared_ptr<char> ptr2 = make_share_array<char>(128);
    cout << ptr2.use_count() << endl;
    return 0;
}

