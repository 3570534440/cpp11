#include <iostream>
using namespace std;

// 定义第一个命名空间
namespace Pirate {
    void speak() {
        cout << "我是要成为海贼王的男人！" << endl;
    }
}

// 定义第二个命名空间
namespace Ninja {
    void speak() {
        cout << "我要成为最强的火影！" << endl;
    }
}

namespace OnePiece {
    namespace StrawHat {
        void captain() {
            cout << "路飞船长！" << endl;
        }
    }
}


int main() {
    // 调用Pirate命名空间的speak函数
    Pirate::speak();

    // 调用Ninja命名空间的speak函数
    Ninja::speak();
    //命名空间嵌套
    OnePiece::StrawHat::captain();

    namespace SH = OnePiece::StrawHat;
    SH::captain(); //别名

    return 0;
}
/*
我是要成为海贼王的男人！
我要成为最强的火影！
路飞船长！
路飞船长！
 */