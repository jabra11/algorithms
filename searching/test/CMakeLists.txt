enable_testing()

find_package(GTest)

set(tests
    run_linear_search_test.cc
    run_binary_search_test.cc
    )

add_executable(run_searching_tests ${tests})
target_link_libraries(run_searching_tests
                    PRIVATE
                    jab_utils
                    searching_API
                    gtest
                    gtest_main
                    )

add_test(searching run_searching_tests)
