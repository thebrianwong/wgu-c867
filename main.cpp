#include <string>
#include <sstream>
#include <iostream>
using namespace std;

#include "degree.h"
#include "student.h"
#include "roster.h"

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

  for (int i = 0; i < Roster::numOfStudents; ++i)
  {
    classRoster.parseStudentInfo(studentData[i]);
  }

  // Requirement F4
  classRoster.printAll();

  classRoster.printInvalidEmails();

  cout << "Average Days:" << endl;
  for (int i = 1; i <= Roster::numOfStudents; ++i)
  {
    string prefixID = "A";
    string suffixID = to_string(i);
    string studentID = prefixID + suffixID;
    classRoster.printAverageDaysInCourse(studentID);
  }
  cout << endl;

  cout << "Students in the Software degree program." << endl;
  classRoster.printByDegreeProgram(SOFTWARE);

  classRoster.remove("A3");

  classRoster.printAll();

  classRoster.remove("A3");

  return 0;
}
