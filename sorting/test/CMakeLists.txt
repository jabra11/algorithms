enable_testing()

find_package(GTest)

set(tests
    run_insertion_sort_test.cc
    run_selection_sort_test.cc
    run_merge_sort_test.cc
    )

add_executable(run_tests ${tests})
target_link_libraries(run_tests
                    PRIVATE
                    sorting_API
                    jab_utils 
                    gtest
                    gtest_main
                    )

add_test(run_test run_tests)
