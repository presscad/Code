/*
 * =====================================================================================
 *
 *       Filename:  list.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/08/2015 20:01:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anh.nqv (), nguyenquocvuonganh1993@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

namespace list {
  template <class T>
    class Node {
    public:
      Node();
      virtual ~Node();

      //abadonned function
      Node(const Node&) = delete;
      Node(Node&&) = delete;
      Node& operator=(Node) = delete;

      //access function
      Node** pNext() {return &next_;}
      Node** pPrev() {return &prev_;}
      Node* Next() const {return next_;}
      Node* Prev() const {return prev_;}
      T** pData() {return &data_;}
      T* Data() {return data_;}

      void SetNext(Node*);
      void SetPrev(Node*);
      void SetData(const T&);
    private:
      Node* next_;
      Node* prev_;
      T* data_;
    };
  template <class T>
    class LinkedList {
    public:
      LinkedList();
      virtual ~LinkedList();
      LinkedList(LinkedList&&);
      LinkedList& operator=(LinkedList&&);

      //abadonned function
      LinkedList(const LinkedList&) = delete;
      LinkedList& operator=(const LinkedList&) = delete;

      //access function
      Node<T>* Head() const {return head_;}
      Node<T>* Tail() const {return tail_;}


      //
      void PushFront(const T&);
      //
      void PushBack(const T&);
      //
      T* PopFront();
      //
      T* PopBack();

      //Insert the single node "source" after node in list.
      //
      void InsertAfter(Node<T>* const source , Node<T>* const ins);
      //
      void InsertBefore(Node<T>* const source, Node<T>* const ins);

      //Insert a sub-list after a node in list
      void InsertAfter(Node<T>* const, Node<T>* const, Node<T>* const);
      //
      void InsertBefore(Node<T>* const, Node<T>* const, Node<T>* const);

      //Insert a single node before a node in list
      //Delete a single node
      void Delete(Node<T>*);
      //Delete "n" consecutive nodes
      void Delete(Node<T>*, int n);
      //Delete a sub-list in list. 
      void Delete(Node<T>*, Node<T>*);

      //Sort list with operator <
      void Sort();
      //Sort list with a function pointer
      void Sort(bool (*Compare)(const T&, const T&));
      
    private:
      Node<T>* head_;
      Node<T>* tail_;
    };
}

#include "list.cpp"
#endif
