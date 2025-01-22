#include "../exercise.h"

// struct Fibonacci {
//     unsigned long long cache[128];
//     int cached;

//     // TODO: 实现正确的缓存优化斐波那契计算
//     unsigned long long get(int i) {
//         for (; false; ++cached) {
//             cache[cached] = cache[cached - 1] + cache[cached - 2];
//         }
//         return cache[i];
//     }
// };
struct Fibonacci {
    unsigned long long cache[128];  // 用于缓存最多 128 项斐波那契数列的值
    int cached;                     // 表示当前已缓存的最大斐波那契项的数量

    // 构造函数：初始化缓存结构体
    Fibonacci() : cached(0) {
        cache[0] = 0;  // F(0) = 0
        cache[1] = 1;  // F(1) = 1
        cached = 2;    // 初始缓存了前两项
    }

    // 获取第 i 项斐波那契数，使用缓存优化
    unsigned long long get(int i) {
        if (i < cached) {
            return cache[i];  // 如果缓存中已有值，直接返回
        }

        // 计算并缓存缺失的斐波那契数
        for (int j = cached; j <= i; ++j) {
            cache[j] = cache[j - 1] + cache[j - 2];  // F(n) = F(n-1) + F(n-2)
        }

        cached = i + 1;  // 更新已缓存的最大项数
        return cache[i];  // 返回第 i 项
    }
};
int main(int argc, char **argv) {
    // TODO: 初始化缓存结构体，使计算正确
    Fibonacci fib;
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}
