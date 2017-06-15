/*
 * Tyler Miracle
 * Bigint_hpp
 * CS2 23001
 * 09/15/2017
 */
#include <iostream>
#ifndef CS2_BIGINT_HPP
#define CS2_BIGINT_HPP


const int BIGINT_SIZE = 156;                    //Global constant - Size of bigint

class bigint {
public:

  bigint();
  bigint(int x);
  bigint(const char a[]);
  void  debug_print(std::ostream&) const;
  friend std::ostream& operator<<(std::ostream&, const bigint&);
  friend std::istream& operator>>(std::istream&, bigint&);
  bool operator ==(const bigint&)const;
  bigint operator+(bigint rhs)const;
  int operator[](int i);
  int operator[](int i)const;
  bigint operator *(const bigint&)const;
  void times_10(const int);
  void times_single_digit(const int);

private:
  int a[BIGINT_SIZE];
};

#endif
