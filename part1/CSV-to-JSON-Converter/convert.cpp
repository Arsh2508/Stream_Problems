#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main()
{
    std::fstream infile("data.csv");
    if(!infile.is_open()) {
        std::cerr << "Failed to open the file \n";
        return -1;
    }

    std::string line;
    std::vector<std::string> headers;

    if(!std::getline(infile, line)) {
        std::cerr << "File is empty\n";
        return -1;
    }

    std::string header;
    std::stringstream ss(line);
    while(std::getline(ss, header, ',')) {
        headers.push_back(header);
    }

    std::ofstream outfile("data.json");
    if(!outfile.is_open()) {
        std::cerr << "Failed to open file\n";
        return -1;
    }

    outfile << "[";

    bool comma = false;

    while(std::getline(infile, line)) {
        std::stringstream sstr(line);
        std::string field;

        if(comma) {
            outfile << ",";
        }

        comma = true;

        outfile << "\n\t{";
        for(size_t i = 0; i < headers.size(); ++i) {
            if(!std::getline(sstr, field, ',')) continue;
            outfile << "\"" << headers[i] << "\":";
            outfile << "\"" << field << "\"";
            if(i != headers.size() - 1) {
                outfile << ",";
            }
        }
        outfile << "}";
    }

    outfile << "\n]";

    return 0;
}