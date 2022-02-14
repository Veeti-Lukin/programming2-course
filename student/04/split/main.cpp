#include <iostream>
#include <string>
#include <vector>


// TODO: Implement split function here
// Do not change main function
std::vector<std::string> split(std::string text, char splitter, bool skip_empty=false) {
    std::vector<std::string> words;
    std::string substr = "";
    size_t start = 0;
    size_t end = text.find(splitter);
    while (end != std::string::npos) {
        substr = text.substr(start, end - start);
        start = end +1;
        end = text.find(splitter, start);

        if (skip_empty && substr ==  "")
            continue;

        words.push_back(substr);
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
