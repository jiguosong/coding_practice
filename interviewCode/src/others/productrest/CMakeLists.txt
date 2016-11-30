add_executable(productrest productrest.h productrest.cpp productrest_test.cpp)
target_link_libraries(productrest gtest gmock_main)
cotire(productrest)
add_test(NAME productrest_test COMMAND productrest)
