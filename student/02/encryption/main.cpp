#include <iostream>
#include <string>

using std::string;

const char ASCII_MIN = 'a';
const char ASCII_MAX = 'z';

const string ALPHABETS = "abcdefghijklmnopqrstuvwxyz";

string input_key() {
    //opens user input for secret key.
    //Does tests for the key and returns it
    //Retuns empty std::string if key didn't pass the tests
    string input = "";
    std::getline(std::cin, input);

    if (input.size() != 26) {
        std::cout << "Error! The encryption key must contain 26 characters." << std::endl;
        return "";
    }

    // check that there are only lowercase alphabets
    for (char & character : input){
       if ( ASCII_MIN > character or character > ASCII_MAX) {
           std::cout << "Error! The encryption key must contain only lower case characters." << std::endl;
           return "";
       }
    }
    // chek that there are all of the lowercase alphabets
    for (char letter = 'a';  letter < 'z'+1; ++letter) {
        if (input.find(letter) == string::npos) {
            std::cout << "Error! The encryption key must contain all alphabets a-z." << std::endl;
            return "";
        }
    }
    return input;
}

void encrypt(string &text, string key) {
    for (string::size_type i = 0; i < text.size(); ++i) {
        char character = text.at(i);

        // characters not found in key wont be encrypted
        if (key.find(character) == string::npos)
            continue;

        char encrypted_char = key.at(ALPHABETS.find(character));
        // changing the original text variable not a copy by referencing it in parameters with &
        text.at(i) = encrypted_char;
    }
}

int main()
{
    std::cout << "Enter the encryption key: ";
    string encryption_key = input_key();
    if (encryption_key == "")
        return EXIT_FAILURE;

    std::cout << "Enter the text to be encrypted: ";
    string text = "";
    std::getline(std::cin, text);

    encrypt(text, encryption_key);
    std::cout << "Encrypted text: " << text << std::endl;

    return EXIT_SUCCESS;
}
