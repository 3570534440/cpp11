#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	string str = "D:\hello\world\test.txt";//��ʱ\t�ᱻ�����Ʊ��
	cout << str << endl;
	string str1 = "D:hello\\world\\test.txt";//��ʱ\t���ᵱ���Ʊ��
	cout << str1 << endl;
	string str2 = "<qwe>\
		<awdf>\
		<appok>\
		<���>\
		<ddddd>";
	cout << str2 << endl;

	//
	string str3 = R"(D:\hello\world\test.txt)";//��ʱ\t������ת���ַ�
	cout << str3 << endl;
	string str4 = R"(<qwe>
		<awdf>
		<appok>
		<���>
		<ddddd>)";//����ԭ�������ն����
	cout << str4 << endl;
	string str3 = R"hello(D:\hello\world\test.txt)hello";
	//R���˵��ַ�������һ����
	return 0;
}