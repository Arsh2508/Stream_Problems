#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main()
{
    std::ifstream infile("input.txt");
    std::string title, header, paragraph, line;

    infile >> title;
    std::getline(infile, title);

    infile >> header;
    std::getline(infile, header);

    std::string tmp;
    while(std::getline(infile, line)) {
        std::stringstream ss(line);
        std::getline(ss, tmp, ':');
        std::getline(ss, tmp);
        paragraph += "<p>";
        paragraph += tmp;
        paragraph += "<p>\n";
    }

    std::ofstream web("web_page.html");

    web << "<!DOCTYPE html>\n"
           "<html lang=\"en\">\n"
           "<head>\n"
           "  <meta charset=\"utf-8\">\n"
           "  <title>" << title << "</title>\n"
           "</head>\n"
           "<body>\n"
           "  <h1>" << header << "</h1>\n"
           "  " << paragraph <<
           "</body>\n"
           "</html>\n";
    
    return 0;
    
}