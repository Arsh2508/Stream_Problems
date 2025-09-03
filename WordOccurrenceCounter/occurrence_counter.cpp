#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>

int main()
{
    std::fstream infile("text.txt");
    if(!infile.is_open()) {
        std::cerr << "Failed to open the file\n";
        return -1;
    }

    std::map<std::string, int> count;
    std::string line;

    while(std::getline(infile, line)) {
        std::stringstream ss(line);
        std::string word;
        while(std::getline(ss, word, ',')){
            std::transform (word.begin(), word.end(), word.begin(), [](unsigned char c) {
                return std::tolower(c);
            });

            ++count[word];
        }
    }

    for(auto [key, value] : count) {
        std::cout << key << " " << value << "\n";
    }

    return 0;
}