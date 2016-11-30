add_executable(validbst validbst.h validbst.cpp validbst_test.cpp)
target_link_libraries(validbst gtest gmock_main)
cotire(validbst)
add_test(NAME validbst_test COMMAND validbst)
