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

string Student::getStudentID()
{
  return studentID;
}
string Student::getFirstName()
{
  return firstName;
}
string Student::getLastName()
{
  return lastName;
}
string Student::getEmailAddress()
{
  return emailAddress;
}
int Student::getAge()
{
  return age;
}
int Student::getDaysInCourse1()
{
  return daysInCourses[0];
}
int Student::getDaysInCourse2()
{
  return daysInCourses[1];
}
int Student::getDaysInCourse3()
{
  return daysInCourses[2];
}
DegreeProgram Student::getDegreeProgram()
{
  return degreeProgram;
}
void Student::setStudentID(string newStudentId)
{
  studentID = newStudentId;
}
void Student::setFirstName(string newFirstName)
{
  firstName = newFirstName;
}
void Student::setLastName(string newLastName)
{
  lastName = newLastName;
}
void Student::setEmailAddress(string newEmailAddress)
{
  emailAddress = newEmailAddress;
}
void Student::setAge(int newAge)
{
  age = newAge;
}
void Student::setDaysInCourse1(int newDaysInCourse1)
{
  daysInCourses[0] = newDaysInCourse1;
}
void Student::setDaysInCourse2(int newDaysInCourse2)
{
  daysInCourses[1] = newDaysInCourse2;
}
void Student::setDaysInCourse3(int newDaysInCourse3)
{
  daysInCourses[2] = newDaysInCourse3;
}
void Student::setDegreeProgram(DegreeProgram newDegreeProgram)
{
  degreeProgram = newDegreeProgram;
}
void Student::print()
{
  cout << studentID << "\t";
  cout << "First Name: " << firstName << "\t";
  cout << "Last Name: " << lastName << "\t";
  cout << "Age: " << age << "\t";
  cout << "daysInCourse: {" << daysInCourses[0] << ", " << daysInCourses[1] << ", " << daysInCourses[2] << "} ";
  cout << "Degree Program: " << degreeProgram << "." << endl;
}