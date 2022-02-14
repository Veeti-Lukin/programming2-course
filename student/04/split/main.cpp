#include <iostream>
#include <string>
#include <vector>


// TODO: Implement split function here
// Do not change main function
std::vector<std::string> split(const std::string& text, char splitter, bool skip_empty=false) {
    std::vector<std::string> words;

    if (text.find(splitter) == std::string::npos) {
        words.push_back(text);
        return words;
    }
    std::string current_word = "";
    for (std::string::size_type i = 0; i < text.size(); i++) {
        if (text.at(i) == splitter) {
            if (current_word == "" && skip_empty)
                continue;
            words.push_back(current_word);
            current_word = "";
            continue;
        }
        current_word += text.at(i);
        if (i == text.size()-1) {
            words.push_back(current_word);
        }
    }

    return words;
}

int main()
{
    std::string line = "";
    std::cout << "Enter a string: ";
    getline(std::cin, line);
    std::cout << "Enter the separator character: ";
    char separator = getchar();

    std::vector< std::string > parts  = split(line, separator);
    std::cout << "Splitted string including empty parts: " << std::endl;
    for( auto part : parts ) {
        std::cout << part << std::endl;
    }

    std::vector< std::string > parts_no_empty  = split(line, separator, true);
    std::cout << "Splitted string ignoring empty parts: " << std::endl;
    for( auto part : parts_no_empty ) {
        std::cout << part << std::endl;
    }
}
