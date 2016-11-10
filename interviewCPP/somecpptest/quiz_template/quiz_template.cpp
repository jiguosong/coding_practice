/*
 * quiz_template.cpp
 *
 *  Created on: Nov 7, 2016
 *      Author: songjiguo
 */


//templates
//function
template<typename T>
inline void FAST_copy(T& dest, T& src)
{
  dest = src;
}

//TO_DO  ***********
//please write a template specilization for this template function with a class "special_class"
template<>
inline void FAST_copy<class special_class>(special_class& dest, special_class& src)
{
	dest(src);  // assume copy constructor
}



//class
// file my2D.h
template<class X, class Y>
class my2D
{
	X x;
	Y y;
public:
	my2D(X x, Y y){

//TO_DO  ***********
//codes here to set the data member x and y  ************
		this->x.data = x.data;
		this->y.data = y.data;

	}
	X getX();
	Y getY();
};

//TO_DO  ***********
//create a new template class my2D_child which inherits from
//this template with new member function length(),

//write a template specilization of my2D_child for (X=string, Y=string)
//

template<> : my2D<class X, class Y>
class my2Dnew
{
	X x;
	Y y;
public:
	my2Dnew(X x, Y y){

		this->x.data = x.data;
		this->y.data = y.data;

	}

	length(X x) {
		return x.length;
	}
	X getX();
	Y getY();
};


//file my2D.cpp
#include "my2D.h"
//TO_DO *********************
//impletment the function getX and getY in file my2D.cpp

//TO_DO *********************
//implement this length function of my2D_child to return x*x+y*y
//

//add a main function in this cpp file with following
int main()
{
//TO_DO *******************
//to use this my2D template for cases (X=int(3), Y=int(4)), (X=float(5.5), Y=float(6.6),

//TO_DO ********************
//print an output of my2D_child's length for (X="I need ", Y="Time to finish")

return 0;
}


