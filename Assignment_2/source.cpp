#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct STUDENT_DATA
{
    string lastName;
    string firstName;
    string email;
};

int main()
{
    vector<STUDENT_DATA> students;

#ifdef PRE_RELEASE

    cout << "Running PRE-RELEASE Version" << endl;
    ifstream file("StudentData_Emails.txt");

#else

    cout << "Running STANDARD Version" << endl;
    ifstream file("StudentData.txt");

#endif

    if (!file.is_open())
    {
        cout << "ERROR: Input file could not be opened." << endl;
        return 1;
    }

    string line;

    while (getline(file, line))
    {
        STUDENT_DATA student;

#ifdef PRE_RELEASE

        size_t firstComma = line.find(',');
        size_t secondComma = line.find(',', firstComma + 1);

        if (firstComma != string::npos &&
            secondComma != string::npos)
        {
            student.lastName =
                line.substr(0, firstComma);

            student.firstName =
                line.substr(firstComma + 1,
                    secondComma - firstComma - 1);

            student.email =
                line.substr(secondComma + 1);

            if (!student.firstName.empty() &&
                student.firstName[0] == ' ')
            {
                student.firstName.erase(0, 1);
            }

            students.push_back(student);
        }

#else

        size_t commaPosition = line.find(',');

        if (commaPosition != string::npos)
        {
            student.lastName =
                line.substr(0, commaPosition);

            student.firstName =
                line.substr(commaPosition + 1);

            if (!student.firstName.empty() &&
                student.firstName[0] == ' ')
            {
                student.firstName.erase(0, 1);
            }

            students.push_back(student);
        }

#endif
    }

    file.close();

#ifdef _DEBUG

    cout << "\nDEBUG MODE" << endl;
    cout << "Student Data:" << endl;
    cout << "------------------------" << endl;

    for (const auto& student : students)
    {
        cout << student.lastName
            << ", "
            << student.firstName;

#ifdef PRE_RELEASE
        cout << ", " << student.email;
#endif

        cout << endl;
    }

#endif

    return 1;
}