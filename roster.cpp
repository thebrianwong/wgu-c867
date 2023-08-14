#include <string>
#include <iostream>
using namespace std;

// #include "degree.h"
// #include "student.h"
#include "roster.h"
// #include "student.cpp"

// Requirement E3
Roster::~Roster()
{
  int i;
  for (i = 0; i < 5; ++i)
  {
    delete classRosterArray[i];
    classRosterArray[i] = nullptr;
    cout << "Releasing memory allocated for student " << i + 1 << "." << endl;
  }
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
  // this->classRosterArray[currentArrayIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
  // Student testStudent = *classRosterArray[currentArrayIndex];
  // this->currentArrayIndex += 1;

  Student *newStudent = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
  if (studentID == "A1")
  {
    classRosterArray[0] = newStudent;
  }
  else if (studentID == "A2")
  {
    classRosterArray[1] = newStudent;
  }
  else if (studentID == "A3")
  {
    classRosterArray[2] = newStudent;
  }
  else if (studentID == "A4")
  {
    classRosterArray[3] = newStudent;
  }
  else if (studentID == "A5")
  {
    classRosterArray[4] = newStudent;
  }
}

void Roster::remove(string studentID)
{
  cout << "Attempting to remove student with ID " << studentID << "." << endl;

  int i;
  int rosterArrayLength = 5;
  for (i = 0; i < rosterArrayLength; ++i)
  {
    Student *currentStudent = classRosterArray[i];
    string currentStudentID = currentStudent->getStudentID();
    if (currentStudentID == studentID)
    {
      delete classRosterArray[i];
      classRosterArray[i] = new Student();
      cout << "Student successfully removed." << endl
           << endl;
      return;
    }
  }
  cout << "A student with an ID of " << studentID << " could not be found." << endl
       << endl;
}

void Roster::printAll()
{
  cout << "Current Students:" << endl;

  int i;
  int rosterArrayLength = 5;
  for (i = 0; i < rosterArrayLength; ++i)
  {
    if (classRosterArray[i]->getFirstName() == "Skip Empty Student")
    {
      continue;
    }
    this->classRosterArray[i]->print();
  }
  cout << endl;
}

void Roster::printAverageDaysInCourse(string studentID)
{
  int i;
  int rosterArrayLength = 5;
  for (i = 0; i < rosterArrayLength; ++i)
  {
    Student currentStudent = *classRosterArray[i];
    string currentStudentID = currentStudent.getStudentID();
    if (currentStudentID == studentID)
    {
      int daysInCourse1 = currentStudent.getDaysInCourse1();
      int daysInCourse2 = currentStudent.getDaysInCourse2();
      int daysInCourse3 = currentStudent.getDaysInCourse3();
      double averageDaysInCourses = (daysInCourse1 + daysInCourse2 + daysInCourse3) / 3;
      cout << "Student ID " << studentID << " has an average of " << averageDaysInCourses << " days remaining in their courses." << endl;
      return;
    }
  }
  cout << "A student with an ID of " << studentID << " could not be found." << endl
       << endl;
  ;
}

void Roster::printInvalidEmails()
{
  cout << "Invalid Emails:" << endl;

  int i;
  int rosterArrayLength = 5;
  for (i = 0; i < rosterArrayLength; ++i)
  {
    Student currentStudent = *classRosterArray[i];
    string studentEmailAddress = currentStudent.getEmailAddress();
    int hasAtSign = studentEmailAddress.find("@");
    int hasPeriod = studentEmailAddress.find(".");
    int hasWhitespace = studentEmailAddress.find(" ");
    if ((hasAtSign == -1) || (hasPeriod == -1) || (hasWhitespace != -1))
    {
      cout << studentEmailAddress << endl;
    }
  }
  cout << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
  int i;
  int rosterArrayLength = 5;
  for (i = 0; i < rosterArrayLength; ++i)
  {
    Student currentStudent = *classRosterArray[i];
    DegreeProgram studentDegreeProgram = currentStudent.getDegreeProgram();
    if (studentDegreeProgram == degreeProgram)
    {
      currentStudent.print();
    }
  }
  cout << endl;
}