add_executable(editdistance editdistance.h editdistance.cpp editdistance_test.cpp)
target_link_libraries(editdistance gtest gmock_main)
add_test(NAME editdistance_test COMMAND editdistance)
