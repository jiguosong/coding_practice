add_executable(wordladder wordladder.h wordladder.cpp wordladder_test.cpp)
target_link_libraries(wordladder gtest gmock_main)
cotire(wordladder)
add_test(NAME wordladder_test COMMAND wordladder)
