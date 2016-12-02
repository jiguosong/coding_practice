add_executable(isswapsorted isswapsorted.h isswapsorted.cpp isswapsorted_test.cpp)
target_link_libraries(isswapsorted gtest gmock_main)
cotire(isswapsorted)
add_test(NAME isswapsorted_test COMMAND isswapsorted)
