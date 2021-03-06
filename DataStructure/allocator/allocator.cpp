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


//struct node_memory_pool implement
//=================================================
node_memory_pool::node_memory_pool(void* const memory_node) :
	memory_node_(memory_node),
	next_(nullptr) {}

node_memory_pool::node_memory_pool(node_memory_pool&& node) :
	memory_node_(std::move(node.memory_node_)),
	next_(std::move(node.next_)) {}
//=================================================


//struct list_memory_pool implement
//=================================================
list_memory_pool::list_memory_pool(void* const first_node) :
	first_node_(new node_memory_pool(first_node)),
	last_node_(first_node_) {}

	list_memory_pool::list_memory_pool(list_memory_pool&& list) :
	first_node_(std::move(list.first_node_)),
	last_node_(std::move(list.last_node_)) {}

void list_memory_pool::add_new_memory_pool(void* const memory_pool) {
	last_node_->next_ = new node_memory_pool(memory_pool);
	last_node_ = last_node_->next_;
}

list_memory_pool::~list_memory_pool() {
	node_memory_pool* next_node = first_node_->next_;
	for(node_memory_pool* current = first_node_; current != nullptr; current = next_node) {
		next_node = current->next_;
		delete current;
	}
}
//=================================================


//template class allocator implement
//=================================================
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
	list_memory_->add_new_memory_pool(new_memory);

	last_->next_ = (node*)new_memory;
	assert(!free_block_);
	free_block_ = (node*)new_memory;
	last_ = (node*) make_memory_become_linked_list(new_memory);
}

template <typename T, int size>
void* allocator<T, size>::get_memory_from_system() {
	std::size_t size_block = size*(sizeof(node) + sizeof(T));
	return ::operator new(size_block);
}

template <typename T, int size>
void* allocator<T, size>::make_memory_become_linked_list(void* const memory_location) {
	void* current_pos = memory_location;
	for(int i = 1; i < size - 1; i++) {
		node* pos = (node*)((char*)current_pos + sizeof(node) + sizeof(T));
		((node*)current_pos)->next_ = pos;
		pos->prev_ = (node*)current_pos;
		current_pos = pos;
	}

	node* last_pos = (node*)((char*)current_pos + sizeof(node) + sizeof(T));
	((node*)current_pos)->next_ = last_pos;
	last_pos->prev_ = (node*)current_pos;
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

//===================================================
