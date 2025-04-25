#include <gtest/gtest.h>
#include <stdio.h>
#include <stdarg.h>

// 声明你的 ft_printf 函数
int ft_printf(const char *format, ...);

// 用于捕获 printf 输出的 Helper 函数
std::string exec(const char* command) {
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen(command, "r");
    if (!pipe) return "ERROR";
    while (!feof(pipe)) {
        if (fgets(buffer, 128, pipe) != NULL)
            result += buffer;
    }
    fclose(pipe);
    return result;
}

// 测试用例：输出字符
TEST(FTPrintfTest, PrintChar) {
    // 使用 exec 函数捕获输出
    std::string result = exec("ft_printf 'c' 'a'");  // 调用你的 ft_printf 函数
    EXPECT_EQ(result, "a");
}

// 测试用例：输出字符串
TEST(FTPrintfTest, PrintString) {
    std::string result = exec("ft_printf 's' 'Hello'");
    EXPECT_EQ(result, "Hello");
}

// 测试用例：输出整数
TEST(FTPrintfTest, PrintInteger) {
    std::string result = exec("ft_printf 'd' 42");
    EXPECT_EQ(result, "42");
}

// 测试用例：输出十六进制
TEST(FTPrintfTest, PrintHex) {
    std::string result = exec("ft_printf 'x' 255");
    EXPECT_EQ(result, "ff");
}

// 测试用例：输出百分号
TEST(FTPrintfTest, PrintPercent) {
    std::string result = exec("ft_printf '%' ");
    EXPECT_EQ(result, "%");
}

// 测试用例：输出指针地址
TEST(FTPrintfTest, PrintPointer) {
    int x = 42;
    std::string result = exec("ft_printf 'p' &x");
    // 这里需要根据你运行环境的实际地址进行检查
    EXPECT_NE(result, "0x0");
}
