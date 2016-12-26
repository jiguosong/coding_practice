SET(INCLUDED_FILES
        flattenBTtolinkedlist.h 
        flattenBTtolinkedlist.cpp 
        flattenBTtolinkedlist_test.cpp
        ../traversal_levelorder/traversal_levelorder.h 
        ../traversal_levelorder/traversal_levelorder.cpp
    )
add_executable(flattenBTtolinkedlist ${INCLUDED_FILES})
target_link_libraries(flattenBTtolinkedlist gtest gmock_main)
cotire(flattenBTtolinkedlist)
add_test(NAME flattenBTtolinkedlist_test COMMAND flattenBTtolinkedlist)
