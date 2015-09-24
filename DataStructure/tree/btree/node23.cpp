/*
 * =====================================================================================
 *
 *       Filename:  node23.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  24/09/2015 20:59:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "node23.h"

template <typename T>
node23<T>::node23() {
	void* elements = ::operator new(sizeof(element<T>)*2);
	first_ = (element<T>*)elements;
	second_ = &((element<T>*)elements)[1];
	current_pos_ = first_;
}

template <typename T>
node23<T>::~node23() {
	::operator delete((void*)first_);
	current_pos_ = nullptr;
}

template <typename T>
node23<T>* node23<T>::insert(const T& data) {
	return nullptr;
}

template <typename T>
element<T>* split() {
	return nullptr;
}

template <typename T>
node23<T>* leave23<T>::insert(const T& data) {
	return nullptr;
}
