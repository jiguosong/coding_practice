SET(INCLUDED_FILES
        longestbinarygap.h 
        longestbinarygap.cpp 
        longestbinarygap_test.cpp
    )
add_executable(longestbinarygap ${INCLUDED_FILES})
target_link_libraries(longestbinarygap gtest gmock_main)
cotire(longestbinarygap)
add_test(NAME longestbinarygap_test COMMAND longestbinarygap)
