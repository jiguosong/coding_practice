add_executable(traversal_verticalorder traversal_verticalorder.h traversal_verticalorder.cpp traversal_verticalorder_test.cpp)
target_link_libraries(traversal_verticalorder gtest gmock_main)
cotire(traversal_verticalorder)
add_test(NAME traversal_verticalorder_test COMMAND traversal_verticalorder)
