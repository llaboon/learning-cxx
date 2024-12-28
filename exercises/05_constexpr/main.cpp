#include "../exercise.h"
#include <iostream>
using namespace std;
//unsigned long long a[30];
constexpr unsigned long long fibonacci(int i) {
    switch (i) {
        case 0:
            //a[0]=0;
            return 0;
        case 1:
            //a[1]=1;
            return 1;
        default:
            //constexpr unsigned long long ans=a[i-1]+a[i-2]
            return fibonacci(i-1)+fibonacci(i-2);
    }
}

int main(int argc, char **argv) {
    /*a[0]=0;
    a[1]=1;
    for(int i=2;i<30;i++)
        a[i]=a[i-1]+a[i-2];*/
    constexpr auto FIB20 = fibonacci(20);
    ASSERT(FIB20 == 6765, "fibonacci(20) should be 6765");
    std::cout << "fibonacci(20) = " << FIB20 << std::endl;
    //memset(a,0,sizeof(a));
    // TODO: 观察错误信息，修改一处，使代码编译运行
    // PS: 编译运行，但是不一定能算出结果……
    constexpr auto ANS_N = 9;
    constexpr auto ANS = fibonacci(ANS_N);
    std::cout << "fibonacci(" << ANS_N << ") = " << ANS << std::endl;

    return 0;
}
