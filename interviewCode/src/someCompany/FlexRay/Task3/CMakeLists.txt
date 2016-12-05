add_executable(Task3 Task3.h Task3.cpp Task3_test.cpp)
target_link_libraries(Task3 gtest gmock_main)
cotire(Task3)
add_test(NAME Task3_test COMMAND Task3)
