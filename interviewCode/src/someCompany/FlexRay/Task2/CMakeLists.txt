add_executable(Task2 Task2.h Task2.cpp Task2_test.cpp)
target_link_libraries(Task2 gtest gmock_main)
cotire(Task2)
add_test(NAME Task2_test COMMAND Task2)
