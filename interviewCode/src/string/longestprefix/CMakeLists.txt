add_executable(longestprefix longestprefix.h longestprefix.cpp longestprefix_test.cpp)
target_link_libraries(longestprefix gtest gmock_main)
cotire(longestprefix)
add_test(NAME longestprefix_test COMMAND longestprefix)
