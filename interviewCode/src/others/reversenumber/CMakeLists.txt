add_executable(reversenumber reversenumber.h reversenumber.cpp reversenumber_test.cpp)
target_link_libraries(reversenumber gtest gmock_main)
cotire(reversenumber)
add_test(NAME reversenumber_test COMMAND reversenumber)
