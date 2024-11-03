# Look for headers in the include directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# add_library(13_split SHARED 13_split.cpp)
# link_libraries(13_split)

# add_library(13_mytype SHARED 13_mytype.cpp)
# link_libraries(13_mytype)

# You can also add any stand alone executables
# add_executable(example main.cpp) # Will make a binary called "example" inside build/bin using main.cpp
add_executable(main_zipfs_algorithms main_zipfs_algorithms.cpp)
add_executable(main_zipfs_containers main_zipfs_containers.cpp)
