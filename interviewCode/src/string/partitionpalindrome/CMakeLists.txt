add_executable(partitionpalindrome partitionpalindrome.h partitionpalindrome.cpp partitionpalindrome_test.cpp)
target_link_libraries(partitionpalindrome gtest gmock_main)
cotire(partitionpalindrome)
add_test(NAME partitionpalindrome_test COMMAND partitionpalindrome)
