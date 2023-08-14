#include <string>
#include <iostream>
using namespace std;

#include "degree.h"
#include "student.h"

// Requirement D2
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
  this->studentID = studentID;
  this->firstName = firstName;
  this->lastName = lastName;
  this->emailAddress = emailAddress;
  this->age = age;
  this->daysInCourses[0] = daysInCourse1;
  this->daysInCourses[1] = daysInCourse2;
  this->daysInCourses[2] = daysInCourse3;
  this->degreeProgram = degreeProgram;
}

Student::Student()
{
  this->studentID = "Invalid";
  this->firstName = "Skip Empty Student";
}

string Student::getStudentID()
{
  return this->studentID;
}

string Student::getFirstName()
{
  return this->firstName;
}

string Student::getLastName()
{
  return this->lastName;
}

string Student::getEmailAddress()
{
  return this->emailAddress;
}

int Student::getAge()
{
  return this->age;
}

int Student::getDaysInCourse1()
{
  return this->daysInCourses[0];
}

int Student::getDaysInCourse2()
{
  return this->daysInCourses[1];
}

int Student::getDaysInCourse3()
{
  return this->daysInCourses[2];
}

DegreeProgram Student::getDegreeProgram()
{
  return this->degreeProgram;
}

void Student::setStudentID(string newStudentId)
{
  this->studentID = newStudentId;
}

void Student::setFirstName(string newFirstName)
{
  this->firstName = newFirstName;
}

void Student::setLastName(string newLastName)
{
  this->lastName = newLastName;
}

void Student::setEmailAddress(string newEmailAddress)
{
  this->emailAddress = newEmailAddress;
}

void Student::setAge(int newAge)
{
  this->age = newAge;
}

void Student::setDaysInCourse1(int newDaysInCourse1)
{
  this->daysInCourses[0] = newDaysInCourse1;
}

void Student::setDaysInCourse2(int newDaysInCourse2)
{
  this->daysInCourses[1] = newDaysInCourse2;
}

void Student::setDaysInCourse3(int newDaysInCourse3)
{
  this->daysInCourses[2] = newDaysInCourse3;
}

void Student::setDegreeProgram(DegreeProgram newDegreeProgram)
{
  this->degreeProgram = newDegreeProgram;
}

void Student::print()
{
  // Get the corresponding string from each enum
  DegreeProgram degreeProgram = this->getDegreeProgram();
  string degreeProgramString;
  switch (degreeProgram)
  {
  case SECURITY:
    degreeProgramString = "SECURITY";
    break;
  case NETWORK:
    degreeProgramString = "NETWORK";
    break;
  case SOFTWARE:
    degreeProgramString = "SOFTWARE";
    break;

  default:
    break;
  }

  cout << "Student ID: " << this->getStudentID() << "\t";
  cout << "First Name: " << this->getFirstName() << "\t";
  cout << "Last Name: " << this->getLastName() << "\t";
  cout << "Age: " << this->getAge() << "\t";
  cout << "Days In Courses: {" << this->getDaysInCourse1() << ", " << this->getDaysInCourse2() << ", " << this->getDaysInCourse3() << "}\t";
  cout << "Degree Program: " << degreeProgramString << endl;
}