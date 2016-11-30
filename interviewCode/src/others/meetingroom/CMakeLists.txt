add_executable(meetingroom meetingroom.h meetingroom.cpp meetingroom_test.cpp)
target_link_libraries(meetingroom gtest gmock_main)
cotire(meetingroom)
add_test(NAME meetingroom_test COMMAND meetingroom)
