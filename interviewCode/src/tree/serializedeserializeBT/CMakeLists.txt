SET(INCLUDED_FILES
        serializedeserializeBT.h 
        serializedeserializeBT.cpp 
        serializedeserializeBT_test.cpp 
        ../traversal_levelorder/traversal_levelorder.h 
        ../traversal_levelorder/traversal_levelorder.cpp
    )

add_executable(serializedeserializeBT ${INCLUDED_FILES})
target_link_libraries(serializedeserializeBT gtest gmock_main)
cotire(serializedeserializeBT)
add_test(NAME serializedeserializeBT_test COMMAND serializedeserializeBT)
