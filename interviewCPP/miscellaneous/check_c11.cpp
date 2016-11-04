/*
 * check_c11.cpp
 *
 *  Created on: Oct 31, 2016
 *      Author: songjiguo
 */

using namespace std;

#include <iostream>

int main(){
        #if __cplusplus==201402L
        std::cout << "C++14" << std::endl;
        #elif __cplusplus==201103L
        std::cout << "C++11" << std::endl;
        #else
        std::cout << "C++" << std::endl;
        #endif
}
