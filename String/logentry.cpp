/**
 * @file logentry.hpp
 *
 * @version 1.0
 * @date
 * @author
 *
 * Implementation for a log entry.
 *
 */

/*
 * Tyler Miracle
 * CS23001
 * 2/25/2017
*/

#include <iostream>
#include <vector>

#include "string.hpp"
#include "logentry.hpp"

/**
 * @pre
 * @post
 */
log_entry::log_entry(const String & s) {
    // ...
    std::vector<String> vec = s.split(' ');

    if(vec.size() == 10){
      host = vec[0];


    std::vector<String> time_o_entry = vec[3].split(':');
    std::vector<String> date_string = time_o_entry[0].split('/');


    String day = date_string[0].substr(1, date_string[0].length());
    date.setday(day);

    String month = date_string[1];
    date.setmonth(month);

    int year = date_string[2].str_to_int();
    date.setyear(year);


    time.sethour(time_o_entry[1].str_to_int());
    time.setminute(time_o_entry[2].str_to_int());
    time.setsecond(time_o_entry[3].str_to_int());

    request = vec[5] + vec[6] + vec[7];
    number_of_bytes = vec[9].str_to_int();
    status = vec[8];
    if(vec[9] == '-'){
      number_of_bytes = 0;
    }
    number_of_bytes = vec[9].str_to_int();
    }else{
      host = "-";

      date.setday("-");
      date.setmonth("-");
      date.setyear(0);

      time.sethour(0);
      time.setminute(0);
      time.setsecond(0);
      request = "-";
      status = "-";
      number_of_bytes = 0;
    }
}

/**
 * @pre
 * @post
 */
std::vector<log_entry> parse(std::istream & in) {
  std::vector<log_entry> result;
  do{                            // String line = getline(in);
    String line = getline(in);   // while(!in.eof()){
    if(in.eof()){                // log_entry log(line);
      return result;}            // result.push_back(log);
    log_entry log(line);         // String line = getline(in); }
    result.push_back(log);
  }while(!in.eof());
  return result;
}

std::ostream& operator<<(std::ostream& out, const log_entry& log){
  out << log.host << " ";

  out << log.date.getday() << "/";
  out << log.date.getmonth() << "/";
  out << log.date.getyear() << " ";

  out << log.time.gethour() << ":";
  if (log.time.getminute() < 10){
    out << "0";
}
  out << log.time.getminute()<< ":";
  out << log.time.getsecond() << " ";

  out << log.request << " ";
  out << log.status << " ";
  out << log.number_of_bytes << "\n";

  return out;
}

/**
 * @pre
 * @post
 */
void output_all(std::ostream & out, const std::vector<log_entry> & logs) {

  for(unsigned int i = 0; i< logs.size(); ++i){
    out << logs[i];
  }
}

/**
 * @pre
 * @post
 */
void by_host(std::ostream & out, const std::vector<log_entry> & logs) {
  for(unsigned int i =0; i < logs.size(); ++i){
    out << logs[i].gethost() << '\n';
  }
}

//////////////////////////////////////////////////////////
/**
 * @pre
 * @post
 */
int byte_count(const std::vector<log_entry> & logs) {
  int sum = 0;
  for(unsigned int i =0; i<logs.size(); ++i){
    sum += logs[i].getbytes();
  }
    return sum;
}
