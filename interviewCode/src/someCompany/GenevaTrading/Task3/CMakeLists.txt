add_executable(GenevaTrading_Task3 Task3.h Task3.cpp Task3_test.cpp)
target_link_libraries(GenevaTrading_Task3 gtest gmock_main)
cotire(GenevaTrading_Task3)
add_test(NAME GenevaTrading_Task3_test COMMAND GenevaTrading_Task3)
