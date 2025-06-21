#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

#include "txtmanipull.hpp"

std::string to_lower(std::string original) {
    std::transform(original.begin(), original.end(), original.begin(), [](unsigned char c){ return std::tolower(c); });
    return original;
}

int main(int argc, char* argv[]) {
    std::string fileName;
    std::string filter;

    if (argc < 2) {
    system("cls");
        std::cout << "[__________Log_File_Reader__________]\n";
        std::cout << "Made by ChaoticOfChaos\n";
        std::cout << "Github : https://github.com/ChaoticOfChaos\n\n";

        std::cout << "Enter File Name:\n";
        std::cout << ">>> ";
        std::getline(std::cin, fileName);

    } else {
        fileName = argv[1];

    }

    TXTManipulation::ReadFile logs(fileName);

    if (logs.read() == 1) {
        std::cerr << "Log File Not Found!\n";
        return 1;
    }

    system("cls");

    std::cout << "Lines : " << std::to_string(logs.getValue().size()) << std::endl;

    std::cout << "'quit' to Quit\n";
    while (1) {
        std::cout << "(" << fileName << ") -> ";
        std::getline(std::cin, filter);

        if (filter == "quit" || filter == "exit") {
            break;
        }

        for (std::string line : logs.getValue()) {
            if (to_lower(line).find(to_lower(filter)) != std::string::npos) {
                std::cout << line << std::endl;
            }
        }

        std::cout << "\n\n";
        
    }

    return 0;
}