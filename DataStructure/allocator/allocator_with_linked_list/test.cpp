/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  25/09/2015 23:22:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include "allocator.h"
#include <iostream>
#include <list>

const std::size_t size = 100;


struct S {
	int i;
	double d;
	S(const int& ii = 0, const double& dd = 0.0) : i(ii), d(dd) {}
};


using ALLOCATOR = allocator<S, size>;

int main() {
	ALLOCATOR* s = new ALLOCATOR();

	for(std::size_t j = 0; j < 100000; j++) {
		for(std::size_t i = 0; i < size; i++) {
			S* p = new(s->alloc()) S(4, 4.4);
			p->~S();
		}
	}
	delete s;
	return 0;
}


//int main() {
//	for(int j = 0; j < 100; j++) {
//		for(std::size_t i = 0; i < size; i++) {
//			S* p = new S(4, 4.4);
//			delete p;
//		}
//	}
//	return 0;
//}
//
//
