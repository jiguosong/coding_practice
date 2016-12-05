/*
 * helloGotW.cpp
 *
 *  Created on: Dec 5, 2016
 *      Author: songjiguo
 */

class widget {
public:
	widget():X(0){};
	widget(int x):X(x){};
private:
	int X;
};


int main()
{
	// https://herbsutter.com/2013/05/09/gotw-1-solution/
	int x = 10;
	widget w;       // default ctor              // (a)
	widget w2();   // a function return widget   // (b)
	widget w3{};    // default ctor              // (c)
	widget w4(x);     // (d) a compatible type with the constructor argument, with implicit cast allowed    // (d)
	widget w5{x};     // (e) exactly the type with the constructor argument, with no implicit cast allowed OR if widget have an initializer-list constructor // (e)
	widget w6 = x;    // (f)   allow implicit cast
	widget w7 = {x};  // (g)   ???
	auto w8 = x;     // (h) copy initializes a w, with the same type as x (h)
	auto w9 = widget { x };  // (i) copy initialization, and w is going to be of type x // (i)

}

