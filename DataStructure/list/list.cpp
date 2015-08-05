/*
 * =====================================================================================
 *
 *       Filename:  list.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/08/2015 23:25:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anh.nqv (), nguyenquocvuonganh1993@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "list.h"
using namespace list;

template <class T>
  Node<T>::Node() :
    next_(nullptr),
    prev_(nullptr),
    data_(nullptr) 
  {}

template <class T>
  Node<T>::~Node() {
    if(next_) {
      delete next_;
      next_ = nullptr;
    }

    prev_ = nullptr;
    if(data_) {
      delete data_;
      data_ = nullptr;
    }
  }

template <class T>
  void Node<T>::SetNext(const Node<T>* n) {
    next_ = n;
    n->prev_ = this;
  }

template <class T>
  void Node<T>::SetPrev(const Node<T>* n) {
    prev_ = n;
    n->next_ = this;
  }

template <class T>
  void Node<T>::SetData(const T& data) {
    data_ = new T(data);
  }


template <class T>
  LinkedList<T>::LinkedList() :
    head_(new Node<T>()),
    tail_(new Node<T>())
  {
    head_->SetNext(tail_);
    tail_->SetPrev(head_);
  }

template <class T>
  LinkedList<T>::~LinkedList() {
    tail_ = nullptr;
    if(head_) {
      delete head_;
      head_ = nullptr;
    }
  }

template <class T>
  LinkedList<T>::LinkedList(LinkedList&& l) {
    head_ = l.head_;
    tail_ = l.tail_;
  }

template <class T>
  LinkedList<T>& LinkedList<T>::operator=(LinkedList&& l) {
    if(head_)
      delete head_;
    head_ = l.head_;
    tail_ = l.tail_;
  }

