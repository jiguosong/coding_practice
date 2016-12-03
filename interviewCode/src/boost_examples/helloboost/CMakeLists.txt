add_executable(helloboost helloboost.h helloboost.cpp helloboost_test.cpp)

target_link_libraries(helloboost gtest gmock_main)
cotire(helloboost)
add_test(NAME helloboost_test COMMAND dividearray)