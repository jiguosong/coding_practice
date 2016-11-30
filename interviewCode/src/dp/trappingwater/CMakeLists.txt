add_executable(trappingwater trappingwater.h trappingwater.cpp trappingwater_test.cpp)
target_link_libraries(trappingwater gtest gmock_main)
cotire(trappingwater)
add_test(NAME trappingwater_test COMMAND trappingwater)


#add_executable(MyExecutable ${MyExecutableSources})
#target_link_libraries(MyExecutable ${MyExecutableLibraries})
