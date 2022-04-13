#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>

// reads a file to given std::string *str_holder*
// return true if succeed, false otherwise
bool read_file(const std::string &file_name, std::string &str_holder);

// return boool wether substring is found in string or not
bool find_substr(std::string str, std::string substr, bool match_case);

#endif // UTILITIES_H
