// #include "../exercise.h"
// #include <cstring>
// #include <vector>

// // READ: std::vector <https://zh.cppreference.com/w/cpp/container/vector>

// // TODO: 将下列 `?` 替换为正确的代码
// int main(int argc, char **argv) {
//     {
//         std::vector<int> vec{1, 2, 3, 4, 5};
//         ASSERT(vec.size() == 5, "Fill in the correct value.");
//         // THINK: `std::vector` 的大小是什么意思？与什么有关？
//         ASSERT(sizeof(vec) == sizeof(std::vector<int>), "Fill in the correct value.");
//         int ans[]{1, 2, 3, 4, 5};
//         ASSERT(std::memcmp(vec.data(), ans, sizeof(ans)) == 0, "Fill in the correct values.");
//     }
//     {
//         std::vector<double> vec{1, 2, 3, 4, 5};
//         {
//             ASSERT(vec.size() == 5, "Fill in the correct value.");
//             ASSERT(sizeof(vec) ==sizeof(std::vector<double>) , "Fill in the correct value.");
//             double ans[]{1, 2, 3, 4, 5};
//             ASSERT(std::memcmp(vec.data(), ans, sizeof(ans)) == 0, "Fill in the correct values.");
//         }
//         {
//             vec.push_back(6);
//             ASSERT(vec.size() == 6, "Fill in the correct value.");
//             ASSERT(sizeof(vec) == sizeof(std::vector<double>), "Fill in the correct value.");
//             vec.pop_back();
//             ASSERT(vec.size() == 5, "Fill in the correct value.");
//             ASSERT(sizeof(vec) == sizeof(std::vector<double>), "Fill in the correct value.");
//         }
//         {
//             vec[4] = 6;
//             ASSERT(vec[0] == 1, "Fill in the correct value.");
//             ASSERT(vec[1] == 2, "Fill in the correct value.");
//             ASSERT(vec[2] == 3, "Fill in the correct value.");
//             ASSERT(vec[3] == 4, "Fill in the correct value.");
//             ASSERT(vec[4] == 6, "Fill in the correct value.");
//         }
//         {
//             // THINK: `std::vector` 插入删除的时间复杂度是什么？
//             vec.insert(vec.begin()+1, 1.5);
//             ASSERT((vec == std::vector<double>{1, 1.5, 2, 3, 4, 6}), "Make this assertion pass.");
//             vec.erase(vec.begin()+2);
//             ASSERT((vec == std::vector<double>{1, 1.5, 2, 4, 6}), "Make this assertion pass.");
//         }
//         {
//             vec.shrink_to_fit();
//             ASSERT(vec.capacity() == 5, "Fill in the correct value.");
//             vec.clear();
//             ASSERT(vec.empty(), "`vec` is empty now.");
//             ASSERT(vec.size() == 0, "Fill in the correct value.");
//             ASSERT(vec.capacity() == 5, "Fill in the correct value.");
//         }
//     }
//     {
//         std::vector<char> vec(48, 'z'); // TODO: 调用正确的构造函数
//         ASSERT(vec[0] == 'z', "Make this assertion pass.");
//         ASSERT(vec[47] == 'z', "Make this assertion pass.");
//         ASSERT(vec.size() == 48, "Make this assertion pass.");
//         ASSERT(sizeof(vec) == 48, "Fill in the correct value.");
//         {
//             auto capacity = vec.capacity();
//             vec.resize(16);
//             ASSERT(vec.size() == 16, "Fill in the correct value.");
//             ASSERT(vec.capacity() == 48, "Fill in a correct identifier.");
//         }
//         {
//             vec.reserve(256);
//             ASSERT(vec.size() == 16, "Fill in the correct value.");
//             ASSERT(vec.capacity() == 256, "Fill in the correct value.");
//         }
//         {
//             vec.push_back('a');
//             vec.push_back('b');
//             vec.push_back('c');
//             vec.push_back('d');
//             ASSERT(vec.size() == 20, "Fill in the correct value.");
//             ASSERT(vec.capacity() == 48, "Fill in the correct value.");
//             ASSERT(vec[15] == 'z', "Fill in the correct value.");
//             ASSERT(vec[16] == 'a', "Fill in the correct value.");
//             ASSERT(vec[17] == 'b', "Fill in the correct value.");
//             ASSERT(vec[18] == 'c', "Fill in the correct value.");
//             ASSERT(vec[19] == 'd', "Fill in the correct value.");
//         }
//     }

//     return 0;
// }


#include "../exercise.h"
#include <cstring>
#include <vector>

// READ: std::vector <https://zh.cppreference.com/w/cpp/container/vector>

