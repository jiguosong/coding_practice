SET(INCLUDED_FILES
        task2.h 
        task2.cpp 
        task2_test.cpp
    )
add_executable(task2 ${INCLUDED_FILES})
target_link_libraries(task2 gtest gmock_main)
cotire(task2)
add_test(NAME task2_test COMMAND task2)
