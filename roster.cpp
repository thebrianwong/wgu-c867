#include "roster.h"

// Requirement E3
Roster::~Roster() // Requirement F5
{
  for (int i = 0; i < Roster::numOfStudents; ++i)
  {
    delete classRosterArray[i];
    classRosterArray[i] = nullptr;
    cout << "Releasing memory allocated for student " << i + 1 << "." << endl;
  }
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
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

  for (int i = 0; i < Roster::numOfStudents; ++i)
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

  for (int i = 0; i < Roster::numOfStudents; ++i)
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
  for (int i = 0; i < Roster::numOfStudents; ++i)
  {
    Student currentStudent = *classRosterArray[i];
    string currentStudentID = currentStudent.getStudentID();
    if (currentStudentID == studentID)
    {
      int daysInCourse1 = currentStudent.getDaysInCourses()[0];
      int daysInCourse2 = currentStudent.getDaysInCourses()[1];
      int daysInCourse3 = currentStudent.getDaysInCourses()[2];
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

  for (int i = 0; i < Roster::numOfStudents; ++i)
  {
    Student currentStudent = *classRosterArray[i];
    string studentEmailAddress = currentStudent.getEmailAddress();
    unsigned long hasAtSign = studentEmailAddress.find("@");
    unsigned long hasPeriod = studentEmailAddress.find(".");
    unsigned long hasWhitespace = studentEmailAddress.find(" ");
    if ((hasAtSign == -1) || (hasPeriod == -1) || (hasWhitespace != -1))
    {
      cout << studentEmailAddress << endl;
    }
  }
  cout << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
  for (int i = 0; i < Roster::numOfStudents; ++i)
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

void Roster::parseStudentInfo(string studentInfo)
{
  size_t rightIndex = studentInfo.find(",");
  string studentID = studentInfo.substr(0, rightIndex);

  size_t leftIndex = rightIndex + 1;
  rightIndex = studentInfo.find(",", leftIndex);
  string firstName = studentInfo.substr(leftIndex, rightIndex - leftIndex);

  leftIndex = rightIndex + 1;
  rightIndex = studentInfo.find(",", leftIndex);
  string lastName = studentInfo.substr(leftIndex, rightIndex - leftIndex);

  leftIndex = rightIndex + 1;
  rightIndex = studentInfo.find(",", leftIndex);
  string emailAddress = studentInfo.substr(leftIndex, rightIndex - leftIndex);

  leftIndex = rightIndex + 1;
  rightIndex = studentInfo.find(",", leftIndex);
  int age = stoi(studentInfo.substr(leftIndex, rightIndex - leftIndex));

  leftIndex = rightIndex + 1;
  rightIndex = studentInfo.find(",", leftIndex);
  int daysInCourse1 = stoi(studentInfo.substr(leftIndex, rightIndex - leftIndex));

  leftIndex = rightIndex + 1;
  rightIndex = studentInfo.find(",", leftIndex);
  int daysInCourse2 = stoi(studentInfo.substr(leftIndex, rightIndex - leftIndex));

  leftIndex = rightIndex + 1;
  rightIndex = studentInfo.find(",", leftIndex);
  int daysInCourse3 = stoi(studentInfo.substr(leftIndex, rightIndex - leftIndex));

  leftIndex = rightIndex + 1;
  rightIndex = studentInfo.find(",", leftIndex);
  DegreeProgram degreeProgram;
  string degreeProgramString = studentInfo.substr(leftIndex, rightIndex - leftIndex);

  if (degreeProgramString == "SECURITY")
  {
    degreeProgram = SECURITY;
  }
  else if (degreeProgramString == "NETWORK")
  {
    degreeProgram = NETWORK;
  }
  else
  {
    degreeProgram = SOFTWARE;
  }

  Roster::add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}
