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
    class node {
    public:
      node();
      virtual ~node() noexcept;
      node(const node&) = delete;
      node(node&&) = delete;

      node& operator=(node) = delete;
      void SetNext(node*);
      void SetData(const T&);
      node* GetNext() const;
      T* GetData() const;
    private:
      node* next_;
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
    private:
      node<T>* root_;
    };
}

#include "stack.cpp"
#endif
