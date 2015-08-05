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
    if(data_) {
      delete data_;
      data_ = nullptr;
    }
    next_ = nullptr;
    prev_ = nullptr;
  }

template <class T>
  void Node<T>::SetNext(Node<T>* n) {
    next_ = n;
    n->prev_ = this;
  }

template <class T>
  void Node<T>::SetPrev(Node<T>* n) {
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
    for(auto ii = head_->Next(); ii != tail_->Next();ii = ii->Next()) {
      delete ii->Prev();
    }
    delete tail_;
    tail_ = nullptr;
    head_ = nullptr;
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

template <class T>
  void LinkedList<T>::PushFront(const T& t) {
    Node<T>* n = new Node<T>();
    n->SetData(t);
    n->SetNext(head_->Next());
    head_->SetNext(n);
    n->Next()->SetPrev(n);
    n->SetPrev(head_);
  }

template <class T>
  void LinkedList<T>::PushBack(const T& t) {
    Node<T>* n = new Node<T>();
    n->SetData(t);
    n->SetPrev(tail_->Prev());
    n->SetNext(tail_);
    tail_->SetPrev(n);
    n->Prev()->SetNext(n);
  }

template <class T>
  T* LinkedList<T>::PopFront() {
    if(head_->Next() == tail_)
      return nullptr;
    Node<T>* ret = head_->Next();
    head_->SetNext(ret->Next());
    ret->Next()->SetPrev(head_);
    return ret->Data();
  }

template <class T>
  T* LinkedList<T>::PopBack() {
    if(head_->Next() == tail_)
      return nullptr;
    Node<T>* ret = tail_->Prev();
    tail_->SetPrev(ret->Prev());
    ret->Prev()->SetNext(tail_);
    return ret->Data();
  }


