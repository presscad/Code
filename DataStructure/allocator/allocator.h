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
};

struct list_memory_pool {
	node_memory_pool* first_node_;
	node_memory_pool* last_node_;
	
	list_memory_pool(void* first_memory_pool) {
		node_memory_pool* first = new node_memory_pool();
		first->memory_node_ = first_memory_pool;
		first->next_ = nullptr;
		first_node_ = first;
		last_node_ = first;
	}

	void add_new_memory_pool(void* memory_pool) {
		node_memory_pool* new_pool = new node_memory_pool();
		new_pool->memory_node_ = memory_pool;
		new_pool->next_ = nullptr;
		last_node_->next_ = new_pool;
		last_node_ = new_pool;
	}

	~list_memory_pool() {
		node_memory_pool* current = first_node_;
		node_memory_pool* next = nullptr;
		while(current != nullptr) {
			next = current->next_;
			delete current;
			current = next;
		}
	}
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
