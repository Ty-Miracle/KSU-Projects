/*
 * Tyler Miracle
 * bigint_cpp
 * CS2 23001
 * 09/15/2016
*/
#include "bigint.hpp"
#ifndef CS2_BIGINT_CPP
#define CS2_BIGINT_CPP

bigint::bigint(){                        //intializes array to 0
  for(int i=0; i<BIGINT_SIZE; i++){
    a[i] = 0;
  }
}

bigint::bigint(int number) : bigint() {
  int elem=0;
  while(number != 0){
    int n= number%10;
    a[elem]=n;
    number/=10;
    ++elem;
  }
}

bigint::bigint(const char that[]) : bigint() {
  int elem=0;
  while(that[elem] != '\0'){
    ++elem;
}
  --elem;
  for(int i =0; that[i] != '\0'; ++i, --elem){
    a[elem] = (int(that[i])-int('0'));
  }
}

void bigint::debug_print(std::ostream& out) const{         //Prints array
  out << "|";
  for(int i=BIGINT_SIZE-1; i >=0; --i)
    out << a[i]<<"|";
}

bool bigint::operator == (const bigint& rhs)const{
  for(int i=0; i < BIGINT_SIZE;++i){
    if(a[i] != rhs.a[i]) return false;
  }return true;
}

std::ostream& operator <<(std::ostream& out, const bigint& num){
  int count=0;
  int i=1;
  int bigi = BIGINT_SIZE-1;
  while( num.a[bigi]== 0){
    --bigi;
}
  while(bigi >=0){
    out << num.a[bigi];
    ++count, --bigi;
    if(count == 70*i){
      out << "\n";
      ++i;
    }
  }
  if(count == 0){
    out << 0;
  }
  return out;
}

std::istream& operator >>(std::istream& in,bigint& num){
  int elem=0;
  char position;
  char ch[BIGINT_SIZE];

  in >> position;                         //position in file(num [0-9])
  while(position != ';' && !in.eof()){    //eof = end of file
    ch[elem] = position;                  //[0-9]based off file
    in >> position;                       //new pos
    ++elem;
  }
  ch[elem]=0;                             //null
  num = bigint(ch);

  return in;
}
/*
int bigint::operator[](int i){
  int x;
  int count=0;
  int power=1;
  if(i != 0){
    while(count !=i){
      power= power * 10;
      ++count;
    }
    x = a[i]*power;
  }
  else {
    x = a[i];
  }
return x;
}
*/

int bigint::operator[](int i){
  return a[i];
}
int bigint::operator[](int i)const{
  return a[i];
}

bigint bigint::operator+(bigint rhs)const{
  int i=0;
  int rem=0;
  int value=0;

  while(i<BIGINT_SIZE){
    rem= rhs.a[i] + a[i] + rem;          //rem carries 1's through iterations
    value = rem%10;
    rem /= 10;
    rhs.a[i]=value;
    ++i;
}
return rhs;
}
//here
bigint bigint::operator * (const bigint& rhs)const {
  bigint result, partial =*this;
  for (int i=0;i < BIGINT_SIZE;++i, partial=*this){
    partial.times_single_digit(rhs[i]);
    partial.times_10(i);
    result = result + partial;
  }
  return result;
}

void bigint::times_single_digit(const int x){
  int place_value = 0;
  int carry = 0;
  for(int i=0; i<BIGINT_SIZE;++i){
    place_value = (x * a[i]) + carry;
    carry = place_value / 10;
    a[i]=place_value %10;
  }
}

void bigint::times_10(const int x){
  for(int i = (BIGINT_SIZE -1); i>= 0;--i){
    a[i]= a[i-x];                       //shifts
}

  for (int i=(x-1); i>=0;--i){
    a[i]=0;
    }
}

/*
prob 20 * 15, it computes 5 * 20 correctly but when it does 10 * 20 it adds an additional zero."
*/

#endif
