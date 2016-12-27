SET(INCLUDED_FILES
        task5.h 
        task5.cpp 
        task5_test.cpp
    )
add_executable(task5 ${INCLUDED_FILES})
target_link_libraries(task5 gtest gmock_main)
cotire(task5)
add_test(NAME task5_test COMMAND task5)
