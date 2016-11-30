add_executable(add2number add2number.h add2number.cpp add2number_test.cpp)
target_link_libraries(add2number gtest gmock_main)
cotire(add2number)
add_test(NAME add2number_test COMMAND add2number)
