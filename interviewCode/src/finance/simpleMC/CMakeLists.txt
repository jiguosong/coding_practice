file(GLOB_RECURSE sources
    simpleMC.h simpleMC.cpp 
    random1.h random1.cpp 
    random2.h random2.cpp
    PayOff.h PayOff.cpp
    DoubleDigital.h DoubleDigital.cpp
    Vanilla.h Vanilla.cpp
    PayOffBridge.h PayOffBridge.cpp
    Parameters.h Parameters.cpp
    MCStatistics.h MCStatistics.cpp
    ConvergenceTable.h ConvergenceTable.cpp
    Arrays.h Arrays.cpp
    Normals.h Normals.cpp
    Parameters.h Parameters.cpp
    ParkMiller.h ParkMiller.cpp
    AntiThetic.h AntiThetic.cpp
    simpleMC_test.cpp)
    
add_executable(simpleMC ${sources})
target_link_libraries(simpleMC gtest gmock_main)
cotire(simpleMC)
add_test(NAME simpleMC_testa COMMAND simpleMC)
