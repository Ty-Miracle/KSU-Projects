/*
  * Tyler Miracle
  * Utilities.hpp
  * CS23001
  * 09/15/2016
*/
#ifndef CS2_UTILITIES_HPP
#define CS2_UTILITIES_HPP
#include "../string/string.hpp"


String infix_to_postfix(const String&);
String evaluate(String left, String t, String right, int num);
String evaluate(String left, String t, String right, int num, std::ostream& out);
String postfix_to_assembly(const String&);
void postfix_to_assembly(const String& , std::ostream& out);

#endif
