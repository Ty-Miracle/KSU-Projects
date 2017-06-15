/*
 * Tyler Miracle
 * 2/25/17
 * String program
 * CS23001
*/

#include "string.hpp"
#include <vector>
#include <cassert>
#ifndef CS23001_STRING_CPP
#define CS23001_STRING_CPP


//constructors----------------
String::String(){
  string_size = 1;
  str = new char[string_size];
  str[0]=0;
}

String::String(char ch){
  string_size = 2;
  str = new char[string_size];
  str[0]=ch;
  str[1]=0;
}

String::String(const char cstr[]){     //Same as (const char * a)
  int i=0;
  while(cstr[i] != 0){
    i++;
  }
  string_size = i+1;
  str = new char[string_size];
  int pos=0;
  while(cstr[pos] != 0){
    str[pos]=cstr[pos];
    ++pos;
    //if(pos>=capacity)
    //break;
  }
  str[pos]=0;
}

String::String(int size){
  str = new char[size];
  string_size = size;
}

String::String(int cap, const char * cstr){
  string_size= cap+1;
  str = new char[string_size];
  int pos=0;
  while(cstr[pos] != 0){
    str[pos]=cstr[pos];
    ++pos;
    ++string_size;
  }
  ++string_size;
  str[pos]=0;
}

void String::reset_capacity(int new_cap) {
  char * temp_data = new char [new_cap];
  for(int i=0; i<new_cap;++i){
    if(i >= capacity()){
      temp_data[i]= 0; //change zero to 1 for testing.
    }else {
      temp_data[i]= str[i];
    }
  }
  delete [] str;
  str = temp_data;
  string_size = new_cap+1;
}
//-----------------------------

//Big three + swap-------------
String::~String(){
  delete [] str;
}

void String::swap(String& rhs){
  int temp_cap = string_size;
  string_size = rhs.string_size;
  rhs.string_size = temp_cap;

  char * temp_data = str;
  str = rhs.str;
  rhs.str = temp_data;
}

String::String(const String& rhs) :String(rhs.string_size){
  for(int i=0; i<string_size;++i){
    str[i]= rhs.str[i];
  }
}

String& String::operator=(String rhs){
  swap(rhs);
  return *this;
}
//----------------------------
int String::length()const{
  int size=0;
  while(str[size] !=0){
    ++size;
  }
  return size;
}

int String::capacity()const {
  int size=0;
  while(str[size] !=0){
    ++size;
  }
  return size;
}

char & String::operator[](int i){
  assert(i >=0);
  return str[i];
}

char String::operator[](int i)const{
  assert(i >=0);
  return str[i];
}

bool String::operator==(const String& rhs)const{
  int pos=0;
  while((str[pos] !=0) && (str[pos]==rhs.str[pos])){
    ++pos;
  }
  return str[pos] == rhs.str[pos];
}

bool operator==(const char cstr[], const String& rhs){
  int pos=0;
  while ((cstr[pos] != 0) && (cstr[pos]==rhs[pos])){
    ++pos;
  }
  return cstr[pos] == rhs[pos];
}

bool operator==(char ch, const String& rhs){
  if((ch != 0) && (ch==rhs[0])){
    if(rhs[1] !=0)return false;
  }
  return ch==rhs[0];
}

bool operator!=(const String& lhs, const String& rhs){
  //  int pos=0;
  if(lhs.length() != rhs.length()){return true;}
  //  while(lhs[pos] == rhs[pos]){
  // ++pos;
  // }
  for (int i=0; lhs[i] != '\0' && rhs[i] != '\0'; ++i){
    if(lhs[i] != rhs[i]){return true;} //was: if(lhs[i] == rhs[i]){return false;}
  }return false;//was }return true;
  //return lhs[pos] != rhs[pos];
}

/*
std::istream& operator>>(std::istream& in, String& rhs){
  rhs.reset_capacity(2);
  char x='a';
  int i=0;

  while(x!=in.eof()){
    while(x!= ' '|| x!=in.eof()){
      in>> x;
      rhs.reset_capacity(i+2);
      rhs[i]= x;
      i++;
      if(x== ' ' || x=='\t' || x=='\n'|| x=='\r'){
        rhs.reset_capacity(i+2);
        rhs = rhs+ x;
        ++i;
      }
    }
    in>> x;
  }
  return in;
}
*/

std::istream& operator>>(std::istream& in, String& rhs){
  char a[1024];
  in>>a;
  rhs = a;
  return in;
}

std::ostream& operator<<(std::ostream& out, const String& rhs){
  out<<rhs.str;
  return out;
}

bool operator<=(const String& lhs, const String& rhs){
  int pos=0;
  while(lhs[pos]!=0 && rhs[pos] !=0 && lhs[pos]== rhs[pos]){
    ++pos;
  }
  return lhs[pos]<=rhs[pos];
}

bool String::operator<(const String& rhs)const{
  int pos=0;
  while(str[pos] !=0 && rhs.str[pos] !=0 && str[pos]== rhs.str[pos]){
    ++pos;
  }
  return str[pos]<rhs.str[pos];
}

bool operator<(const char cstr[],  const String& rhs){
  int pos=0;
  while(cstr[pos]!=0 && rhs[pos]!=0 && cstr[pos]==rhs[pos]){
    ++pos;
  }
  return cstr[pos]<rhs[pos];
}

bool operator<(char ch, const String& rhs){
  int pos=0;
  while(ch!=0 && rhs[pos]!=0 && ch==rhs[pos]){
    ++pos;
      }
  return ch<rhs[pos];
}

