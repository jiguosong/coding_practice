SET(INCLUDED_FILES
        beautifulbinarystr.h 
        beautifulbinarystr.cpp 
        beautifulbinarystr_test.cpp
    )
add_executable(beautifulbinarystr ${INCLUDED_FILES})
target_link_libraries(beautifulbinarystr gtest gmock_main)
cotire(beautifulbinarystr)
add_test(NAME beautifulbinarystr_test COMMAND beautifulbinarystr)
