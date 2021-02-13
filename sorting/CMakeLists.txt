add_library(sorting_API INTERFACE)
target_include_directories(sorting_API INTERFACE include)

add_subdirectory(test)
#add_subdirectory(benchmark)

install(DIRECTORY include/jab
    DESTINATION include)
