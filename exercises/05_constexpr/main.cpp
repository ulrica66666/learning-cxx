#include "../exercise.h"

constexpr unsigned long long fibonacci(int i) {
    switch (i) {
        case 0:
            return 0;
        case 1:
            return 1;
        default:
            return fibonacci(i - 1) + fibonacci(i - 2);
    }
}

int main(int argc, char **argv) {
    constexpr auto FIB20 = fibonacci(20);
    ASSERT(FIB20 == 6765, "fibonacci(20) should be 6765");
    std::cout << "fibonacci(20) = " << FIB20 << std::endl;

    // 修改：将 ANS_N 和 ANS 的计算从 constexpr 改为运行期
    const int ANS_N = 90;
    const auto ANS = fibonacci(ANS_N); // 非 constexpr，运行期计算
    std::cout << "fibonacci(" << ANS_N << ") = " << ANS << std::endl;

    return 0;
}

