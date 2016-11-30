add_executable(reversebits reversebits.h reversebits.cpp reversebits_test.cpp)
target_link_libraries(reversebits gtest gmock_main)
cotire(reversebits)
add_test(NAME reversebits_test COMMAND reversebits)
