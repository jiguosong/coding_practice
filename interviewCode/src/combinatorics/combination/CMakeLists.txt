add_executable(combination combination.h combination.cpp combination_test.cpp)
target_link_libraries(combination gtest gmock_main)
cotire(combination)
add_test(NAME combination_test COMMAND combination)
