add_executable(painthouses painthouses.h painthouses.cpp painthouses_test.cpp)
target_link_libraries(painthouses gtest gmock_main)
cotire(painthouses)
add_test(NAME painthouses_test COMMAND painthouses)
