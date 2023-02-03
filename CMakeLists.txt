cmake_minimum_required(VERSION 3.20)
project(behaviorTree VERSION 0.1.0)

# 设置C++版本为20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置编译选项,是否开启单元测试
option(BT_UNIT_TESTS "Build the unit tests" ON)

# 设置源文件目录
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LIST)


set(BEHAVIOR_TREE_LIBRARY ${PROJECT_NAME})

add_library(behaviorTree ${SRC_LIST})
if(BT_UNIT_TESTS)
    message(STATUS "Building unit tests")
    enable_testing()
    include(FetchContent)
    FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
    add_subdirectory(tests)
endif()

# 设置include目录
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)
# target_include_directories(${BEHAVIOR_TREE_LIBRARY} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include)


# 设置包含目录
target_include_directories(${BEHAVIOR_TREE_LIBRARY} PUBLIC
                           "${PROJECT_BINARY_DIR}")