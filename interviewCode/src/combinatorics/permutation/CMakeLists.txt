add_executable(permutation permutation.h permutation.cpp permutation_test.cpp)
target_link_libraries(permutation gtest gmock_main)
cotire(permutation)
add_test(NAME permutation_test COMMAND permutation)
