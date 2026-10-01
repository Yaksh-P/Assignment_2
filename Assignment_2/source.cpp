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

    if (!file.is_open())
    {
        cout << "ERROR: StudentData.txt could not be opened." << endl;
        return 1;
    }

    string line;

    while (getline(file, line))
    {
        size_t commaPosition = line.find(',');

        if (commaPosition != string::npos)
        {
            STUDENT_DATA student;

            student.lastName = line.substr(0, commaPosition);
            student.firstName = line.substr(commaPosition + 1);

            // Remove leading space before first name
            if (!student.firstName.empty() && student.firstName[0] == ' ')
            {
                student.firstName.erase(0, 1);
            }

            students.push_back(student);
        }
    }

    file.close();

#ifdef _DEBUG

    cout << "DEBUG MODE" << endl;
    cout << "Student Data:" << endl;
    cout << "------------------------" << endl;

    for (const auto& student : students)
    {
        cout << student.lastName << ", "
             << student.firstName << endl;
    }

#endif

    return 1;
}