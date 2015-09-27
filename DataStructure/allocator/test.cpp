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

int main() {
	allocator<int, 2>* s = new allocator<int, 2>();

	for(int i = 0; i < 5; i++) {
		int* p = new(s->alloc()) int(4);
		*p = 5;
	}
	delete s;
	return 0;
}


//int main() {
//	for(int i = 0; i < 1000000; i++) {
//		int *p = new int(3);
//		delete p;
//	}
//}
