#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;

#include "degree.h"

class Student
{
public: // Requirement D2
  Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
  Student();
  ~Student();
  string getStudentID();
  string getFirstName();
  string getLastName();
  string getEmailAddress();
  int getAge();
  int *getDaysInCourses();
  DegreeProgram getDegreeProgram();
  void setStudentID(string newStudentId);
  void setFirstName(string newFirstName);
  void setLastName(string newLastName);
  void setEmailAddress(string newEmailAddress);
  void setAge(int newAge);
  void setDaysInCourses(int daysInCourse[]);
  void setDegreeProgram(DegreeProgram newDegreeProgram);
  void print();

private: // Requirement D1
  static const int numberOfCourses = 3;
  string studentID;
  string firstName;
  string lastName;
  string emailAddress;
  int age;
  int daysInCourses[numberOfCourses];
  DegreeProgram degreeProgram;
};

#endif
