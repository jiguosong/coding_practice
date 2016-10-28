/*

 * test_constructions.cpp
 *
 *  Created on: Oct 26, 2016
 *      Author: songjiguo
 */

//please fix the code so that it can be passed in compilation
//after you fix the bug, you run it and you will get many print out like ".... GONE--"
//please explain how those lines are shown up

/*
 * Here is the output after fixing the bugs
 *

haha
 woooz 10 GONE-- 1
-----------
pp caller base
base
pp caller i am child
i am child
pp caller this is child
this is child

 woooz 11 GONE-- 2
 woooz 10 GONE-- 3

 *
 *

Here is my explanation: all "... GONE--" come from the destructor of struct woooz.
 1) First "woooz 10 GONE-- 1" appears because of the line "struct woooz wA=wz1;" in the function "void haha(struct woooz& wz1, struct woooz& wz2)".
   	The copy constructor is used to initialize in the declaration of wA.
 2) Second "woooz 10 GONE-- 2" appears because the thread is leaving the functoin scope and destructor is automatically called
 3) Third "woooz 10 GONE-- 3" appears for the similar reason
*/

#include <iostream>

//int lineC=0;
class app{
public:
	static int lineC;
	int a;
	app(int x):a(x){}
	app() {a=0;};
	app operator+(const int k) const { return app(a + k);}
};

int app::lineC = 0;

struct woooz{
	int b;
	std::string wz;

	woooz(int k, const std::string& kk="WoooZ"):b(k){ wz=kk;}
	~woooz(){
		std::cout << " woooz " << b <<" GONE-- " << ++app::lineC << std::endl;
	}
};

class Handler{
public:
	app m_a;
	struct woooz m_WZ();
	std::string m_name;
	Handler(struct app* a, std::string n){
		m_a=*a;
		m_name=n;
		std::cout << "pp caller " << m_name << std::endl;
	}
};

void haha(struct woooz& wz1, struct woooz& wz2){
	struct woooz wA=wz1;
	struct woooz& wB=wz2;
	struct woooz* pWZ=&wB;
	std::cout << __func__ << std::endl;
}

class chd_handler: public Handler{
public:
	chd_handler(struct app* a): Handler(a, "i am child"){ }
	chd_handler(struct app* a, std::string n):
		Handler(a, n){      }
};

int main()
{
	app a(1);
	app aa=5;
	app a3=aa+1;
	const app ary[20];

	struct woooz wz1(10, "You");
	struct woooz wz2(11, "Me");
	haha(wz1, wz2);

	std::cout << "-----------" << std::endl;

	struct app b = a;
	Handler hb(&b, "base");
	std::cout << hb.m_name << std::endl;
	chd_handler ch(&b);
	std::cout << ch.m_name << std::endl;
	chd_handler ck(&b, "this is child");
	std::cout << ck.m_name << std::endl;
	std::cout << std::endl;
}