int main(int argc, char **argv) {
    {
        std::vector<int> vec{1, 2, 3, 4, 5};
        ASSERT(vec.size() == 5, "Fill in the correct value."); // vec 包含 5 个元素
        // THINK: std::vector 的大小是什么意思？与什么有关？
        ASSERT(sizeof(vec) == sizeof(void *) * 3, "Fill in the correct value.");
        // sizeof(vec) 表示 vector 内部的元数据大小，包括指针和容量信息，通常为 3 个指针大小。

        int ans[]{1, 2, 3, 4, 5};
        ASSERT(std::memcmp(vec.data(), ans, sizeof(ans)) == 0, "Fill in the correct values.");
        // vec.data() 返回底层数组的首地址。
    }
    {
        std::vector<double> vec{1, 2, 3, 4, 5};
        {
            ASSERT(vec.size() == 5, "Fill in the correct value."); // vec 包含 5 个元素
            ASSERT(sizeof(vec) == sizeof(void *) * 3, "Fill in the correct value.");
            // 同样，sizeof(vec) 为 3 个指针大小。

            double ans[]{1, 2, 3, 4, 5};
            ASSERT(std::memcmp(vec.data(), ans, sizeof(ans)) == 0, "Fill in the correct values.");
            // vec.data() 返回底层数组首地址，与 ans 比较内容相同。
        }
        {
            vec.push_back(6);
            ASSERT(vec.size() == 6, "Fill in the correct value."); // 增加一个元素，vec.size() 为 6
            ASSERT(sizeof(vec) == sizeof(void *) * 3, "Fill in the correct value.");
            // 元数据大小不变。

            vec.pop_back();
            ASSERT(vec.size() == 5, "Fill in the correct value."); // 删除一个元素，vec.size() 回到 5
            ASSERT(sizeof(vec) == sizeof(void *) * 3, "Fill in the correct value.");
            // 元数据大小仍不变。
        }
        {
            vec[4] = 6; // 将第五个元素的值改为 6
            ASSERT(vec[0] == 1, "Fill in the correct value.");
            ASSERT(vec[1] == 2, "Fill in the correct value.");
            ASSERT(vec[2] == 3, "Fill in the correct value.");
            ASSERT(vec[3] == 4, "Fill in the correct value.");
            ASSERT(vec[4] == 6, "Fill in the correct value."); // 检查修改是否正确
        }
        {
            // THINK: std::vector 插入删除的时间复杂度是什么？
            vec.insert(vec.begin() + 1, 1.5); // 在第二个位置插入 1.5
            ASSERT((vec == std::vector<double>{1, 1.5, 2, 3, 4, 6}), "Make this assertion pass.");

            vec.erase(vec.begin() + 3); // 删除第四个位置的元素
            ASSERT((vec == std::vector<double>{1, 1.5, 2, 4, 6}), "Make this assertion pass.");
        }
        {
            vec.shrink_to_fit();
            ASSERT(vec.capacity() == vec.size(), "Fill in the correct value.");
            // 调用 shrink_to_fit 后容量应等于当前大小。

            vec.clear(); // 清空 vector
            ASSERT(vec.empty(), "vec is empty now.");
            ASSERT(vec.size() == 0, "Fill in the correct value."); // size 应为 0
            ASSERT(vec.capacity() >= 5, "Fill in the correct value.");
            // capacity 可能大于 0，具体实现依赖于标准库。
        }
    }
    {
        std::vector<char> vec(48, 'z'); // 初始化大小为 48，每个元素为 'z'
        ASSERT(vec[0] == 'z', "Make this assertion pass.");
        ASSERT(vec[47] == 'z', "Make this assertion pass.");
        ASSERT(vec.size() == 48, "Make this assertion pass.");
        ASSERT(sizeof(vec) == sizeof(void *) * 3, "Fill in the correct value.");
        // 同样，sizeof(vec) 是元数据大小。

        {
            auto capacity = vec.capacity();
            vec.resize(16); // 改变大小为 16
            ASSERT(vec.size() == 16, "Fill in the correct value.");
            ASSERT(vec.capacity() == capacity, "Fill in a correct identifier.");
            // 缩小尺寸不会改变 capacity。
        }
        {
            vec.reserve(256); // 改变容量为 256
            ASSERT(vec.size() == 16, "Fill in the correct value.");
            // 大小不变。
            ASSERT(vec.capacity() == 256, "Fill in the correct value.");
            // 容量增加到 256。
        }
        {
            vec.push_back('a');
            vec.push_back('b');
            vec.push_back('c');
            vec.push_back('d');
            ASSERT(vec.size() == 20, "Fill in the correct value."); // 增加 4 个元素，总大小为 20
            ASSERT(vec.capacity() == 256, "Fill in the correct value."); // 容量不变
            ASSERT(vec[15] == 'z', "Fill in the correct value."); // 第 16 个元素仍为原值 'z'
            ASSERT(vec[16] == 'a', "Fill in the correct value.");
            ASSERT(vec[17] == 'b', "Fill in the correct value.");
            ASSERT(vec[18] == 'c', "Fill in the correct value.");
            ASSERT(vec[19] == 'd', "Fill in the correct value.");
        }
    }

    return 0;
}

