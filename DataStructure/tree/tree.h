/*
 * =====================================================================================
 *
 *       Filename:  tree.h
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
    class node {
    public:      
      //life cycle
      node();
      node(const node&) = delete;
      node(node&&) = delete;
      virtual ~node() noexcept;

      //prevent assign from other source
      node& operator=(node&) = delete;

      //operator
      bool operator<(const node&);
      bool operator<(node&&);
      bool operator==(const node&);
      bool operator==(node&&);

      //access function
      node** Children() {return child_;};
      node* Left() const {return child_[0];}
      node* Right() const {return child_[1];}      
      node** pLeft() {return child_;}
      node** pRight() {return child_++;}
      T* Data() const {return data_;}
  
      //methods
      void SetLeft(const node* left) {child_[0] = left;}
      void SetRight(const node* right) {child_[1] = right;}
      void SetData(const T& data) {data_ = new T(data);}
      void SetData(T&& data) {data_ = new T(data);}
      
    private:
      //private members
      node* child_[2];
      T* data_;
    };

  template <class T>
    class tree {
    public:
      //life cycle
      tree();
      tree(tree&&);
      virtual ~tree() noexcept;

      //access 
      node<T>* GetRoot() const {return root_;}

      //abadoned function
      tree(const tree&) = delete;
      tree& operator=(tree) = delete;

      //methods
      void AddNode(const T&);
      void TravelTree(node<T>*);

    private:
      node<T>* root_;
    };
}

#include "tree.cpp"
#endif
