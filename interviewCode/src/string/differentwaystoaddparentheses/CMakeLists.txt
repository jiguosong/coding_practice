SET(INCLUDED_FILES
        differentwaystoaddparentheses.h 
        differentwaystoaddparentheses.cpp 
        differentwaystoaddparentheses_test.cpp
    )
add_executable(differentwaystoaddparentheses ${INCLUDED_FILES})
target_link_libraries(differentwaystoaddparentheses gtest gmock_main)
cotire(differentwaystoaddparentheses)
add_test(NAME differentwaystoaddparentheses_test COMMAND differentwaystoaddparentheses)
