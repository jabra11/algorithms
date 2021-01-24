set(src
    src/main.cc
    src/selection_sort.hpp
    src/insertion_sort.hpp
    )

add_executable(sorting ${src})

target_link_libraries(sorting PUBLIC utility)
