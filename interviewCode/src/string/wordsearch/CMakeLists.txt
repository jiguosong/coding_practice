add_executable(wordsearch wordsearch.h wordsearch.cpp wordsearch_test.cpp)
target_link_libraries(wordsearch gtest gmock_main)
cotire(wordsearch)
add_test(NAME wordsearch_test COMMAND wordsearch)
