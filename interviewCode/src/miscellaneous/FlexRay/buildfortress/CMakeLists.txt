add_executable(buildfortress buildfortress.h buildfortress.cpp buildfortress_test.cpp)
target_link_libraries(buildfortress gtest gmock_main)
cotire(buildfortress)
add_test(NAME buildfortress_test COMMAND buildfortress)
