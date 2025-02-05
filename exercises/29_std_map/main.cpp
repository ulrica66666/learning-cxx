﻿// #include "../exercise.h"
// #include <map>

// // READ: `std::map` <https://zh.cppreference.com/w/cpp/container/map>
// // READ: `std::unordered_map` <https://zh.cppreference.com/w/cpp/container/unordered_map>

// template<class k, class v>
// bool key_exists(std::map<k, v> const &map, k const &key) {
//     // TODO: 实现函数
// }

// template<class k, class v>
// void set(std::map<k, v> &map, k key, v value) {
//     // TODO: 实现函数
// }

// // ---- 不要修改以下代码 ----
// int main(int argc, char **argv) {
//     using namespace std::string_literals;

//     std::map<std::string, std::string> secrets;

//     set(secrets, "hello"s, "world"s);
//     ASSERT(key_exists(secrets, "hello"s), "\"hello\" shoud be in `secrets`");
//     ASSERT(!key_exists(secrets, "foo"s), "\"foo\" shoud not be in `secrets`");

//     set(secrets, "foo"s, "bar"s);
//     set(secrets, "Infini"s, "Tensor"s);
//     ASSERT(secrets["hello"] == "world", "hello -> world");
//     ASSERT(secrets["foo"] == "bar", "foo -> bar");
//     ASSERT(secrets["Infini"] == "Tensor", "Infini -> Tensor");

//     set(secrets, "hello"s, "developer"s);
//     ASSERT(secrets["hello"] == "developer", "hello -> developer");

//     return 0;
// }
#include "../exercise.h"
#include <map>

// 检查键是否存在于 map 中
template<class k, class v>
bool key_exists(std::map<k, v> const &map, k const &key) {
    return map.find(key) != map.end();  // 如果 find 返回 map.end()，说明键不存在
}

// 设置一个键值对到 map 中，如果键已经存在则更新值
template<class k, class v>
void set(std::map<k, v> &map, k key, v value) {
    map[key] = value;  // 如果键存在，会更新值；如果键不存在，会插入新的键值对
}

// ---- 不要修改以下代码 ----
int main(int argc, char **argv) {
    using namespace std::string_literals;

    std::map<std::string, std::string> secrets;

    set(secrets, "hello"s, "world"s);
    ASSERT(key_exists(secrets, "hello"s), "\"hello\" shoud be in `secrets`");
    ASSERT(!key_exists(secrets, "foo"s), "\"foo\" shoud not be in `secrets`");

    set(secrets, "foo"s, "bar"s);
    set(secrets, "Infini"s, "Tensor"s);
    ASSERT(secrets["hello"] == "world", "hello -> world");
    ASSERT(secrets["foo"] == "bar", "foo -> bar");
    ASSERT(secrets["Infini"] == "Tensor", "Infini -> Tensor");

    set(secrets, "hello"s, "developer"s);
    ASSERT(secrets["hello"] == "developer", "hello -> developer");

    return 0;
}

