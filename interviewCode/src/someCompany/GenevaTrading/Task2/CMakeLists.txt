add_executable(GenevaTrading_Task2 Task2.h Task2.cpp Task2_test.cpp)
target_link_libraries(GenevaTrading_Task2 gtest gmock_main)
cotire(GenevaTrading_Task2)
add_test(NAME GenevaTrading_Task2_test COMMAND GenevaTrading_Task2)
