/*
 * =====================================================================================
 *
 *       Filename:  allocator.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  5/09/2015 15:54:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include "allocator.h"
#include <iostream>
#include <cassert>

template <typename T, int size>
allocator<T, size>::allocator() {
	void* memory_pool = get_memory_from_system();
	first_ = (node*)memory_pool;
	first_->prev_ = nullptr;
	free_block_ = first_;

	last_ = (node*)make_memory_become_linked_list(memory_pool);

	list_memory_ = new list_memory_pool(memory_pool);
}

template <typename T, int size>
allocator<T, size>::~allocator() {
	node_memory_pool* current = list_memory_->first_node_;
	node_memory_pool* next = nullptr;
	while(current != nullptr) {
		next = current->next_;
		::operator delete(current->memory_node_);
		current = next;
	}

	delete list_memory_;
}

template <typename T, int size>
void* allocator<T, size>::alloc() {
	if(!free_block_) {
		add_new_memory();
	}

	void* free_block = free_block_;
	free_block_ = free_block_->next_;
	return (void*)((char*)free_block + sizeof(node));
}

template <typename T, int size>
void allocator<T, size>::add_new_memory() {
	void* new_memory = get_memory_from_system();

	last_->next_ = (node*)new_memory;
	if(nullptr == free_block_)
		free_block_ = (node*)new_memory;
	last_ = (node*) make_memory_become_linked_list(new_memory);
}

template <typename T, int size>
void* allocator<T, size>::get_memory_from_system() {
	std::size_t size_block = size*(sizeof(node) + sizeof(T));
	return ::operator new(size_block);
}

template <typename T, int size>
void* allocator<T, size>::make_memory_become_linked_list(void* memory_location) {
	node* current_pos = (node*)memory_location;
	for(int i = 1; i < size - 1; i++) {
		node* pos = current_pos + sizeof(node) + sizeof(T);
		current_pos->next_ = pos;
		pos->prev_ = current_pos;
		current_pos = pos;
	}

	node* last_pos = current_pos + sizeof(node) + sizeof(T);
	current_pos->next_ = last_pos;
	last_pos->prev_ = current_pos;
	last_pos->next_ = nullptr;
	return last_pos;
}

template <typename T, int size>
void allocator<T, size>::dealloc(void* data_location) {
	node* location = (node*) ((char*)data_location - sizeof(node));
	node* prev = ((node*)location)->prev_;
	node* next = ((node*)location)->next_;
	next->prev_ = prev;
	prev->next_ = next;

	last_->next_ = (node*)location;
	((node*)location)->prev_ = last_;
	last_ = location;
}

