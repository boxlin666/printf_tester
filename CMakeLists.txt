cmake_minimum_required(VERSION 3.10)
project(MyCProject LANGUAGES C CXX)

# 设置 C 和 C++ 标准
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 指定 Google Test 的本地路径
set(GTEST_ROOT ~/gtest-install)
find_package(GTest REQUIRED PATHS ${GTEST_ROOT})

# 添加源文件
add_library(ft STATIC ft_printf.c)
target_include_directories(ft PUBLIC ${PROJECT_SOURCE_DIR}/src)

# 添加测试可执行文件
find_package(GTest REQUIRED)
add_executable(run_tests gtest_ftprintf.cpp)
target_link_libraries(run_tests PRIVATE ft GTest::GTest GTest::Main)

# 启用测试
enable_testing()
add_test(NAME Tests COMMAND run_tests)