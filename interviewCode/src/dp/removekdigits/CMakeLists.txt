add_executable(removekdigits removekdigits.h removekdigits.cpp removekdigits_test.cpp)
target_link_libraries(removekdigits gtest gmock_main)
cotire(removekdigits)
add_test(NAME removekdigits_test COMMAND removekdigits)
