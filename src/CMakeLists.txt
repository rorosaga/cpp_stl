# Look for headers in the include directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# add_library(13_split SHARED 13_split.cpp)
# link_libraries(13_split)

# add_library(13_mytype SHARED 13_mytype.cpp)
# link_libraries(13_mytype)

# You can also add any stand alone executables
# add_executable(example main.cpp) # Will make a binary called "example" inside build/bin using main.cpp
add_executable(main_zipfs_containers main_zipfs_containers.cpp)
add_library(main_zipfs_containers_lib OBJECT main_zipfs_containers.cpp)

add_executable(main_zipfs_algorithms main_zipfs_algorithms.cpp)
add_library(main_zipfs_algorithms_lib OBJECT main_zipfs_algorithms.cpp)

# target_include_directories(main_zipfs_containers PUBLIC ${sciplot_content_SOURCE_DIR}/include)
# target_link_libraries(main_zipfs_containers PUBLIC sciplot)

add_custom_command(
    TARGET main_zipfs_containers POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_SOURCE_DIR}/assets/pg2701.txt
            ${CMAKE_BINARY_DIR}/bin
)

add_custom_command(
    TARGET main_zipfs_containers POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_SOURCE_DIR}/src/plot.py
            ${CMAKE_BINARY_DIR}/bin
)

add_custom_command(
    TARGET main_zipfs_containers POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_SOURCE_DIR}/assets/principito.txt
            ${CMAKE_BINARY_DIR}/bin
)

add_custom_command(
    TARGET main_zipfs_algorithms POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_SOURCE_DIR}/assets/pg2701.txt
            ${CMAKE_BINARY_DIR}/bin
)

add_custom_command(
    TARGET main_zipfs_algorithms POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_SOURCE_DIR}/src/plot.py
            ${CMAKE_BINARY_DIR}/bin
)

add_custom_command(
    TARGET main_zipfs_algorithms POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_SOURCE_DIR}/assets/principito.txt
            ${CMAKE_BINARY_DIR}/bin
)


# add_custom_target(run_all
#     COMMAND ${CMAKE_COMMAND} -E echo "Running main_zipfs_containers..."
#     COMMAND ${CMAKE_BINARY_DIR}/bin/main_zipfs_containers
#     COMMAND ${CMAKE_COMMAND} -E echo "Running plot.py..."
#     COMMAND python ${CMAKE_BINARY_DIR}/bin/plot.py
#     DEPENDS main_zipfs_containers
# )