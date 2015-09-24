/*
 * =====================================================================================
 *
 *       Filename:  Tree.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  31/07/2015 22:13:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anh.nqv (), nguyenquocvuonganh1993@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


#ifndef _TREE_H_
#define _TREE_H_

namespace binary_tree {
  template <class T>
    class Node {
    public:      
      //life cycle
      Node();
      Node(const Node&) = delete;
      Node(Node&&) = delete;
      virtual ~Node() noexcept;

      //prevent assign from other source
      Node& operator=(const Node&) = delete;
      Node& operator=(Node&&) = delete;

      //operator
      bool operator<(const Node&);
      bool operator<(Node&&);
      bool operator==(const Node&);
      bool operator==(Node&&);

      //access function
      Node** Children() {return child_;};
      Node* Left() const {return child_[0];}
      Node* Right() const {return child_[1];}      
      Node** pLeft() {return child_;}
      Node** pRight() {return child_++;}
      T* Data() const {return data_;}
  
      //methods
      void SetLeft(const Node* left) {child_[0] = left;}
      void SetRight(const Node* right) {child_[1] = right;}
      void SetData(const T& data) {data_ = new T(data);}
      void SetData(T&& data) {data_ = new T(data);}
      
    private:
      //private members
      Node* child_[2];
      T* data_;
    };

  template <class T>
    class Tree {
    public:
      //life cycle
      Tree();
      Tree(Tree&&);
      Tree(const Tree&) = delete;
      virtual ~Tree() noexcept;

      //access 
      Node<T>* GetRoot() const {return root_;}

      //assign operator
      Tree& operator=(const Tree&) = delete;
      Tree& operator=(Tree&&);
      template <class U>
      friend void swap(Tree<U>&, Tree<U>&);

      //methods
      void AddNode(const T&);
      void AddNodeByCompareFunc(const T&);
      void TravelTree(Node<T>*);

    public:
      int (*Compare)(const T&, const T&);
    private:
      Node<T>* root_;
    };
}

#include "tree.cpp"
#endif
