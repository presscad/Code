/*
 * =====================================================================================
 *
 *       Filename:  list.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/08/2015 22:10:27
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anh.nqv (), nguyenquocvuonganh1993@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef _LIST_H_
#define _LIST_H_

namespace stc {
  template <class T>
    class Node {
    public:
      Node(const T&,
           Node* next = nullptr,
           Node* prev = nullptr);
      Node(T&&,
           Node* next = nullptr,
           Node* prev = nullptr);
      Node(Node* next = nullptr,
           Node* prev = nullptr);
      Node(Node&&);
      virtual ~Node();


      //abadonned functions
      Node(const Node&) = delete;
      Node& operator=(const Node&) = delete;
      Node& operator=(Node&&) = delete;

      //access
      Node* Next() const {return next_;}
      Node* Prev() const {return prev_;}
      T* Data() const {return data_;}
      void SetNext(Node*);
      void SetPrev(Node*);
      void SetData(const T&);
      void SetData(T&&);
      void SetDataWithNull(const T&);
      void SetDataWithNull(T&&);
    private:
      Node* next_;
      Node* prev_;
      T* data_;
    };

  template <class T>
    class LinkedList {
    public:
      LinkedList();
      LinkedList(LinkedList&&);
      virtual ~LinkedList();
      LinkedList& operator=(LinkedList&&);

      //abadonned functions
      LinkedList(const LinkedList&) = delete;
      LinkedList& operator=(const LinkedList&) = delete;

      void PushBack(const T&);
      void PushBack(T&&);
    private:
      Node<T>* head_;
      Node<T>* tail_;
    };
}

#include "list.cpp"

#endif
