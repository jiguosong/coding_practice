add_executable(slidingwindownmax slidingwindownmax.h slidingwindownmax.cpp slidingwindownmax_test.cpp)
target_link_libraries(slidingwindownmax gtest gmock_main)
cotire(slidingwindownmax)
add_test(NAME slidingwindownmax_test COMMAND slidingwindownmax)


#add_executable(MyExecutable ${MyExecutableSources})
#target_link_libraries(MyExecutable ${MyExecutableLibraries})
