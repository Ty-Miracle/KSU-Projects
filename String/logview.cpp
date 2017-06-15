/**
 * @file logview.cpp
 *
 * @version 1.0
 * @date
 * @author
 *
 * Main body for logview application
 *
 */
/*
  * Tyler Miracle
  * CS23001
  * 2/25/2017
*/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

#include "string.hpp"
#include "logentry.hpp"

void output_usage_and_exit(const char cmd[], const std::vector<String>& opts);

int main(int argc, char *argv[]) {

    // options
    std::vector<String> opt(3);
    opt[0] = "all";
    opt[1] = "bytes";
    opt[2] = "host";

    // error if there are not 3 things on the command line
    if (argc != 3) { output_usage_and_exit(argv[0], opt); }

    // open file, quit if open fails
    std::ifstream in(argv[2]);
    if (!in) { std::cerr << "Couldn't open " << argv[2] << "\n"; exit(2); }

    // process the log file
    std::vector<log_entry> log_entries = parse(in);

    // we're done with the file
    in.close();

    // handle the specified option
    String option(argv[1]);
    if (option == opt[0]) {
        // Output everything
      //std::cout << log_entries[0].date;
        output_all(std::cout, log_entries);
    }
    else if (option == opt[1]) {
        // output total number of bytes
        std::cout << "Total number of bytes sent: "
                  << byte_count(log_entries) << std::endl;
    }
    else if (option == opt[2]) {
        // output host names only
        by_host(std::cout, log_entries);
    }
    else {
        // error, bad option
        std::cerr << "Unrecognized option: " << option << std::endl;
        std::cerr << "Recognized options: "
             << opt[0] << " "
             << opt[1] << " "
             << opt[2] << std::endl;
    }

    // return success
    return 0;
}

void output_usage_and_exit(const char cmd[], const std::vector<String>& opt)
{
    // output usage message
    std::cerr << "Usage: " << cmd << " [";
       for (std::vector<String>::size_type idx = 0; idx < opt.size() - 1; ++idx)
           std::cerr << opt[idx] << " | ";
    std::cerr << opt[opt.size() - 1] << "] log_file\n";

    // exit with error
    exit(1);
}
