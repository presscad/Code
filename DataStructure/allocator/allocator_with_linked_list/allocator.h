/*
 * =====================================================================================
 *
 *       Filename:  allocator.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  25/09/2015 08:02:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef _ALLOCATOR_H_
#define _ALLOCATOR_H_

struct node {
	node* next_;
	node* prev_;
};

struct node_memory_pool {
	void* memory_node_;
	node_memory_pool* next_;

	node_memory_pool(void* const = nullptr);

	node_memory_pool(node_memory_pool&&);
	node_memory_pool(const node_memory_pool&) = delete;
};

struct list_memory_pool {
	node_memory_pool* first_node_;
	node_memory_pool* last_node_;
	
	list_memory_pool(void* const);

	list_memory_pool(const list_memory_pool&) = delete;
	list_memory_pool(list_memory_pool&&);

	void add_new_memory_pool(void* const);

	~list_memory_pool();
};

template <typename T, int size>
class allocator {
	public:
		allocator();
		allocator(const allocator&) = delete;
		allocator(allocator&&) = delete;

		~allocator();

		void* alloc();
		void dealloc(void*);
	private:
		void* get_memory_from_system();
		void* make_memory_become_linked_list(void* const);
		void add_new_memory();
	private:
		list_memory_pool* list_memory_;
		node* first_;
		node* last_;
		node* free_block_;
};

#include "allocator.cpp"
#endif
