﻿#include "../exercise.h"
#include <algorithm>
#include <string>
#include <vector>

// READ: `std::transform` <https://zh.cppreference.com/w/cpp/algorithm/transform>
// std::transform 是一个泛型算法，用于对一个范围内的元素进行转换，并将结果存储到另一个范围中

// READ: `std::vector::begin` <https://zh.cppreference.com/w/cpp/container/vector/begin>

std::string multi2(int val) {
    val *= 2;
    return std::to_string(val);
}

int main(int argc, char** argv) {
    std::vector<int> val{8, 13, 21, 34, 55};
    std::vector<std::string> ans(val.size());
    // TODO: 调用 `std::transform`，将 `v` 中的每个元素乘以 2，并转换为字符串，存入 `ans`
    // std::transform(val.begin(), val.end(), ans.begin(), [](int n) { return std::to_string(n * 2);});
    std::transform(val.begin(), val.end(), ans.begin(), multi2);
    ASSERT(ans.size() == val.size(), "ans size should be equal to val size");
    ASSERT(ans[0] == "16", "ans[0] should be 16");
    ASSERT(ans[1] == "26", "ans[1] should be 26");
    ASSERT(ans[2] == "42", "ans[2] should be 42");
    ASSERT(ans[3] == "68", "ans[3] should be 68");
    ASSERT(ans[4] == "110", "ans[4] should be 110");
    return 0;
}
