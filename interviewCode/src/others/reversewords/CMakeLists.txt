add_executable(reversewords reversewords.h reversewords.cpp reversewords_test.cpp)
target_link_libraries(reversewords gtest gmock_main)
cotire(reversewords)
add_test(NAME reversewords_test COMMAND reversewords)
