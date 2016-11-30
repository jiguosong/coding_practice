add_executable(wordbreak wordbreak.h wordbreak.cpp wordbreak_test.cpp)
target_link_libraries(wordbreak gtest gmock_main)
cotire(wordbreak)
add_test(NAME wordbreak_test COMMAND wordbreak)
