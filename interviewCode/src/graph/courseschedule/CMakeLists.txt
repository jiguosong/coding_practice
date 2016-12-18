add_executable(courseschedule courseschedule.h courseschedule.cpp courseschedule_test.cpp)
target_link_libraries(courseschedule gtest gmock_main)
cotire(courseschedule)
add_test(NAME courseschedule_test COMMAND courseschedule)
