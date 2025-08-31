#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <sstream>

int main()
{
    std::ifstream infile("text.txt");
    if(!infile.is_open()) {
        std::cerr << "Failed to open the file\n";
        return -1;
    }

    std::unordered_set<std::string> words;

    std::ofstream outfile("compressed.txt");
    if(!outfile.is_open()) {
        std::cerr << "Failed to open the file\n";
        return -1;
    }

    std::string line;
    while(getline(infile, line)) {
        std::stringstream ss(line);
        std::string word;
        while(ss >> word) {
            if(words.find(word) == words.end()) {
                outfile << word << " ";
            }
            else {
                outfile << "* ";
            }
            words.insert(word);
        }
        outfile << "\n";
    }

    return 0;
}