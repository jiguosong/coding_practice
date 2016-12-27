SET(INCLUDED_FILES
        lettercombiephonenumber.h 
        lettercombiephonenumber.cpp 
        lettercombiephonenumber_test.cpp
    )
add_executable(lettercombiephonenumber ${INCLUDED_FILES})
target_link_libraries(lettercombiephonenumber gtest gmock_main)
cotire(lettercombiephonenumber)
add_test(NAME lettercombiephonenumber_test COMMAND lettercombiephonenumber)
