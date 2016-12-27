SET(INCLUDED_FILES
        buysellstock4.h 
        buysellstock4.cpp 
        buysellstock4_test.cpp
    )
add_executable(buysellstock4 ${INCLUDED_FILES})
target_link_libraries(buysellstock4 gtest gmock_main)
cotire(buysellstock4)
add_test(NAME buysellstock4_test COMMAND buysellstock4)
