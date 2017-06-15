/*
  * Tyler Miracle
  * CS23001
  * 2/25/2017
*/

#ifndef CS2_LOGENTRY_HPP
#define CS2_LOGENTRY_HPP

/**
 * @file logentry.hpp
 *
 * @version 1.0
 * @date
 * @author
 *
 *  Class definition for a log entry.
 *
 */

#include <iostream>
#include <vector>

#include "string.hpp"

/** date_type class */
class Date {
public:
  Date() {};
  void setday(String linestring){day = linestring;};
  void setmonth(String linestring){month = linestring;};
  void setyear(int linestring){year = linestring;};
  String getday()const{return day;};
  String getmonth()const{return month;};
  int getyear()const{return year;};

private:
  String day, month;
  int    year;
};

/** time_type class */
class Time {
public:
  Time() {};
  void sethour(int linevalue){hour = linevalue;};
  void setminute(int linevalue){minute = linevalue;};
  void setsecond(int linevalue){second = linevalue;};
  int gethour()const {return hour;};
  int getminute()const {return minute;};
  int getsecond()const {return second;};

private:
  int hour, minute, second;

};


/** log_entry class */
class log_entry {
public:
  log_entry() {};
  log_entry(const String &);
  friend std::ostream & operator<<(std::ostream &, const log_entry &);
  String gethost()const {return host;};
  int getbytes()const {return number_of_bytes;};

private:
  String host;
  Date date;
  Time time;
  String request;
  String status;
  int    number_of_bytes;
};


// free functions
std::vector<log_entry>  parse       (std::istream &);
void                    output_all  (std::ostream &, const std::vector<log_entry> &);
void                    by_host     (std::ostream &, const std::vector<log_entry> &);
int                     byte_count  (const std::vector<log_entry> &);

#endif
