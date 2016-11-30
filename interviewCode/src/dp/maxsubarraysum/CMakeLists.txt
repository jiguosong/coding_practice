add_executable(maxsubarraysum maxsubarraysum.h maxsubarraysum.cpp maxsubarraysum_test.cpp)
target_link_libraries(maxsubarraysum gtest gmock_main)
cotire(maxsubarraysum)
add_test(NAME maxsubarraysum_test COMMAND maxsubarraysum)
