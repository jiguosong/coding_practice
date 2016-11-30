add_executable(parsestr2tree parsestr2tree.h parsestr2tree.cpp parsestr2tree_test.cpp)
target_link_libraries(parsestr2tree gtest gmock_main)
cotire(parsestr2tree)
add_test(NAME parsestr2tree_test COMMAND parsestr2tree)
