#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using  std::cout, std::cin, std::string, std::ifstream, std::endl, std::vector,
        std::ofstream, std::getline;

vector<string> readLines(ifstream& fileObject){
    vector<string> lines = {};
    string line = "";
    // true if correctly gets line from fileobject
    while (getline(fileObject, line)){
        lines.push_back(line);
    }
    //when while loop breaks check if reached eof
    //or if there was error while reading line
    if (!fileObject.eof()){
        cout << "There was invalid line in in the file" << endl;
        return  {};
    }
    // no error while reading the file
    return lines;
}

int main(){
    cout << "Input file: ";
    string fileName = "";
    getline(cin, fileName);
    ifstream fileObject(fileName);

    if (! fileObject) {
        cout << "ERROR! The file " << fileName << " cannot be opened." << endl;
        return EXIT_FAILURE;
    }

    vector<string> strings = readLines(fileObject);
    for (string & s : strings){
        cout << s << endl;
    }
    return EXIT_SUCCESS;
}
