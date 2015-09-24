/*
 * =====================================================================================
 *
 *       Filename:  node23.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  24/09/2015 18:08:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#ifndef _NODE23_H_
#define _NODE23_H_

#include "element.h"

template <typename T>
class node23 {
	public:
		node23();
		node23(const node23&) = delete;
		node23(node23&&) = delete;

		virtual ~node23();

		virtual node23* insert(const T&);
		element<T>* split();
	private:
		element<T>* first_;
		element<T>* second_;
		void* current_pos_;
};

template <typename T>
class leave23 : public node23<T> {
	public:
		leave23() : node23<T>() {}
		node23<T>* insert(const T&) override;
};

#include "node23.cpp"

#endif
