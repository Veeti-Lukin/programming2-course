#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

const std::string HELP_TEXT = "N                  = List ordered by student numbers\n"
                              "U                  = List ordered alphabetically by user ids\n"
                              "C <student_number> = Change the given student's phone number\n"
                              "Q                  = Quit\n";

struct Student {
    std::string student_number;
    std::string user_id;
    std::string name;
    std::string phone_number;
    std::string email;
    std::string skype;
};

std::vector<std::string> split(const std::string& s,
                               const char delimiter,
                               const bool ignore_empty = false) {
    std::vector<std::string> result;
    std::string tmp = s;

    while(tmp.find(delimiter) != std::string::npos) {
        std::string new_part = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter)+1, tmp.size());
        if(not (ignore_empty and new_part.empty())) {
            result.push_back(new_part);
        }
    }
    if(not (ignore_empty and tmp.empty())) {
        result.push_back(tmp);
    }
    return result;
}


bool read_data(const std::string& file_name,
               std::map< std::string, Student* >& alphabetical_order,
               std::map< std::string, Student* >& numerical_order) {
    std::ifstream file_object(file_name);
    if( !file_object ) {
        return false;
    }

    std::string line = "";

    while( getline( file_object, line ) ) {
        std::vector<std::string> parts = split(line, ';');
        if(parts.size() != 6) {
            return false;
        }

        Student* new_student = new Student({parts[0],
                                            parts[1],
                                            parts[2],
                                            parts[3],
                                            parts[4],
                                            parts[5]});
        numerical_order[parts[0]] = new_student;
        alphabetical_order[parts[1]] = new_student;
    }
    file_object.close();
    return true;
}


void print_data(const Student& s) {
    std::cout << s.student_number << " " << s.user_id << std::endl
              << s.name << std::endl
              << s.phone_number << std::endl
              << s.email << std::endl
              << s.skype << std::endl << std::endl;
}

bool is_valid_phone_number(const std::string number) {
    for(unsigned int i = 0; i < number.length(); ++i) {
        if(!(('0' <= number[i] and number[i] <= '9')
             or number[i] == ' '
             or number[i] == '-')) {
            std::cout << "Erroneous phone number: "
                      << number
                      << std::endl << std::endl;
            return false;
        }
    }
    return true;
}

bool change_phone_number(const std::string& id,
                         std::map< std::string, Student* >& alphabetical_order,
                         std::map< std::string, Student* >& numerical_order) {
    if (numerical_order.find(id) == numerical_order.end()) {
        std::cout << "There is no student with the given number!" << std::endl
        << std::endl;
        return false;
    }

    std::cout << "Enter a new phone number: ";
    std::string phone_num;
    getline(std::cin, phone_num);
    std:: cout << std::endl;

    if (!is_valid_phone_number(phone_num)) {
        return false;
    }

    numerical_order.at(id)->phone_number = phone_num;
    alphabetical_order.at(numerical_order.at(id)->user_id)->phone_number = phone_num;
    return true;
}

void write_data(const std::string& file_name,
                std::map< std::string, Student* >& alphabetical_order) {
    std::ofstream file(file_name);
    for (auto& pair: alphabetical_order) {
       file << pair.second->student_number << ";";
       file << pair.second->user_id << ";";
       file << pair.second->phone_number << ";";
       file << pair.second->email << ";";
       file << pair.second->skype << std::endl;
    }
}

int main() {
    std::string file_name = "";
    std::cout << "Student file: ";
    std::getline(std::cin, file_name);

    std::map< std::string, Student* > user_ids;
    std::map< std::string, Student* > student_numbers;
    if(not read_data(file_name, user_ids, student_numbers)) {
        std::cout << "Error in reading file!" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << HELP_TEXT << std::endl;

    while(true) {
        std::string line;
        std::cout << "register> ";
        getline(std::cin, line);
        std::vector<std::string> parts = split(line, ' ', true);

        if(parts.empty()) {
            continue;
        }
        std::string command = parts.at(0);

        // Printing in alphabetical order by user ids
        if(command == "U" or command == "u") {
            if(parts.size() != 1) {
                std::cout << "Erroneous parameters!" << std::endl  << HELP_TEXT;
                continue;
            } else {
                for(auto& pair: user_ids) {
                    print_data(*(pair.second));
                }
            }

            // Printing in numerical order by student numbers
        } else if(command == "N" or command == "n") {
            if(parts.size() != 1){
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            } else {
                for(auto& pair: student_numbers) {
                    print_data(*(pair.second));
                }
            }

            // Changing student data
        } else if(command == "C" or command == "c") {
            if(parts.size() != 2){
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            change_phone_number(parts.at(1), user_ids, student_numbers);

            // TODO: Add functionality here

        } else if(command == "Q" or command == "q") {
            // Deleting the data structure: deallocating memory
            // and nullifying pointers
            for(auto pair: student_numbers) {
                pair.second = nullptr;
            }

            for(auto pair: user_ids) {
                delete pair.second;
                pair.second = nullptr;
            }

            return EXIT_SUCCESS;
        } else {
            std::cout << "Erroneous command!" << std::endl << HELP_TEXT;
        }
    }
}


