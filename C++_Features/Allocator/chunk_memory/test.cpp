/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/09/2015 11:29:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstring>
using namespace std;

int loop = 1000;
struct T {
	double d;
	string s;

	T() : d(0.0), s("abc") {}
};
struct S {
	double d;
	string s;
	T t;
	S() : d(0.0), s("abc"), t() {}
};
void func1() {
	for(int j = 0; j < loop; j++) {
		for(int i = 0; i < loop; i++) {
			S* p = new S();
			delete p;
		}
	}
}

void func2() {
	int size_S = sizeof(S);
	for(int j = 0; j < loop; j++) {
		void* memory = ::operator new(loop*size_S);
		char* templ = (char*)memory;
		for(int i = 0; i < loop; i++) {
			S* p = new(templ) S();
			templ += size_S;
			p->~S();
		}
		::operator delete(memory);
	}
}


int main() {
	func2();
	return 0;
}
