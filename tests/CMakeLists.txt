set(BT_TEST_SOURCES
    gtest_behaviorTree.cpp
    gtest_t2.cpp
)
if(BT_UNIT_TESTS)
    message(STATUS "Building unit tests in tests directory")
    enable_testing()
    add_executable(${BEHAVIOR_TREE_LIBRARY}_test ${BT_TEST_SOURCES})
    target_link_libraries(${PROJECT_NAME}_test
        ${BEHAVIOR_TREE_LIBRARY} gtest gtest_main)

    target_include_directories(${BEHAVIOR_TREE_LIBRARY}_test PRIVATE gtest/include ${GTEST_INCLUDE_DIRS})

    # add_custom_command(TARGET ${BEHAVIOR_TREE_LIBRARY}_test POST_BUILD
    #     COMMAND ${CMAKE_COMMAND} -E copy_directory)

    # add_test(BehaviorTreeCoreTest ${BEHAVIOR_TREE_LIBRARY}_test)


    # add_executable(${BEHAVIOR_TREE_LIBRARY}_test ${BT_TEST_SOURCES})
    # target_link_libraries(${BEHAVIOR_TREE_LIBRARY}_test GTest::gtest_main)
    # target_include_directories(${BEHAVIOR_TREE_LIBRARY}_test PRIVATE gtest/include ${GTEST_INCLUDE_DIRS})
    include(GoogleTest)
    gtest_discover_tests(${BEHAVIOR_TREE_LIBRARY}_test)
endif()