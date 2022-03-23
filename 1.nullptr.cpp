//c++笔记

//笔记转载
//作者: 苏丙榅
//链接 : https://subingwen.cn/cpp/bind/#3-%E7%BB%91%E5%AE%9A%E5%99%A8
//来源: 爱编程的大丙
//

#include<iostream>
#include <string>
using namespace std;
//# define NULL ((vold *)0)//NULL其实是（void*）0
int main(int argc, char* argv[])
{
	//在c++中建议将所有的NULL写成nullptr;
}
//c++中NULL定义如下：
/* Define NULL pointer value */
#ifndef NULL
    #ifdef __cplusplus
        #define NULL    0
    #else  /* __cplusplus */
        #define NULL    ((void *)0)
    #endif  /* __cplusplus */
#endif  /* NULL */
/*
在C++中，NULL被定义为0，而不是(void*)0，为什么C++在NULL的定义上不继续兼容C延续
(void*)0的定义呢？因为C++中不能将void*类型的指针隐式转换成其他指针类型，所以将NULL
定义为(void*)0的话并不能起到空指针的作用

int main() {
    void* a = (void*) 0;
    char* b = a;     //在C中可以，C++不行
    return 0;
}

*/