add_library(jab_utils INTERFACE)
target_include_directories(jab_utils INTERFACE include)

install(DIRECTORY include/jab
    DESTINATION include)
