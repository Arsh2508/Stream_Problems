#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

int main(int argc, char *argv[])
{
    if(argc < 2) {
        std::cerr << "Need at least one argument passed: " << argv[0] << " file1.csv [file2.csv ...]\n";
        return -1;
    }

    std::unordered_set<std::string> lines;

    std::ofstream outfile("data.json");
    if(!outfile.is_open()) {
        std::cerr << "Failed to open the file!\n";
        return -1;
    }

    outfile << "[";

    bool comma = false;
    std::vector<std::string> headers;
    std::string line;

    for(int i = 1; i < argc; ++i) {
        std::ifstream infile(argv[i]);
        if(!infile.is_open()) {
            std::cerr << "Failed to open input file:" << argv[i] << "\n";
            continue;
        }

        if(!std::getline(infile, line)) {
            continue;
        }
        std::string header;

        if(headers.empty()){
            std::stringstream ss(line);
            while(std::getline(ss, header, ',')) {
                headers.push_back(header);
            }
        }

        while(std::getline(infile, line)) {
            if(lines.find(line) != lines.end()) continue;
            lines.insert(line);

            if(comma) {
                outfile << ",";
            }
            comma = true;    
            
            std::stringstream fields(line);
            
            outfile << "\n\t{";
            
            for(size_t j = 0; j < headers.size(); ++j) {
                outfile << "\"" << headers[j] << "\": ";
                
                std::string field;
                std::getline(fields, field, ',');

                if(std::all_of(field.begin(), field.end(), ::isdigit)) {
                    outfile << field;
                }
                else{
                    outfile << "\"" << field <<  "\"";
                }
                
                if(j < headers.size() - 1){
                    outfile << ", ";
                }
            }

            outfile << "}"; 
        }

    }

    outfile << "\n]";

    return 0;
}