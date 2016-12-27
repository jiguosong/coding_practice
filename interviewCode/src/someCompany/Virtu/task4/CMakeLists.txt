SET(INCLUDED_FILES
        task4.h 
        task4.cpp 
        task4_test.cpp
    )
add_executable(task4 ${INCLUDED_FILES})
target_link_libraries(task4 gtest gmock_main)
cotire(task4)
add_test(NAME task4_test COMMAND task4)
