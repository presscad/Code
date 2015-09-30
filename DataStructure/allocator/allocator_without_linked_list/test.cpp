/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  29/09/2015 22:16:49
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include <iostream>
#include "allocator.h"

int main() {
	allocator<int, 100000>* a = new allocator<int, 100000>();
	for(std::size_t i = 0; i < 10000; i++) {
			int* p = nullptr;
			p = (int*)a->alloc(p);
	}
	delete a;
	return 0;
}

//int main() {
//	for(std::size_t i = 0; i < 10000; i++) {
//		int* p = new int;
//		delete p;
//	}
//}
