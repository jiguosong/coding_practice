add_executable(rotatearray rotatearray.h rotatearray.cpp rotatearray_test.cpp)
target_link_libraries(rotatearray gtest gmock_main)
cotire(rotatearray)
add_test(NAME rotatearray_test COMMAND rotatearray)
