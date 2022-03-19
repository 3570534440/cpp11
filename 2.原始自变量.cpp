#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	string str = "D:\hello\world\test.txt";//此时\t会被当成制表符
	cout << str << endl;
	string str1 = "D:hello\\world\\test.txt";//这时\t不会当成制表符
	cout << str1 << endl;
	string str2 = "<qwe>\
		<awdf>\
		<appok>\
		<你好>\
		<ddddd>";
	cout << str2 << endl;

	//
	string str3 = R"(D:\hello\world\test.txt)";//此时\t不会变成转义字符
	cout << str3 << endl;
	string str4 = R"(<qwe>
		<awdf>
		<appok>
		<你好>
		<ddddd>)";//可以原样的在终端输出
	cout << str4 << endl;
	string str3 = R"hello(D:\hello\world\test.txt)hello";
	//R两端的字符必须是一样的
	return 0;
}