add_executable(findvalueinbst findvalueinbst.h findvalueinbst.cpp findvalueinbst_test.cpp)
target_link_libraries(findvalueinbst gtest gmock_main)
cotire(findvalueinbst)
add_test(NAME findvalueinbst_test COMMAND findvalueinbst)
