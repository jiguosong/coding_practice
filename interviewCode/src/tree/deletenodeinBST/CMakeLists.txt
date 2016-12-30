SET(INCLUDED_FILES
        deletenodeinBST.h 
        deletenodeinBST.cpp 
        deletenodeinBST_test.cpp
        ../traversal_levelorder/traversal_levelorder.h 
        ../traversal_levelorder/traversal_levelorder.cpp
        ../validbst/validbst.h
        ../validbst/validbst.cpp
    )
add_executable(deletenodeinBST ${INCLUDED_FILES})
target_link_libraries(deletenodeinBST gtest gmock_main)
cotire(deletenodeinBST)
add_test(NAME deletenodeinBST_test COMMAND deletenodeinBST)
