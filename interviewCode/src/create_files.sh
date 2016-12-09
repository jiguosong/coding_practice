#!/bin/sh

MYCM=$1

bpath='/home/songjiguo/workspace/interviewCode/src/'

mkdir $MYCM
echo add_subdirectory\($MYCM\) >> CMakeLists.txt

sed -e s/XXX/$MYCM/g $bpath/CMakeLists_template.txt > $MYCM/CMakeLists.txt
sed -e s/XXX/$MYCM/g $bpath/gtest_template.cpp > $MYCM/$MYCM\_test.cpp
sed -e s/XXX/$MYCM/g $bpath/header_template.h > $MYCM/$MYCM.h
sed -e s/XXX/$MYCM/g $bpath/cpp_template.cpp > $MYCM/$MYCM.cpp
