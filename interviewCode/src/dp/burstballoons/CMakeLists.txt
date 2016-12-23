SET(INCLUDED_FILES
        burstballoons.h 
        burstballoons.cpp 
        burstballoons_test.cpp
    )
add_executable(burstballoons ${INCLUDED_FILES})
target_link_libraries(burstballoons gtest gmock_main)
cotire(burstballoons)
add_test(NAME burstballoons_test COMMAND burstballoons)
