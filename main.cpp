#include <string>
#include <sstream>
#include <iostream>
using namespace std;

// #include "degree.h"
#include "student.cpp"
// #include "student.h"
#include "roster.cpp"
// #include "roster.h"

// move to Roster, follow cohort 3 video
// Requirement E2
void parseStudentData(const string studentData[], Roster &classRoster)
{
  int i;
  const int numOfStudents = 5;
  for (i = 0; i < numOfStudents; ++i)
  {
    string studentInfoString = studentData[i];
    stringstream infoSS(studentInfoString);

    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int day1;
    int day2;
    int day3;
    DegreeProgram degreeProgram;

    string token;
    int infoIndex = 0;
    while (getline(infoSS, token, ','))
    {
      switch (infoIndex)
      {
      case 0:
        studentID = token;
        break;
      case 1:
        firstName = token;
        break;
      case 2:
        lastName = token;
        break;
      case 3:
        emailAddress = token;
        break;
      case 4:
        age = stoi(token);
        break;
      case 5:
        day1 = stoi(token);
        break;
      case 6:
        day2 = stoi(token);
        break;
      case 7:
        day3 = stoi(token);
        break;
      case 8:
        if (token == "SECURITY")
        {
          degreeProgram = SECURITY;
        }
        else if (token == "NETWORK")
        {
          degreeProgram = NETWORK;
        }
        else
        {
          degreeProgram = SOFTWARE;
        }
        break;
      default:
        break;
      }
      infoIndex += 1;
    }
    // Requirement F3
    classRoster.add(studentID, firstName, lastName, emailAddress, age, day1, day2, day3, degreeProgram);
  }
}

int main()
{
  // Requirement A
  const string studentData[] =
      {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
       "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
       "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
       "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
       "A5,Brian,Wong ,bwong28@wgu.edu,26,30,35,40,SOFTWARE"};

  // Requirement F1
  cout << "Application Introduction:" << endl
       << endl;
  cout << "Course Title: Scripting and Programming - Applications - C867" << endl;
  cout << "Programming Language: C++" << endl;
  cout << "WGU Student ID: 011147336" << endl;
  cout << "Name: Brian Wong" << endl
       << endl;
  ;

  // Requirement F2
  Roster classRoster;

  // loop through students and call Roster parse function, and pass student string
  parseStudentData(studentData, classRoster);

  // int i;

  // for (i = 0; i < 5; ++i)
  // {
  //   classRoster.parseStudentInfo(studentData[i]);
  // }

  // Requirement F4
  classRoster.printAll();

  // classRoster.printInvalidEmails();

  // int i;

  // cout << "Average Days:" << endl;
  // for (i = 1; i <= 5; ++i)
  // {
  //   string prefixID = "A";
  //   string suffixID = to_string(i);
  //   string studentID = prefixID + suffixID;
  //   classRoster.printAverageDaysInCourse(studentID);
  // }
  // cout << endl;

  // cout << "Students in the Software degree program." << endl;
  // classRoster.printByDegreeProgram(SOFTWARE);

  // classRoster.remove("A3");

  // classRoster.printAll();

  // classRoster.remove("A3");

  return 0;
}