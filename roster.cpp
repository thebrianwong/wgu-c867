#include <string>
#include <iostream>
using namespace std;

#include "degree.h"
// #include "student.h"
#include "roster.h"
#include "student.cpp"

// Requirement E3
Roster::Roster()
{
  classRosterArray[0] = NULL;
  classRosterArray[1] = NULL;
  classRosterArray[2] = NULL;
  classRosterArray[3] = NULL;
  classRosterArray[4] = NULL;
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
  Student newStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
  // cout << newStudent.getStudentID() << endl;
  // cout << classRosterArray << endl;
  // cout << classRosterArray[0]->getFirstName() << endl;
  cout << classRosterArray[0] << endl;
  if (!classRosterArray[0])
  {
    classRosterArray[0] = &newStudent;
  }
  else if (classRosterArray[1] == NULL)
  {
    classRosterArray[1] = &newStudent;
  }
  else if (classRosterArray[2] == NULL)
  {
    classRosterArray[2] = &newStudent;
  }
  else if (classRosterArray[3] == NULL)
  {
    classRosterArray[3] = &newStudent;
  }
  else if (classRosterArray[4] == NULL)
  {
    classRosterArray[4] = &newStudent;
  }
}
void Roster::remove(string studentID)
{
  int i;
  int rosterArrayLength = 5;
  for (i = 0; i < rosterArrayLength; ++i)
  {
    Student currentStudent = *classRosterArray[i];
    string currentStudentID = currentStudent.getStudentID();
    if (currentStudentID == studentID)
    {
      delete classRosterArray[i];
      return;
    }
  }
  cout << "A student with an ID of " << studentID << " could not be found." << endl;
}
void Roster::printAll()
{
  int i;
  int rosterArrayLength = 5;
  for (i = 0; i < rosterArrayLength; ++i)
  {
    cout << "error here?" << endl;
    cout << classRosterArray << endl;
    cout << classRosterArray[0] << endl;
    cout << classRosterArray[1] << endl;
    cout << classRosterArray[2] << endl;
    cout << classRosterArray[3] << endl;
    cout << classRosterArray[4] << endl;
    Student currentStudentPointer = *classRosterArray[i];
    Student currentStudent = currentStudentPointer;
    cout << currentStudent.getAge() << endl;
    currentStudent.print();
  }
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
  cout << "A student with an ID of " << studentID << " could not be found." << endl;
}
void Roster::printInvalidEmails()
{
  int i;
  int rosterArrayLength = 5;
  cout << "Invalid Emails" << endl;
  for (i = 0; i < rosterArrayLength; ++i)
  {
    Student currentStudent = *classRosterArray[i];
    string studentEmailAddress = currentStudent.getEmailAddress();
    int hasAtSign = studentEmailAddress.find("@");
    int hasPeriod = studentEmailAddress.find(".");
    int hasWhitespace = studentEmailAddress.find(" ");
    if ((!hasAtSign) || (!hasPeriod) || (hasWhitespace))
    {
      cout << studentEmailAddress << endl;
    }
  }
}
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
  int i;
  int rosterArrayLength = 5;
  cout << "Students in the " << degreeProgram << " degree program." << endl;
  for (i = 0; i < rosterArrayLength; ++i)
  {
    Student currentStudent = *classRosterArray[i];
    DegreeProgram studentDegreeProgram = currentStudent.getDegreeProgram();
    if (studentDegreeProgram == degreeProgram)
    {
      currentStudent.print();
    }
  }
}