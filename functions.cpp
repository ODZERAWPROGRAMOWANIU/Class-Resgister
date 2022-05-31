#include <iostream>
#include <vector>
#include <tuple>
#include <iomanip>
#include <ctime>
#include "headers.h"
using namespace std;
vector<string> attendanceAtTheLesson;
vector<tuple<string, string, float, float, float, float, float> > studentToAdd;
void checkAttendance()
{
  char attendance;
  float amountOfAttendance = 0;
  cout << "Enter P or p if student is present and A or a if absent" << endl;
  cin >> attendance;
  if (attendance == 'P' || attendance == 'p')
  {
    attendanceAtTheLesson.push_back("Present");
  }
  if (attendance == 'A' || attendance == 'a')
  {
    attendanceAtTheLesson.push_back("Absent");
  }
}
void addStudent()
{
  string firstN, secondN;
  float grade1, grade2, grade3, grade4, grade5;
  cout << "Enter how many students you wanna add: " << endl;
  int amount;
  cin >> amount;
  while (amount--)
  {
    cout << "First enter second name, then first, and enter first five grades of student" << endl;
    cin >> firstN >> secondN >> grade1 >> grade2 >> grade3 >> grade4 >> grade5;
    firstN[0] = toupper(firstN[0]);
    secondN[0] = toupper(secondN[0]);
    studentToAdd.push_back(make_tuple(firstN, secondN, grade1, grade2, grade3, grade4, grade5));
    checkAttendance();
  }
}
void allStudentsWithGrades()
{
  if (studentToAdd.size() < 1)
  {
    cout << "If you want show something first you have to add students!" << endl;
  }
  for (int i = 0; i < studentToAdd.size(); i++)
  {
    cout << i + 1 << ".";
    cout << get<0>(studentToAdd[i]) << " ";
    cout << get<1>(studentToAdd[i]) << " ";
    cout << get<2>(studentToAdd[i]) << " ";
    cout << get<3>(studentToAdd[i]) << " ";
    cout << get<4>(studentToAdd[i]) << " ";
    cout << get<5>(studentToAdd[i]) << " ";
    cout << get<6>(studentToAdd[i]) << endl;
  }
}
void calculateAverage()
{
  vector<float> allAverages;
  for (auto &&tuple : studentToAdd)
  {
    float n1, n2, n3, n4, n5;
    tie(ignore, ignore, n1, n2, n3, n4, n5) = tuple;
    float average = (n1 + n2 + n3 + n4 + n5) / 5;
    allAverages.push_back(average);
    average = 0;
  }
  if (allAverages.size() < 1)
  {
    cout << "If you want show something first you have to add students!" << endl;
  }
  for (int i = 0; i < studentToAdd.size(); i++)
  {
    cout << i + 1 << ".";
    cout << get<0>(studentToAdd[i]) << " ";
    cout << get<1>(studentToAdd[i]) << " ";
    cout << setprecision(2) << allAverages[i] << endl;
  }
}
void showAttendance()
{
  if (attendanceAtTheLesson.size() < 1)
  {
    cout << "First you have to check attendance and then print it" << endl;
  }
  for (int i = 0; i < studentToAdd.size(); i++)
  {
    cout << i + 1 << ".";
    cout << get<0>(studentToAdd[i]) << " ";
    cout << get<1>(studentToAdd[i]) << " ";
    cout << attendanceAtTheLesson[i] << endl;
  }
}
void drawStudent()
{
  srand(time(NULL));
  int temp = studentToAdd.size();
  int numberOfStudent = (rand() % temp) + 1;
  cout << "The student with the number: " << numberOfStudent << " goes to the answer" << endl;
  cout << "So it's: " << endl;
  cout << get<0>(studentToAdd[numberOfStudent - 1]) << " ";
  cout << get<1>(studentToAdd[numberOfStudent - 1]) << endl;
}