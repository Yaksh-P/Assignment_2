#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct STUDENT_DATA
{
    string lastName;
    string firstName;
};

int main()
{
    vector<STUDENT_DATA> students;

    ifstream file("StudentData.txt");

    string line;

    while (getline(file, line))
    {
        size_t commaPosition = line.find(',');

        STUDENT_DATA student;

        student.lastName = line.substr(0, commaPosition);
        student.firstName = line.substr(commaPosition + 1);

        students.push_back(student);
    }

    file.close();

    return 1;
}