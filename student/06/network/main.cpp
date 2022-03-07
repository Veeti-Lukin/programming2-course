#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>

using Network = std::map<std::string, std::vector<std::string>>;

const std::string HELP_TEXT = "S = store id1 i2\nP = print id\n"
                              "C = count id\nD = depth id\n";

std::vector<std::string> split(const std::string& s,
                               const char delimiter,
                               bool ignore_empty = false)
{
    std::vector<std::string> result;
    std::string tmp = s;

    while(tmp.find(delimiter) != std::string::npos)
    {
        std::string new_part = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter) + 1, tmp.size());
        if(not (ignore_empty and new_part.empty()))
        {
            result.push_back(new_part);
        }
    }
    if(not (ignore_empty and tmp.empty()))
    {
        result.push_back(tmp);
    }
    return result;
}

void storeToNetwork(Network& network, const std::string& id1,
                    const std::string& id2) {
    // check if the inviter is inside the network already if not add inviter
    if (network.find(id1) == network.end()) {
        network.insert( {id1, {}} );
    }
    network.at(id1).push_back(id2);
}

void printNetworkOfId(const Network& network, const std::string& id, int depth = 0) {
    std::string indentation(depth*2, '.');
    std::cout << indentation << id << std::endl;

    // check if id is in network
    if (network.find(id) == network.end()) {
        return;
    }
    for (const std::string& connectionId : network.at(id)) {
        printNetworkOfId(network, connectionId, depth+1);
    }
}

int countNetworkSizeOfId(const Network& network, const std::string& id) {
    int sizeOfNetwork = 0;
    if (network.find(id) != network.end()) {
        for (const std::string& connectionId : network.at(id)) {
           sizeOfNetwork += 1 + countNetworkSizeOfId(network, connectionId);
        }
    }
    return sizeOfNetwork;
}

int countNetworkDepthOfId(const Network& network, const std::string& id) {
    int depthOfNetwork = 0;
    if (network.find(id) != network.end()) {

        for (const std::string& connectionId : network.at(id)) {

           if (countNetworkDepthOfId(network, connectionId) > depthOfNetwork) {
               depthOfNetwork = countNetworkDepthOfId(network, connectionId);
           }
        }
    }
    return depthOfNetwork +1;
}


int main()
{
    // TODO: Implement the datastructure here
    Network network;

    while(true)
    {
        std::string line;
        std::cout << "> ";
        getline(std::cin, line);
        std::vector<std::string> parts = split(line, ' ', true);

        // Allowing empty inputs
        if(parts.size() == 0)
        {
            continue;
        }

        std::string command = parts.at(0);

        if(command == "S" or command == "s")
        {
            if(parts.size() != 3)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id1 = parts.at(1);
            std::string id2 = parts.at(2);
            storeToNetwork(network, id1, id2);

        }
        else if(command == "P" or command == "p")
        {
            if(parts.size() != 2)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id = parts.at(1);

            printNetworkOfId(network, id);

        }
        else if(command == "C" or command == "c")
        {
            if(parts.size() != 2)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id = parts.at(1);

            std::cout << countNetworkSizeOfId(network, id) << std::endl;

        }
        else if(command == "D" or command == "d")
        {
            if(parts.size() != 2)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id = parts.at(1);

            std::cout << countNetworkDepthOfId(network, id) << std::endl;

        }
        else if(command == "Q" or command == "q")
        {
           return EXIT_SUCCESS;
        }
        else
        {
            std::cout << "Erroneous command!" << std::endl << HELP_TEXT;
        }
    }
}
