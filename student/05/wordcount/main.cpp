#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;

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

set<string> split(string text, char splitter, bool skip_empty=false) {
    set<string> words;
    string substr = "";
    size_t start = 0;
    size_t end = text.find(splitter);
    while (end != string::npos) {
        substr = text.substr(start, end - start);
        start = end +1;
        end = text.find(splitter, start);

        if (skip_empty && substr ==  "")
            continue;

        words.insert(substr);
    }
    words.insert(text.substr(start, end - start));
    return words;
}

int main()  {
    cout << "Input file: ";
    string inputFileName = "";
    getline(cin, inputFileName);

    vector<string> lines = readLinesFromFile(inputFileName);
    if (lines.size() == 0) {
        return EXIT_FAILURE;
    }

    map<string, set<int>> wordLines;
    unsigned int lineNum = 1;
    for (const string& line : lines) {
        set<string> words = split(line, ' ', true);
        for (const string& word : words) {
            if (wordLines.find(word) == wordLines.end()) {
                wordLines.insert({word, {}});
            }
            wordLines.at(word).insert(lineNum);
        }
        lineNum++;
    }

    for(const auto& p : wordLines) {
        cout << p.first << " "<< p.second.size() <<": ";
        for (const int& lineNum : p.second) {
            cout << lineNum;
            if (p.second.find(lineNum) != (--p.second.end())) {
                cout << ", ";
            }
        }
        cout << endl;
    }
}
