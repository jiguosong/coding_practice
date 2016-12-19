SET(INCLUDED_FILES
        leftmostsmallernumber.h 
        leftmostsmallernumber.cpp 
        leftmostsmallernumber_test.cpp
    )
add_executable(leftmostsmallernumber ${INCLUDED_FILES})
target_link_libraries(leftmostsmallernumber gtest gmock_main)
cotire(leftmostsmallernumber)
add_test(NAME leftmostsmallernumber_test COMMAND leftmostsmallernumber)
