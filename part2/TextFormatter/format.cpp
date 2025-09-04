#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int main()
{
    std::ifstream infile("format.cfg");
    if(!infile.is_open()) {
        std::cerr << "Failed to open the file!\n";
        return -1;
    }

    std::string key, value;

    std::string upper, wrap, prefix;
    while(infile >> key >> value >> value){
        if(key == "uppercase") {
            upper = value;
        }
        else if(key == "wrap") {
            wrap = value;
        }
        else if(key == "prefix") {
            prefix = value;
        }
    }

    infile.close();

    std::ifstream data("data.txt");
    if(!data.is_open()) {
        std::cerr << "Failed to open the file\n";
        return -1;
    }

    bool first = true;
    std::ofstream outfile("formatted.txt");
    std::string line;
    int n = std::stoi(wrap);
    while(std::getline(data, line)) {
        if(!line.empty()) outfile << prefix;
        
        if((first && upper == "title") || upper == "all") {
            std::transform(line.begin(), line.end(), line.begin(), [](unsigned char c) {
                return std::toupper(c);
            });
        }
        if(line.size() > n) {
            line.resize(n);
        }
        outfile << line << "\n";
        first = false;
    }
       
    return 0;

}