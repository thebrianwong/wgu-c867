#include <string>
#include <iostream>
using namespace std;

#include "student.h"
#include "degree.h"
#include "student.cpp"

int main()
{
  const string studentData[] =
      {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Brian,Wong,bwong28@wgu.edu,26,30,35,40,SOFTWARE"};

  Student myStudent = Student("A1", "John", "Smith", "John1989@gm ail.com", 20, 30, 35, 40, NETWORK);

  myStudent.print();

  return 0;
}