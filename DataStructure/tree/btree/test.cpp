/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  24/09/2015 21:22:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include "node23.h"
#include <iostream>

int main() {
	node23<int>* templ = new node23<int>;
	node23<float>* templ2 = new node23<float>;
	delete templ;
	delete templ2;
	return 0;
}
