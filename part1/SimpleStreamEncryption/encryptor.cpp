#include <iostream>
#include <fstream>
#include <string>

int main() 
{
    std::ifstream infile("text.txt");
    if(!infile.is_open()) {
        std::cerr << "Failed to open the file\n";
        return -1;
    }

    std::ofstream outfile("encrypted.txt");
    if(!outfile.is_open()) {
        std::cerr << "Failed to open the file\n";
        return -1;
    }

    char ch;
    while(infile.get(ch)) {
        if((ch > 64 && ch < 91) || (ch > 96 && ch < 123)) {
            ++ch;
            if(ch == 91) {
                ch = 'A';
            }
            if(ch == 123) {
                ch = 'a';
            }
        }
        outfile << ch;
    }

    return 0;
}   