set(src
    src/main.cc
    src/linear_search.hpp
    src/binary_search.hpp
    )

add_executable(searching ${src})

target_link_libraries(searching PUBLIC utility)
