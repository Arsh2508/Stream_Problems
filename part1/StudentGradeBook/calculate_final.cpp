#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

struct Student {
    std::string name;
    double grade;

    Student(std::string _name, double _grade): name{_name}, grade{_grade} {}
};

int main()
{
    std::ifstream infile("student.csv");
    if(!infile.is_open()) {
        std::cerr << "Failed to open the file!\n";
        return -1;
    }

    std::vector<Student> students;
    std::string line;

    if(!std::getline(infile, line)) {
        std::cerr << "File is empty!\n";
        return -1;
    }

    while (std::getline(infile, line)) {
        std::stringstream ss(line);
        std::string name, mid, final, homework;

        std::getline(ss, name, ',');
        std::getline(ss, mid, ',');
        std::getline(ss, final, ',');
        std::getline(ss, homework, ',');

        double Mid = std::stod(mid);
        double Final = std::stod(final);
        double Homework = std::stod(homework);

        double Grade = 0.3 * Mid + 0.3 * Final + 0.4 * Homework;

        students.push_back({name, Grade});
    }

    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.grade > b.grade;
    });

    std::ofstream output("finalGrade");

    for(size_t i = 0; i < students.size(); ++i) {
        output << students[i].name << " : " << students[i].grade << "\n";
    }
    
    return 0;
}