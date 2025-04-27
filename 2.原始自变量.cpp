#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	string str = "D:\\hello\\world\\test.txt"; // 反斜杠转义
	cout << str << endl;

	string str1 = "D:hello\\world\\test.txt"; // 反斜杠转义
	cout << str1 << endl;

	string str2 = R"(<qwe>
	<awdf>
	<appok>
	<你好>
	<ddddd>)"; // 用原始字符串
	cout << str2 << endl;

	string str3 = R"(D:\hello\world\test.txt)"; // 原始字符串，不需要转义
	cout << str3 << endl;

	string str4 = R"(<qwe>
	<awdf>
	<appok>
	<你好>
	<ddddd>)"; // 原样输出
	cout << str4 << endl;

	string str5 = R"hello(D:\hello\world\test.txt)hello"; // 自定义原始字符串
	cout << str5 << endl;

	return 0;
}
/*
执行结果:

D:\hello\world\test.txt
D:hello\world\test.txt
<qwe>
        <awdf>
        <appok>
        <你好>
        <ddddd>
D:\hello\world\test.txt
<qwe>
        <awdf>
        <appok>
        <你好>
        <ddddd>
D:\hello\world\test.txt


*/