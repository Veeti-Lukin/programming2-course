#include "utilities.hh"
#include <fstream>
#include <sstream>

namespace {

    // convert given string *str* to lower case in place
    void to_lower(std::string &str) {

        for (char &c: str) {
            c = tolower(c);
        }
    }

}

bool read_file(std::string &file_name, std::string str_holder) {

    std::ifstream file_object(file_name);

    if (!file_object) {
        // file was not found
        return false;
    }
    std::stringstream str_stream;
    str_stream << file_object.rdbuf();//read the file

    str_holder = str_stream.str();
    return true;
}
