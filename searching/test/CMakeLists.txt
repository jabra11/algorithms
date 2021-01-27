enable_testing()

set(src
    run_tests.cc
    )

find_package(GTest)

add_executable(searching_tests ${src})
target_link_libraries(searching_tests
                    PRIVATE
                    jab_utils
                    searching_API
                    gtest
                    gtest_main
                    )
add_test(searching_tests searching_tests)
