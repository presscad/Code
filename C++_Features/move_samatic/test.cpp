/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14/09/2015 00:54:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>

class S {
	public:
		S(const int& a = 0) : a_(a) {}
		S(const S& s) : a_(s.a_) {
			std::cout << "S: This is copy constructor!" << std::endl;
		}
		S(S&& s) noexcept : a_(s.a_) {
			std::cout << "S: This is move constructor!" << std::endl;
		}
	public:
		int a_;
};

class T {
	public:
		T(const int& a = 0) : s_(a) {}
		T(const T& t) : s_(t.s_){
			std::cout << "T: This is copy constructor!" << std::endl;
		}
		T(T&& t) noexcept : s_(std::move(t.s_)) {  
			std::cout << "T: This is move constructor!" << std::endl;
		}
	public:
		S s_;
};

T init() {
	return T(12);
}

T init2(T t) {
	std::cout << "ABC" << std::endl;
	return t;
}

int main() {
	T t1(init());				//<------ This won't call Move_Constructor! Because the return of init() is prvalue. 
	T t2(init2(T()));	  //<------ Call Move_Constructor
	T t3(init2(t1));    //<------ Call Move_constructor 2 times. one is initial of the parameter of init2
											// other is constructor of t3. 
	return 0;
}
