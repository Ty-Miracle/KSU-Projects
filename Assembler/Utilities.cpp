
/*
 *Tyler Miracle
 *4/5/2017
 *utilities program
*/
//may neeed #include <vector>

#ifndef CS2_UTILITIES_CPP
#define CS2_UTILITIES_CPP
#include "utilities.hpp"
#include "stack.hpp"

String infix_to_postfix(const String& infix){
  stack<String> stk;
  std::vector<String> tokens = infix.split(' ');
  for(int i =0; i < tokens.size(); ++i){
    //    std::cout << std::endl << tokens[i] << std::endl;
    if(tokens[i] == ")"){
      String right = stk.pop();
      String oper = stk.pop();
      String left = stk.pop();
      stk.push(left+' ' + right +' ' + oper);
    }else if(tokens[i] != "("){
      stk.push(tokens[i]);
    }else if(tokens[i] == ""){}
  }
  return stk.top();
}

//A B C * + D E - /
String postfix_to_assembly(const String& postfix){
  int num = 1;
  stack<String> stk;
  std::vector<String> tokens = postfix.split(' '); //ABC*+DE/
  for(int i= 0; i < tokens.size(); ++i){
    String t = tokens[i];
    if (t != '*' && t != '/' && t != '+' && t != '-'){      //if letter
      stk.push(t);                           //add to stack
    }else {                            //if operator
      String right = stk.pop();
      String left = stk.pop();
     const String eval = evaluate(left, t, right, num);
      stk.push(eval);     //ABC   //A
      ++num;
    }    //ATEMP1
  }
  return stk.top();
}

void postfix_to_assembly(const String& postfix, std::ostream& out){
  int num = 1;
  stack<String> stk;
  std::vector<String> tokens = postfix.split(' '); //ABC*+DE/
  for(int i= 0; i < tokens.size(); ++i){
    String t = tokens[i];
    if (t != '*' && t != '/' && t != '+' && t != '-'){      //if letter
      stk.push(t);                           //add to stack
    }else {                            //if operator
      String right = stk.pop();
 String left = stk.pop();
      const String eval = evaluate(left, t, right, num, out);
      stk.push(eval);     //ABC   //A
      ++num;
    }    //ATEMP1
  }
  // return stk.top();
}


String evaluate(String left, String t, String right, int num){    // std::ostream parameter

  std::cout << "   LOAD  " << left;
  std::cout << std::endl;

  if(t == '*'){
    std::cout << "   MULR  " << right;
    std::cout << std::endl;
  }else if (t == '/'){
    std::cout << "   DIVR  " << right;
    std::cout << std::endl;
  }else if(t == '+'){
    std::cout << "   ADDR  " << right;
    std::cout << std::endl;
  }else if(t == '-'){
    std::cout << "   SUBR  " << right;
    std::cout << std::endl;
}
  std::cout << "   STOR  " << "TEMP" <<num;    //Temp n
  std::cout << std::endl;

  String result("TEMP");
  int a[25];     //Fits maxint
  for(int index=0; index<15;++index){            //initializes array to zeros
    a[index]=0;
  }
  int elem =0;
  while(num !=0){         //stores number in the array backwards
    int n=num%10;         //Ex. 1234 stored as [4][3][2][1]
    a[elem]=n;
    num/=10;
    ++elem;
  }
  elem = 0;
  while(a[elem]!=0){        //finds end of array
    ++elem;
  }--elem;                  //gets max amount of elems stored
  String storage;
  /*  int x=0;
  while(x != 25){           //This block of code checks what's stored in array
    std::cout << a[x];
    ++x;
    }*/
  for(int i=0;a[i]!=0;++i,--elem ){     //(char(a[i])+char('0')) should change int to char
    storage[elem] = (char(a[i])+char('0'));            //storage is being put in backwards
  }                                              //to have this order ['1']['2']['3']['4']

  result = result + storage[0];

    return result;
}


String evaluate(String left, String t, String right, int num, std::ostream& out){    // std::ostream parameter

  out << "   LOAD  " << left;
  out << std::endl;

  if(t == '*'){
    out << "   MULR  " << right;
    out << std::endl;
  }else if (t == '/'){
    out << "   DIVR  " << right;
    out << std::endl;
  }else if(t == '+'){
    out << "   ADDR  " << right;
    out << std::endl;
  }else if(t == '-'){
    out << "   SUBR  " << right;
    out << std::endl;
  }
  out << "   STOR  " << "TEMP" <<num;    //Temp n
  out << std::endl;

  String result("TEMP");
  int a[25];     //Fits maxint
  for(int index=0; index<25;++index){            //initializes array to zeros
    a[index]=0;
  }
  int elem =0;
  while(num !=0){         //stores number in the array backwards
    int n=num%10;         //Ex. 1234 stored as [4][3][2][1]
    a[elem]=n;
    num/=10;
    ++elem;
  }
  elem = 0;
  while(a[elem]!=0){        //finds end of array
    ++elem;
  }--elem;                  //gets max amount of elems stored
  String storage;
  /*  int x=0;
  while(x != 25){           //This block of code checks what's stored in array
  std::cout << a[x];
    ++x;
    }*/
  for(int i=0;a[i]!=0;++i,--elem ){     //(char(a[i])+char('0')) should change int to char
    storage[elem] = (char(a[i])+char('0'));              //storage is being put in backwards
  }                                              //to have this order ['1']['2']['3']['4']

  result = result + storage[0];
  return result;
}
#endif
