add_executable(N_sum N_sum.h N_sum.cpp N_sum_test.cpp)
target_link_libraries(N_sum gtest gmock_main)
cotire(N_sum)
add_test(NAME N_sum_test COMMAND N_sum)
