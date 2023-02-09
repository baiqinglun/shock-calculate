# 最小版本号
cmake_minimum_required(VERSION 3.24)

# 设置项目信息
project(H2_shock VERSION 1.0 LANGUAGES CXX)

# 设置输出文件存放目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# 设置c++版本号
set(CMAKE_CXX_STANDARD 11)

# 添加子目录
add_subdirectory(src/shock-cal)
add_subdirectory(src/Excel)

message(${CMAKE_BINARY_DIR}/bin)

# 生成exe执行文件
add_executable(H2_shock main.cpp src/shock-cal/shock_cal.cpp src/shock-cal/shock_cal.h src/Excel/BasicExcel.cpp src/Excel/BasicExcel.hpp)

include(FetchContent)
FetchContent_Declare(jsoncpp
        GIT_REPOSITORY https://github.com/open-source-parsers/jsoncpp.git
        GIT_TAG 1.9.4)
FetchContent_MakeAvailable(jsoncpp)

# 链接文件
target_link_libraries(H2_shock PUBLIC shock_cal)
target_link_libraries(H2_shock PUBLIC Excel)
target_link_libraries(H2_shock PUBLIC jsoncpp_lib)


# 将包含目录到目标
target_include_directories(${PROJECT_NAME} PUBLIC
        ${PROJECT_BINARY_DIR}
        src/shock-cal
        src/Excel
        )


