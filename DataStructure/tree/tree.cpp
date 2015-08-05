/*
 * =====================================================================================
 *
 *       Filename:  Tree.cpp
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
Node<T>::Node() : 
  child_{nullptr},
  data_(nullptr)
{}

template <class T>
bool Node<T>::operator<(const Node<T>& n) {
  return *data_ < *(n.data_);
}

template <class T>
bool Node<T>::operator<(Node<T>&& n) {
  return *data_ < *(n.data_);
}

template <class T>
bool Node<T>::operator==(const Node<T>& n) {
  return *data_ == *(n.data_);
}

template <class T>
bool Node<T>::operator==(Node<T>&& n) {
  return *data_ == *(n.data_);
}

template <class T>
Node<T>::~Node() noexcept {
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
Tree<T>::Tree() :
  root_(nullptr)
{}

template <class T>
Tree<T>::Tree(Tree&& t) :
  Tree() 
{
  root_ = t.root_;
}

template <class T>
Tree<T>::~Tree<T>() noexcept {
  if(root_) {
    delete root_;
    root_ = nullptr;
  }
}

template <class T>
void swap(Tree<T>& first, Tree<T>& second) {
  using std::swap;
  swap(first.root_, second.root_);
}

template <class T>
Tree<T>& Tree<T>::operator=(Tree<T>&& t) {
  swap(*this, t);
  return *this;
}

template <class T>
void Tree<T>::AddNode(const T& t) {
  Node<T>** p_curr = &root_;
  //make new Node with data is "t"
  Node<T>* n = new Node<T>();
  n->SetData(t);
  //find the position to add new Node
  while(*p_curr != nullptr) {
    p_curr = (*p_curr)->Children() + (**p_curr < *n);
  }
  *p_curr = n;
}

template <class T>
void Tree<T>::AddNodeByCompareFunc(const T& t) {
  Node<T>** p_curr = &root_;
  Node<T>* n = new Node<T>();
  n->SetData(t);
  while(*p_curr != nullptr) {
    p_curr = (*p_curr)->Children() + Compare(t, *(*p_curr)->Data());
  }
  *p_curr = n;
}

template <class T>
void Tree<T>::TravelTree(Node<T>* n) {
  Node<T>** children = n->Children();
  if(*children)
    TravelTree(*children);
  cout << *(n->Data()) << endl;
  children++;
  if(*children)
    TravelTree(*children);
}
