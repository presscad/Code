/*
 * =====================================================================================
 *
 *       Filename:  allocator.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  29/09/2015 20:38:44
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#ifndef _ALLOCATOR_WITHOUT_LINKED_LIST_H_
#define _ALLOCATOR_WITHOUT_LINKED_LIST_H_

#include <iostream>

struct memory {
	memory(void* const, void** const);
	memory(const memory&) = delete;
	memory(memory&&);
	~memory();
	void* memory_;
	void** register_;
};

struct node_memory {
	node_memory(void* const, void** const);
	node_memory(const node_memory&) = delete;
	node_memory(node_memory&& node);
	~node_memory();
	memory* node_memory_;
	node_memory* next_;
};

struct list_memory {
	list_memory(void* const, void** const);
	list_memory(const list_memory&) = delete;
	list_memory(list_memory&&);
	~list_memory();

	void add_new_node(void* const, void** const);
	node_memory* root_;
	node_memory* last_;
};


template <typename T, std::size_t size>
class allocator {
	public:
		allocator();
		allocator(const allocator&) = delete;
		allocator(allocator&&);
		~allocator();

		void* alloc(void*);
		void dealloc(void*);

	private:
		void add_new_memory_pool();
	private:
		list_memory* list_memory_;
		void* last_mem_block_;
		void** last_reg_block_;
		mutable std::size_t free_block_;
};

#include "allocator.cpp"
#endif

