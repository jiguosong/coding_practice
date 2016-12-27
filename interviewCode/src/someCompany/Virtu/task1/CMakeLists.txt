SET(INCLUDED_FILES
        task1.h 
        task1.cpp 
        task1_test.cpp
    )
add_executable(task1 ${INCLUDED_FILES})
target_link_libraries(task1 gtest gmock_main)
cotire(task1)
add_test(NAME task1_test COMMAND task1)
