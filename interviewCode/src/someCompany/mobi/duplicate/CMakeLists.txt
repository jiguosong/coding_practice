add_executable(duplicate duplicate.h duplicate.cpp duplicate_test.cpp)
target_link_libraries(duplicate gtest gmock_main)
cotire(duplicate)
add_test(NAME duplicate_test COMMAND duplicate)
