add_executable(largestdivisiblesubset largestdivisiblesubset.h largestdivisiblesubset.cpp largestdivisiblesubset_test.cpp)
target_link_libraries(largestdivisiblesubset gtest gmock_main)
cotire(largestdivisiblesubset)
add_test(NAME largestdivisiblesubset_test COMMAND largestdivisiblesubset)
