set(src
    src/utils.hpp)

add_library(utility INTERFACE)
target_include_directories(utility INTERFACE src)