bool operator>=(const String& lhs, const String& rhs){
  int pos=0;
  while(lhs[pos]!=0 && rhs[pos]!=0 && lhs[pos]==rhs[pos]){
    ++pos;
      }
  return lhs[pos]>=rhs[pos];
}

bool operator>(const String& lhs, const String& rhs){
  int pos=0;
  while(lhs[pos]!=0 && rhs[pos]!=0 && lhs[pos]==rhs[pos]){
    ++pos;
      }
  return lhs[pos]>rhs[pos];
}

String String::operator+(const String& rhs)const{
  String result(str);
  int offset= length();
  int pos =0;
  while(rhs.str[pos] !=0){
    result.reset_capacity(result.length()+2);
    result.str[offset+pos] = rhs.str[pos];
    ++pos;
  }
  result.reset_capacity(result.length()+2);
  result.str[offset+pos]=0;
  return result;
}

String operator+(const char cstr[],  const String& rhs){
  String result;
  int offset= result.length();
  int pos =0;
  while(cstr[pos] !=0){
    result.reset_capacity(result.length()+2);
    result[offset+pos] = cstr[pos];
    ++pos;
  }
  result.reset_capacity(result.length()+2);
  result[offset+pos]=0;
  pos=0;
  offset= result.length();
  while(rhs[pos] !=0){
    result.reset_capacity(result.length()+2);
    result[offset+pos] = rhs[pos];
    ++pos;
  }
  result.reset_capacity(result.length()+2);
  result[offset+pos]=0;
  return result;
}

String operator+(char ch, const String& rhs){
  String result(ch);
  int pos =0;
  int offset= result.length();
  while(rhs[pos] !=0){
    result.reset_capacity(result.length()+2);
    result[offset+pos] = rhs[pos];
    ++pos;
  }
  result.reset_capacity(result.length()+2);
  result[offset+pos]=0;
  return result;
}

String& String::operator+=(String rhs){
  int offset = length();
  int pos =0;
  while(rhs.str[pos] !=0){
    if((offset+pos)>= string_size)break; //check capacity
    reset_capacity(length()+2);
    str[offset+pos]=rhs.str[pos];
    ++pos;
  }
  reset_capacity(length()+2);
  str[offset+pos]=0;
  return *this;
}

String String::substr(int start_pos, int count) const{
  int i=0;
  char substr[count+1];
  while(i<=count){
    if(start_pos+i > length()){
      substr[i]=0;
      String sh_result(substr);
      sh_result.reset_capacity(i);
      return sh_result;
    }
    substr[i]= str[start_pos+i];
    i++;
  }
  substr[i]= 0;
  String result(substr);
  return result;
}

int String::find(char ch, int start_pos)const{
  int i=0;
  while(str[start_pos+i]!= ch){
    ++i;
  }
  if(str[start_pos+i]!= ch){
    return -1;
  }else return start_pos+i;
}

int String::find(const String& s, int start_pos) const{
  int i =0;
  while(start_pos <= length()){
    while(str[start_pos] == s[i]){           //table   ab
      ++i;                                   //aaaCAaaCATa    cat
      ++start_pos;                           //aaaCACAaaCATa    cat
      if(i == s.length()){
        return start_pos-i;
      }
    }
    start_pos =++start_pos - i;
    i= i-i;
  }
  return -1;
}
/*
std::vector<String> String::split(char ch) const{
  std::vector<String> result;
  String substr(2);
  //String substr;
  int i=0;
  int x=0;
  int pos=0;

  while(pos <= length()){
    while(str[pos] != ch || pos== length()){
      substr[x] = str[pos];
      //substr[x] += str[pos];
      ++x;
      ++pos;
      if(str[pos] == ch || pos== length()){
        result.push_back(substr);
        ++i;
      }
      //      substr.reset_capacity(x+1);
    }
    substr
    ++pos;
    //    substr.reset_capacity(2);
    x=x-x;
  }
return result;
}
*/

std::vector<String> String::split(char ch) const{
  std::vector<String> result;
  String mystr;
  for (int i=0;str[i] != 0;++i){
    if(str[i]!= ch){
      mystr += str[i];
    }else{
      result.push_back(mystr);
      mystr = str[++i];
    }
  }
  result.push_back(mystr);
  return result;
}

int String::str_to_int(){
  int startindex = length() - 1;
  if(str[startindex] == '-'){
    return 0;
  }
  int value=0, tenspot = 1;
  for (int i= startindex; i>=0; --i){
    value += (int(str[i] - int('0'))* tenspot);
    tenspot *= 10;
  }
  return value;
}
/*
String getline(std::istream& in){

  String s;
  s = getline(in);
  std::vector<String> temp = s.split(';');
  s = temp[0];
  return s;
}
*/

String getline(std::istream& in){

  char ch;
  String line(ch);
  while(in >> ch){
    while(in.get(ch) && ch != '\n' && ch != '\r' && ch != ';'){
      line += ch;
    }
  }
  //  std::vector<String> temp = line.split(';');
  // line = temp[0];
  return line;
}

/*
String getline(std::istream& in){
  String line;
  char ch = '\0';

  for(int i= (in.get(ch), 0);(ch != '\r') && (ch != '\n') && (!in.fail()); ++i, in.get(ch)){
    if(i == (line.length() -1)){
      line.reset_capacity(line.length()*2);
    }
    line += ch;
  }
  return line;
}
*/
#endif
