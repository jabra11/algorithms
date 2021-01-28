enable_testing()

find_package(GTest)

add_executable(insertion_sort run_insertion_sort_test.cc)
target_link_libraries(insertion_sort
                    PRIVATE
                    sorting_API
                    jab_utils 
                    gtest
                    gtest_main
                    )

add_executable(selection_sort run_selection_sort_test.cc)
target_link_libraries(selection_sort
                    PRIVATE
                    sorting_API
                    jab_utils 
                    gtest
                    gtest_main
                    )

add_test(run_selection_sort_tests selection_sort)
add_test(run_insertion_sort_tests insertion_sort)
