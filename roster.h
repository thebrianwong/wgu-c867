#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include <iostream>
#include "degree.h"
#include "student.h"

class Roster
{
public: // Requirement E3
  static const int numOfStudents = 5;
  ~Roster();
  void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
  void remove(string studentID);
  void printAll();
  void printAverageDaysInCourse(string studentID);
  void printInvalidEmails();
  void printByDegreeProgram(DegreeProgram degreeProgram);
  void parseStudentInfo(string studentInfo);
  Student *classRosterArray[numOfStudents]; // Requirement E1
};

#endif
