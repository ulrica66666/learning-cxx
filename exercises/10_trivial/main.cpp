#include "../exercise.h"

// READ: Trivial type <https://learn.microsoft.com/zh-cn/cpp/cpp/trivial-standard-layout-and-pod-types?view=msvc-170>

struct FibonacciCache {
    unsigned long long cache[16];
    int cached;
};

// TODO: 实现正确的缓存优化斐波那契计算
// static unsigned long long fibonacci(FibonacciCache &cache, int i) {
//     int j=cache.cached;
//     for (; j<=i; ++j) {
//         cache.cache[j] = cache.cache[j - 1] + cache.cache[j- 2];
//     }
//     return cache.cache[i];
// }
// 计算斐波那契数列，利用缓存来加速计算
static unsigned long long fibonacci(FibonacciCache &cache, int i) {
    if (i <= 1) {
        return i;  // 斐波那契数列的前两个项是 0 和 1
    }

    // 如果缓存中没有计算过第 i 项，则进行计算并缓存
    if (cache.cached <= i) {
        for (int j = cache.cached; j <= i; ++j) {
            if (j == 0) {
                cache.cache[j] = 0;  // F(0) = 0
            } else if (j == 1) {
                cache.cache[j] = 1;  // F(1) = 1
            } else {
                cache.cache[j] = cache.cache[j - 1] + cache.cache[j - 2];  // F(n) = F(n-1) + F(n-2)
            }
        }
        cache.cached = i + 1;  // 更新已缓存的项数
    }
    
    return cache.cache[i];  // 返回第 i 项的斐波那契数
}

int main(int argc, char **argv) {
    // TODO: 初始化缓存结构体，使计算正确
    // NOTICE: C/C++ 中，读取未初始化的变量（包括结构体变量）是未定义行为
    // READ: 初始化的各种写法 <https://zh.cppreference.com/w/cpp/language/initialization>
    FibonacciCache fib={{0},0};

    ASSERT(fibonacci(fib, 10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fibonacci(fib, 10) << std::endl;
    return 0;
}
