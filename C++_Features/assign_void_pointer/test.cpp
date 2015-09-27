/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  25/09/2015 14:51:19
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>

struct S {
	int a;
	double d;
	S(int aa = 0, double dd = 0.0) : a(aa), d(dd) {}
};

int main() {
	void* p = ::operator new(sizeof(4));
	int* ptr = (int*)p;
	*ptr = 4;
	int a = *ptr;
	a++;
	::operator delete(p);

	void* q = ::operator new(sizeof(S));
	S* templ = new(q) S();
	templ->a = 12;
	templ->d = 12.2;
	templ->~S();
	::operator delete(q);
	
	return 0;
}
