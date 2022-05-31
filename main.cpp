#include <iostream>
#include "headers.h"
#include <vector>
#include <tuple>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<tuple<string, string, float, float, float, float, float> > studentToAdd;
  int choice;
  while (true)
  {
    cout << "---------------------" << endl;
    cout << "CLASS REGISTER" << endl;
    cout << "---------------------" << endl;
    cout << "MENU" << endl;
    cout << "---------------------" << endl;
    cout << "Press what you wanna do: " << endl;
    cout << "---------------------" << endl;
    cout << "1.Add a student with grades to a system" << endl;
    cout << "2.Show students and their grades" << endl;
    cout << "3.Calculate average arithmetic of grades" << endl;
    cout << "4.Show attendance" << endl;
    cout << "5.Randomize a student for a answer" << endl;
    cout << "6.Clear screen" << endl;
    cout << "7.EXIT" << endl;
    cin >> choice;
    system("clear");
    switch (choice)
    {
    case 1:
      addStudent();
      break;
    case 2:
      allStudentsWithGrades();
      break;
    case 3:
      calculateAverage();
      break;
    case 4:
      showAttendance();
      break;
    case 5:
      drawStudent();
      break;
    case 6:
      system("clear");
      break;
    case 7:
      cout << "Thank you for using" << endl;
      exit(0);
      break;
    default:
      cout << "You have choosen a wrong number, try one more time!" << endl;
    }
  }
  return 0;
}
