add_executable(rangesum rangesum.h rangesum.cpp rangesum_test.cpp)
target_link_libraries(rangesum gtest gmock_main)
cotire(rangesum)
add_test(NAME rangesum_test COMMAND rangesum)
