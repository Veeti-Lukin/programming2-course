#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using  std::cout, std::cin, std::string, std::ifstream, std::endl, std::vector,
        std::ofstream, std::getline, std::to_string;

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
    fileObject.close();
}

void writeLines(ofstream& fileObject, const vector<string>& lines ){
    for (const string& line : lines){
        fileObject << line << endl;
    }
    fileObject.close();
}


int main(){
    cout << "Input file: ";
    string inputFileName = "";
    getline(cin, inputFileName);
    ifstream inputfileObject(inputFileName);
    cout << "Output file: ";
    string outputFileName = "";
    getline(cin, outputFileName);

    // checking if inputfile exists before making outputfile object
    if (! inputfileObject) {
        cout << "Error! The file " << inputFileName << " cannot be opened." << endl;
        return EXIT_FAILURE;
    }
    ofstream outputFileObject(outputFileName);


    vector<string> strings = readLines(inputfileObject);

    // adding row numbers
    for (vector<string>::size_type i = 0; i < strings.size(); i++){
        strings.at(i) = to_string(i + 1) + " " + strings.at(i);
    }

    writeLines(outputFileObject, strings);

    return EXIT_SUCCESS;
}
