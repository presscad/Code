/*
 * =====================================================================================
 *
 *       Filename:  tree.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  31/07/2015 23:05:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anh.nqv (), nguyenquocvuonganh1993@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "tree.h"
#include <cstdlib>
#include <iostream>
using namespace binary_tree;
using namespace std;

template <class T> 
node<T>::node() : 
  child_{nullptr},
  data_(nullptr)
{}

template <class T>
node<T>::node(const node& n) : 
  node<T>()
{
  data_ = new T(*n.data_);
}

template <class T>
node<T>::node(node&& n) : 
  node<T>() 
{
  delete data_;
  data_ = n.data_; 
}

template <class T>
bool node<T>::operator<(const node<T>& n) {
  return *data_ < *(n.data_);
}

template <class T>
bool node<T>::operator<(node<T>&& n) {
  return *data_ < *(n.data_);
}

template <class T>
bool node<T>::operator==(const node<T>& n) {
  return *data_ == *(n.data_);
}

template <class T>
bool node<T>::operator==(node<T>&& n) {
  return *data_ == *(n.data_);
}

template <class T>
node<T>::~node() noexcept {
  if(*child_) {
    delete *child_;
    *child_ = nullptr;
  }

  if(child_[1]) {
    delete child_[1];
    child_[1] = nullptr;
  }
}

template <class T>
tree<T>::tree() :
  root_(nullptr)
{}

template <class T>
tree<T>::tree(tree&& t) :
  tree() 
{
  root_ = t.root_;
}

template <class T>
tree<T>::~tree<T>() noexcept {
  if(root_) {
    delete root_;
    root_ = nullptr;
  }
}
template <class T>
void tree<T>::AddNode(const T& t) {
  node<T>** p_curr = &root_;
  //make new node with data is "t"
  node<T>* n = new node<T>();
  n->SetData(t);
  //find the position to add new node
  while(*p_curr != nullptr) {
    p_curr = (*p_curr)->Children() + (**p_curr < *n);
  }
  *p_curr = n;
}

template <class T>
void tree<T>::TravelTree(node<T>* n) {
  node<T>** children = n->Children();
  if(*children)
    TravelTree(*children);
  cout << *(n->Data()) << endl;
  children++;
  if(*children)
    TravelTree(*children);
}
