SET(INCLUDED_FILES
        task3.h 
        task3.cpp 
        task3_test.cpp
    )
add_executable(task3 ${INCLUDED_FILES})
target_link_libraries(task3 gtest gmock_main)
cotire(task3)
add_test(NAME task3_test COMMAND task3)
