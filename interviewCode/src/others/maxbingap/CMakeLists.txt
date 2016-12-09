add_executable(maxbingap maxbingap.h maxbingap.cpp maxbingap_test.cpp)
target_link_libraries(maxbingap gtest gmock_main)
cotire(maxbingap)
add_test(NAME maxbingap_test COMMAND maxbingap)
