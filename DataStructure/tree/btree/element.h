/*
 * =====================================================================================
 *
 *       Filename:  element.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  24/09/2015 18:09:44
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#ifndef _ELEMENT_H_
#define _ELEMENT_H_

template <typename T>
class node23;
template <typename T>
class element {
	public:
		element();
		element(const element&) = delete;
		element(element&&) = delete;

		~element();

	private:
		node23<T>* smaller_;
		node23<T>* bigger_;
		element* next_;
		T* data_;
};

#include "element.cpp"
#endif
