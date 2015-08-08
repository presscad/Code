/*
 * =====================================================================================
 *
 *       Filename:  list.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/08/2015 22:21:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anh.nqv (), nguyenquocvuonganh1993@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "list.h"

using namespace stc;

template <class T>
  Node<T>::Node(const T& t,
                Node* next,
                Node* prev) :
    next_(next),
    prev_(prev) {
      data_ = new T(t);
    }

template <class T>
  Node<T>::Node(T&& t,
                Node* next,
                Node* prev) :
    next_(next),
    prev_(prev) {
      data_ = new T(t);
    }

template <class T>
  Node<T>::Node(Node* next,
                Node* prev) :
    next_(next),
    prev_(prev),
    data_(nullptr) {}

template <class T>
  Node<T>::Node(Node&& n) {
    next_ = n.next_;
    prev_ = n.prev_;
    data_ = n.data_;
  }

template <class T>
  Node<T>::~Node() {
    next_ = nullptr;
    prev_ = nullptr;
    if(data_) {
      delete data_;
      data_ = nullptr;
    }
  }

template <class T>
  void Node<T>::SetNext(Node<T>* n) {
    next_ = n;
  }

template <class T>
  void Node<T>::SetPrev(Node<T>* n) {
    prev_ = n;
  }

template <class T>
  void Node<T>::SetData(const T& t) {
    if(!data_)
      data_ = new T(t);
    else
      *data_ = t;
  }

template <class T>
  void Node<T>::SetData(T&& t) {
    if(!data_)
      data_ = new T(t);
    else
      *data_ = t;
  }

template <class T> 
  void Node<T>::SetDataWithNull(const T& t) {
    data_ = new T(t);
  }

template <class T>
  void Node<T>::SetDataWithNull(T&& t) {
    data_ = new T(t);
  }


template <class T>
  LinkedList<T>::LinkedList() :
    head_(new Node<T>()),
    tail_(new Node<T>()) {
      head_->SetNext(tail_);
      tail_->SetPrev(head_);
    }

template <class T>
  LinkedList<T>::LinkedList(LinkedList<T>&& l) :
    head_(l.head_),
    tail_(l.tail_) {}

template <class T>
  LinkedList<T>::~LinkedList() {
    for(auto ii = head_->Next(); ii != nullptr; ii = ii->Next())
      delete ii->Prev();

    delete tail_;
    head_ = nullptr;
    tail_ = nullptr;
  }

template <class T>
  LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>&& l) {
    for(auto ii = head_->Next(); ii != nullptr; ii = ii->Next())
      delete ii->Prev();

    delete tail_;

    head_ = l.head_;
    tail_ = l.tail_;

    return *this;
  }

template <class T> 
  void LinkedList<T>::PushBack(const T& t) {
    tail_->SetDataWithNull(t);
    Node<T>* n = new Node<T>(nullptr, tail_);
    tail_->SetNext(n);
    tail_ = n;
  }

template <class T>
  void LinkedList<T>::PushBack(T&& t) {
    tail_->SetDataWithNull(t);
    Node<T>* n = new Node<T>(nullptr, tail_);
    tail_->SetNext(n);
    tail_ = n;
  }
