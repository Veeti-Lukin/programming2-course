#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm>
#include <utility>

using namespace std;

const string DELIMETER = ":";

vector<string> readLinesFromFile(string fileName) {
    ifstream fileObject(fileName);
    // cheking if the file exists return empty vector if not
    if (!fileObject) {
        cout << "Error! The file " << fileName << " cannot be opened." << endl;
        return {};
    }

    vector<string> lines = {};
    string line = "";
    // true if correctly gets a line from fileobject
    while (getline(fileObject, line)){
        lines.push_back(line);
    }
    //when while loop breaks check if reached eof
    //or if there was error while reading line
    if (!fileObject.eof()){
        cout << "There was invalid line in in the file" << endl;
        return  {};
    }
    // no errors while reading the file
    fileObject.close();
    return lines;
}

int main()  {
    cout << "Input file: ";
    string inputFileName = "";
    getline(cin, inputFileName);

    vector<string> lines = readLinesFromFile(inputFileName);
    if (lines.size() == 0) {
        return EXIT_FAILURE;
    }

    map<string, int> points;
    for (const string& line : lines) {
        size_t splittingPoint = line.find(DELIMETER);
        if (splittingPoint == string::npos) {
            return EXIT_FAILURE;
        }

        string name = line.substr(0, splittingPoint);
        int score = stoi(line.substr(splittingPoint+1, line.size()));

        if (points.find(name) == points.end()) {
            points.insert({name, 0});
        }
        points.at(name) += score;
    }

    cout << "Final scores:" << endl;
    for(auto& p : points) {
        cout << p.first << ": " << p.second << endl;
    }
}
