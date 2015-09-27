/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  16/09/2015 13:24:56
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>

class T {
	public:
		T(const int& a = 0) :
			a_(a),
			p_(new int) {}
		T(const T& t) : 
			a_(t.a_),
			p_(new int) {}
		T(T&& t) : 
			a_(std::move(t.a_)),
			p_(std::move(t.p_)) {}
		~T() {
			std::cout << "T: This is destructor" << std::endl;
			std::cout << "T: a = " << a_ << std::endl;
			if(p_)
				delete p_;
		}
		T& operator=(T&& t) {
			std::swap(a_, t.a_);
			std::swap(p_, t.p_);
			return *this;
		}
	private:
		int a_;
		int* p_;
};


T init() {
	return T(12);
}


int main() {
	T t1(10);
	t1 = std::move(init());
	return 1;
}
