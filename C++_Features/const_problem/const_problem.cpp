/*
 * =====================================================================================
 *
 *       Filename:  const_problem.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  16/08/2015 13:51:03
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Anh.nqv (), nguyenquocvuonganh1993@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct S {
  int a;
  char* s;
  S(const int a_ = 0, char* s_ = nullptr) : a(a_), s(s_) {}

  char& GetFirstChar() const {
    return s[0];
  }

  void ChangeValue() {
    a = 12;
  }
};

int main () {
  char str[4] = "abc";
  const S s1(1, str);               //expect s1's value can't be modified: a = 1, s = str
  char* pc = &s1.GetFirstChar();    //Call to const function. Ok. Compile is so happy with this.
  *pc = 't';                        //Opps!!! We change the value of some bits in the s1.s
  cout << s1.s << endl;             //s1.s = "tbc" => bitwise const.
  //s1.ChangeValue();       => Illegal. Great. Because void ChangeValue() is void S::ChangeValue()
  return 0;
}


//Solution:
//We may provide 2 versions of this function. const and non-const version.
//To avoid duplication code. We may call the const version of the function in the non-const version. 
