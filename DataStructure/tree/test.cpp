/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/08/2015 15:44:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anh.nqv (), nguyenquocvuonganh1993@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "tree.h"
#include <ctime>
#include <cstdlib>
#include <cstdio>
using namespace std;
using namespace binary_tree;

const int number = 1048576;
int main() {
  tree<int> t;
  srand(time(nullptr));
  for(int i = 0; i < number; i++) {
    int r = rand() % 10000;
    t.AddNode(r);
  }
//  t.TravelTree(t.GetRoot());
  return 0;
}
