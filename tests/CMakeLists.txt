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
# add_library(split_lib SHARED ${CMAKE_SOURCE_DIR}/src/13_split.cpp)
# add_library(mytype_lib SHARED ${CMAKE_SOURCE_DIR}/src/13_mytype.cpp)

# Add the test executables
# add_executable(test_split ${CMAKE_SOURCE_DIR}/tests/test_split.cpp)
# add_executable(test_mytype ${CMAKE_SOURCE_DIR}/tests/test_mytype.cpp)
# add_executable(test_sum ${CMAKE_SOURCE_DIR}/tests/test_sum.cpp)
# add_executable(test_pair ${CMAKE_SOURCE_DIR}/tests/test_pair.cpp)
# add_executable(test_transform ${CMAKE_SOURCE_DIR}/tests/test_transform.cpp)
# add_executable(test_is_raw_pointer ${CMAKE_SOURCE_DIR}/tests/test_is_raw_pointer.cpp)
# add_executable(test_flexible_container ${CMAKE_SOURCE_DIR}/tests/test_flexible_container.cpp)

# # Link the test executables with the corresponding libraries and GTest
# target_link_libraries(
#   test_split
#   13_split
#   GTest::gtest_main
# )

# target_link_libraries(
#   test_mytype
#   13_mytype
#   GTest::gtest_main
# )

# target_link_libraries(
#   test_sum
#   GTest::gtest_main
# )

# target_link_libraries(
#   test_pair
#   GTest::gtest_main
# )

# target_link_libraries(
#   test_transform
#   GTest::gtest_main
# )

# target_link_libraries(
#   test_is_raw_pointer
#   GTest::gtest_main
# )

# target_link_libraries(
#   test_flexible_container
#   GTest::gtest_main
# )

# # Discover the tests in both test executables
# gtest_discover_tests(test_split)
# gtest_discover_tests(test_mytype)
# gtest_discover_tests(test_sum)
# gtest_discover_tests(test_pair)
# gtest_discover_tests(test_transform)
# gtest_discover_tests(test_is_raw_pointer)
# gtest_discover_tests(test_flexible_container)
