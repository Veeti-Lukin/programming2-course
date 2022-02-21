#include <iostream>
#include <fstream>
#include <string>

using  std::cout, std::cin, std::string, std::ifstream, std::endl,
        std::ofstream, std::getline;

int main(){
    cout << "Input file: ";
    string fileName = "";
    getline(cin, fileName);
    ifstream fileObject(fileName);

    if(! fileObject) {
        cout << "ERROR! The file " << fileName << " cannot be opened." << endl;
        return EXIT_FAILURE;
    }

}
