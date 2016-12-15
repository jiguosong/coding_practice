add_executable(finddifference finddifference.h finddifference.cpp finddifference_test.cpp)
target_link_libraries(finddifference gtest gmock_main)
cotire(finddifference)
add_test(NAME finddifference_test COMMAND finddifference)
