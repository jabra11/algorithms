add_library(searching_API INTERFACE)
target_include_directories(searching_API INTERFACE include)

add_subdirectory(test)
#add_subdirectory(benchmark)
