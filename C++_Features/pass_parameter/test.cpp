/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  14/09/2015 19:22:40
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
		T(const int& a = 0) : a_(a) {}
		T(const T& t) : a_(t.a_) 
	{
		std::cout << "T: Copy constructor!" << std::endl;
	}	
		T(T&& t) : a_(t.a_) 
	{
		std::cout << "T: Move constructor!" << std::endl;
	}
	public:
		int a_;
};

T init() {
	return T(12);
}

void the_game(T t) {
	int a = 0;
	return;
}


int main() {
	the_game(std::move(init()));
	return 0;
}
