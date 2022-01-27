#include <iostream>
#include <string>

using std::string;

string input_key() {
    //opens user input for secret key.
    //Does tests for the key and returns it
    //Retuns empty std::string if key didn't pass the tests
    string input = "";
    std::cin >> input;

    if (input.size() != 26) {
        std::cout << "Error! The encryption key must contain 26 characters." << std::endl;
        return "";
    }

    //check that there are only lowercase alphabets
    for (char & character : input){
       if ( 'a' > character or character > 'z') {
           std::cout << "Error! The encryption key must contain only lower case characters." << std::endl;
           return "";
       }
    }
    //chek that there are all of the lowercase alphabets
    for (char letter = 'a';  letter < 'z'+1; ++letter) {
        if (input.find(letter) == string::npos) {
            std::cout << "Error! The encryption key must contain all alphabets a-z." << std::endl;
            return "";
        }
    }
    return input;
}

int main()
{
    std::cout << "Enter the encryption key: " << std::endl;
    string encryption_key = input_key();
    if (encryption_key == "")
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
