/*
 * =====================================================================================
 *
 *       Filename:  allocator.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  29/09/2015 21:34:39
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
#include <utility>



//struct memory implement
//==============================================
memory::memory(void* const mem, void** const reg) :
	memory_(mem),
	register_(reg) {}

memory::memory(memory&& mem) :
	memory_(std::move(mem.memory_)),
	register_(std::move(mem.register_)) {}

memory::~memory() {
	::operator delete(memory_);
	delete[] register_;
}
//==============================================
//struct node_memory implement
//==============================================
node_memory::node_memory(void* const mem, void** const reg) :
	node_memory_(new memory(mem, reg)), 
	next_(nullptr) {}

node_memory::node_memory(node_memory&& node) :
	node_memory_(std::move(node.node_memory_)),
	next_(std::move(node.next_)) {}

node_memory::~node_memory() {
	delete node_memory_;
}
//==============================================
//struct list_memory implement
//==============================================
	list_memory::list_memory(void* const mem, void** const reg) :
		root_(new node_memory(mem, reg)),
		last_(root_) {}
	
	list_memory::list_memory(list_memory&& list) :
		root_(std::move(list.root_)),
		last_(std::move(list.last_)) {}
	
	void list_memory::add_new_node(void* const mem, void** const reg) {
		last_->next_ = new node_memory(mem, reg);
		last_ = last_->next_;
	}

	list_memory::~list_memory() {
		node_memory* current = root_;
		while(current != nullptr) {
			node_memory* next = current->next_;
			delete current;
			current = next;
		}
	}
//==============================================
//template class allocator implement
//==============================================
template <typename T, std::size_t size>
allocator<T, size>::allocator() {
	void* mem = ::operator new(size*sizeof(T));
	void** reg = new void*[size*sizeof(T*)];
	list_memory_ = new list_memory(mem, reg);
	free_block_ = size;
	last_mem_block_ = (char*)mem + size*sizeof(T);
	last_reg_block_ = reg + size*sizeof(T*);
}
template <typename T, std::size_t size>
allocator<T, size>::allocator(allocator&& a) :
	list_memory_(std::move(a.list_memory_)),
	last_mem_block_(std::move(a.last_mem_block_)),
	last_reg_block_(std::move(a.last_reg_block_)),
	free_block_(std::move(a.free_block_)) {}

template <typename T, std::size_t size>
void* allocator<T, size>::alloc(void* ownship_last_block) {
	if(0 == free_block_)
		add_new_memory_pool();

	T** reg_pos = (T**)(last_reg_block_ - free_block_*sizeof(T*));
	reg_pos = (T**)&ownship_last_block;
	free_block_--;
	return (char*)last_mem_block_ - (free_block_ + 1)*sizeof(T);
}

template <typename T, std::size_t size>
void allocator<T, size>::dealloc(void* position) {
	((T*)position)->~T();
	void* last_block = (char*)last_mem_block_ - (free_block_ + 1)*sizeof(T);
	std::swap(*((T*)last_block), *((T*)position));
	free_block_++;
}

template <typename T, std::size_t size>
void allocator<T, size>::add_new_memory_pool() {
	void* mem = ::operator new(size*sizeof(T));
	void** reg = new void*[size*sizeof(T*)];
	list_memory_->add_new_node(mem, reg);
	free_block_ = size;
	last_mem_block_ = (char*)mem + size*sizeof(T);
}

template <typename T, std::size_t size>
allocator<T, size>::~allocator() {
	delete list_memory_;
}
//==============================================
