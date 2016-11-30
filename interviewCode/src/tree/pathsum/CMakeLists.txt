add_executable(pathsum pathsum.h pathsum.cpp pathsum_test.cpp)
target_link_libraries(pathsum gtest gmock_main)
cotire(pathsum)
add_test(NAME pathsum_test COMMAND pathsum)
