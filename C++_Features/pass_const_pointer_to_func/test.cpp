/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  27/09/2015 11:22:33
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

void func(int* const p) {
	int* q = p;   //<----- assign the pointer q by pointer p. 
	q++;          //<----- ofcouse. But care this scence. 
//	p = q;     <---- error. Can't assign to p because p is const. 
}

void func2(const int* p) {
	int* q = new int();  //<----- make new pointer to int.
	p = q;               //<----- alright. p is a pointer which point to const value
//	*p = 12;     <----  ERROR. Can't assign to value which p point to. 
}

int main() {

	return 0;
}
