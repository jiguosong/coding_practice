add_executable(search2dmatrix search2dmatrix.h search2dmatrix.cpp search2dmatrix_test.cpp)
target_link_libraries(search2dmatrix gtest gmock_main)
cotire(search2dmatrix)
add_test(NAME search2dmatrix_test COMMAND search2dmatrix)
