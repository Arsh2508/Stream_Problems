#include <iostream>
#include <fstream>
#include <string>

void sum(std::string& num1, const std::string& num2) {
    int carry = 0;

    int i = num1.size() - 1;
    int j = num2.size() - 1;

    std::string res;
    
    while(i >= 0 || j >= 0 || carry) {
        int d1 = (i >= 0) ? num1[i] - '0' : 0;
        int d2 = (j >= 0) ? num2[j] - '0' : 0;

        int s = d1 + d2 + carry;
        res.push_back((s % 10) + '0');
        
        carry = s / 10;
        --i;
        --j;
    }

    int start = 0;
    int end = res.size() - 1;

    while(start < end) {
        std::swap(res[start], res[end]);
        ++start;
        --end;
    }

    num1 = std::move(res);
}

int main()
{
    std::ifstream infile("number.txt");
    if(!infile.is_open()) {
        std::cerr << "Failed to open the file \n";
        return -1;
    }

    std::string num1;
    std::string num2;

    if(!std::getline(infile, num1)) {
        std::cerr << "file is empty!\n";
        return -1;
    }

    while(std::getline(infile, num2)) {
        sum(num1, num2);
    }

    std::cout << num1 << "\n";

    return 0;
}