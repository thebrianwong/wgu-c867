#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;

#include "degree.h"

class Student
{
public: // Requirement D2
  Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
  string getStudentID();
  string getFirstName();
  string getLastName();
  string getEmailAddress();
  int getAge();
  int getDaysInCourse1();
  int getDaysInCourse2();
  int getDaysInCourse3();
  DegreeProgram getDegreeProgram();
  void setStudentID(string newStudentId);
  void setFirstName(string newFirstName);
  void setLastName(string newLastName);
  void setEmailAddress(string newEmailAddress);
  void setAge(int newAge);
  void setDaysInCourse1(int daysInCourse1);
  void setDaysInCourse2(int daysInCourse2);
  void setDaysInCourse3(int daysInCourse3);
  void setDegreeProgram(DegreeProgram newDegreeProgram);
  void print();

private: // Requirement D1
  string studentID;
  string firstName;
  string lastName;
  string emailAddress;
  int age;
  int daysInCourses[3];
  DegreeProgram degreeProgram;
};

#endif