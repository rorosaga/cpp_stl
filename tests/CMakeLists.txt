include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)

# Add the include directory for header files (do NOT add it as a subdirectory)
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add the library for expression
# I am already building libraries in src/CMakeLists.txt
# add_library(zipfs_lib SHARED ${CMAKE_SOURCE_DIR}/src/main_zipfs_containers.cpp)


# Add the test executables
add_executable(test_zipfs ${CMAKE_SOURCE_DIR}/tests/test_zipfs.cpp)

add_library(zipfs_lib SHARED ${CMAKE_SOURCE_DIR}/src/main_zipfs_containers.cpp)

# Link the test executables with the corresponding libraries and GTest
target_link_libraries(
  test_zipfs
  zipfs_lib
  GTest::gtest_main
)

# Discover the tests in both test executables
gtest_discover_tests(test_zipfs)

# Copy any necessary test files to the build directory
add_custom_command(
    TARGET test_zipfs POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_SOURCE_DIR}/tests/test.txt
            ${CMAKE_BINARY_DIR}
)
