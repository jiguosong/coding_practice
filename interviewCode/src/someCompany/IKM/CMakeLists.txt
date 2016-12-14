add_executable(IKM IKM.h IKM.cpp IKM_test.cpp)
target_link_libraries(IKM gtest gmock_main)
cotire(IKM)
add_test(NAME IKM_test COMMAND IKM)
