add_executable(wordpattern wordpattern.h wordpattern.cpp wordpattern_test.cpp)
target_link_libraries(wordpattern gtest gmock_main)
cotire(wordpattern)
add_test(NAME wordpattern_test COMMAND wordpattern)
