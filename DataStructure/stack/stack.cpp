/*
 * =====================================================================================
 *
 *       Filename:  stack.cpp
 *
 *    Description: 
 *
 *        Version:  1.0
 *        Created:  04/08/2015 20:46:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anh.nqv (), nguyenquocvuonganh1993@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "stack.h"
using namespace stack;

template <class T>
  node<T>::node() :
    next_(nullptr),
    data_(nullptr)
  {}

template <class T>
  node<T>::~node() noexcept {
    if(next_) {
      delete next_;
      next_ = nullptr;
    }

    if(data_) {
      delete data_;
      data_ = nullptr;
    }
  }
  
template <class T>
  void node<T>::SetNext(node<T>* n) {
    next_ = n;
  }

template <class T>
  void node<T>::SetData(const T& data) {
    if(!data_)
      data_ = new T(data);
    else 
      *data_ = data;
  }

template <class T>
  node<T>* node<T>::GetNext() const {
    return next_;
  }

template <class T>
  T* node<T>::GetData() const {
    return data_;
  }

template <class T>
  Stack<T>::Stack() :
    root_(nullptr)
  {}

template <class T>
  Stack<T>::~Stack() noexcept {
    if(root_) {
      delete root_;
      root_ = nullptr;
    }
  }

template <class T>
  Stack<T>::Stack(const Stack<T>& s) {
    root_ = s.root_;
  }

template <class T>
  Stack<T>::Stack(Stack<T>&& s) {
    root_ = s.root_;
  }

template <class T>
  Stack<T>& Stack<T>::operator=(const Stack<T>& s) {
    root_ = s.root_;
  }

template <class T>
  Stack<T>& Stack<T>::operator=(Stack<T>&& s) {
    root_ = s.root_;
  }

template <class T>
  void Stack<T>::Push(const T& t) {
    node<T>* n = new node<T>();
    n->SetData(t);
    n->SetNext(root_);
    root_ = n;
  }   

template <class T>
  T* Stack<T>::Pop() {
    node<T>* n = root_;
    if(!n)
      return nullptr;
    root_ = n->GetNext();
    return n->GetData();
  }
