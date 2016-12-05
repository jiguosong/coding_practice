add_executable(Task1 Task1.h Task1.cpp Task1_test.cpp)
target_link_libraries(Task1 gtest gmock_main)
cotire(Task1)
add_test(NAME Task1_test COMMAND Task1)
