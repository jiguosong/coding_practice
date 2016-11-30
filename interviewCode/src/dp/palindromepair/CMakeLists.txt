add_executable(palindromepair palindromepair.h palindromepair.cpp palindromepair_test.cpp)
target_link_libraries(palindromepair gtest gmock_main)
cotire(palindromepair)
add_test(NAME palindromepair_test COMMAND palindromepair)
