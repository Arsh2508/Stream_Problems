#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main()
{
    std::ifstream infile("system_log.txt");
    if(!infile.is_open()) {
        std::cerr << "Failed to open the file\n";
        return -1;
    }

    int error_count = 0;
    int warning_count = 0;
    int info_count = 0;

    std::ofstream Error("Error.txt");
    if(!Error.is_open()) {
        std::cerr << "Failed to open the file\n";
        return -1;
    }

    std::string line;
    while(getline(infile, line)) {
        std::string word;
        std::stringstream ss(line);
        getline(ss, word, ']');

        if(word == "[ERROR") {
            ++error_count;
            Error << line << "\n";
        }
        else if(word == "[INFO") ++info_count;
        else if(word == "[WARNING") ++warning_count;
    }

    std::ofstream log("logInfo.txt");
    if(!log.is_open()) {
        std::cerr << "Failed to open the file\n";
        return -1;
    }

    log << "[ERROR] : " << error_count << "\n";
    log << "[WARNING] : " << warning_count << "\n";
    log << "[INFO] : " << info_count << "\n";
}