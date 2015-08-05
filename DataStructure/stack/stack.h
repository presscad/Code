/*
 * =====================================================================================
 *
 *       Filename:  stack.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/08/2015 20:32:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anh.nqv (), nguyenquocvuonganh1993@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef _STACK_H_
#define _STACK_H_
namespace stack {
  template <class T>
    class Node {
    public:
      Node();
      virtual ~Node() noexcept;
      Node(const Node&) = delete;
      Node(Node&&) = delete;

      Node& operator=(Node) = delete;
      void SetNext(Node*);
      void SetData(const T&);
      Node* GetNext() const;
      T* GetData() const;
    private:
      Node* next_;
      T* data_;
    };


  template <class T>
    class Stack {
    public:
      Stack();
      virtual ~Stack() noexcept;
      Stack(const Stack&);
      Stack(Stack&&);

      Stack& operator=(const Stack&);
      Stack& operator=(Stack&&);

      void Push(const T&);
      T* Pop();
      Stack* Clone();
    private:
      Node<T>* root_;
    };
}

#include "stack.cpp"
#endif
