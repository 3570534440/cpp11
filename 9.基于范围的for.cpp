/*
for (declaration : expressin)
{

}

*/
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector<int> t{ 1,2,3,4,5,6 };
    for (const auto &value : t)
    {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
//ʹ����ͨ�� for ѭ����ʽ�����ڵ����������������������� auto �Զ��Ƶ�������һ�����������ͣ���Ҫʹ�õ������ķ�ʽȡ��Ԫ���еļ�ֵ�ԣ���ָ��Ĳ���������ͬ����
//it->first
//it->second
//ʹ�û��ڷ��ʵ� for ѭ������������������auto �Զ��Ƶ����������������е� value_type���൱��һ�����飨std::pair��������ȡ��ֵ�Եķ�ʽ���£�
//it.first
//it.second


/*
set������������ֻ����const����

*/