SET(INCLUDED_FILES
        nqueens.h 
        nqueens.cpp 
        nqueens_test.cpp
    )
add_executable(nqueens ${INCLUDED_FILES})
target_link_libraries(nqueens gtest gmock_main)
cotire(nqueens)
add_test(NAME nqueens_test COMMAND nqueens)
