add_executable(dividearray dividearray.h dividearray.cpp dividearray_test.cpp)
cotire(dividearray)
target_link_libraries(dividearray gtest gmock_main)
add_test(NAME dividearray_test COMMAND dividearray)
