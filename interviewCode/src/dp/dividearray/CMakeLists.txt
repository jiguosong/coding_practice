add_executable(dividearray dividearray.h dividearray.cpp dividearray_test.cpp)
target_link_libraries(dividearray gtest gmock_main)
cotire(dividearray)
add_test(NAME dividearray_test COMMAND dividearray)
