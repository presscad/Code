/*
 * =====================================================================================
 *
 *       Filename:  element.cpp
 *
 *    Description: 
 *
 *        Version:  1.0
 *        Created:  24/09/2015 21:18:19
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include "element.h"
#include "node23.h"

template <typename T>
element<T>::element() {
	void* node = ::operator new(sizeof(node23<T>)*2);
	smaller_ = (node23<T>*)node;
	bigger_ = ((node23<T>*)node)[1];
	next_ = nullptr;
}

template <typename T>
element<T>::~element() {
	smaller_->~node23();
	bigger_->~node23();
	::operator delete(smaller_);
}
