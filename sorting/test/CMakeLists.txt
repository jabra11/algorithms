enable_testing()

set(src
    run_tests.cc
    )

find_package(GTest)

add_executable(sorting_tests ${src})
target_link_libraries(sorting_tests
                    PRIVATE
                    sorting_API
                    jab_utils 
                    gtest
                    gtest_main
                    )
add_test(sorting_tests sorting_tests)
