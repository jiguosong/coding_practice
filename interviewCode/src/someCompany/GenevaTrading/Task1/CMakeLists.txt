add_executable(GenevaTrading_Task1 Task1.h Task1.cpp Task1_test.cpp)
target_link_libraries(GenevaTrading_Task1 gtest gmock_main)
cotire(GenevaTrading_Task1)
add_test(NAME GenevaTrading_Task1_test COMMAND GenevaTrading_Task1)
