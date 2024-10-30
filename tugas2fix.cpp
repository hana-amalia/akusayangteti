#include <iostream>
#define SIZE 20
using namespace std;

struct StudentType {
  string studentFName;
  string studentLName;
  int testScore;
  char grade;
};

// define array of StudentType with size of `SIZE`
StudentType students[SIZE];
int highestScoreIndex = 0;

// function definition to get data from user input
void getData() {
  for (int i = 0; i < SIZE; i++)
  {
    string scoreInput;

    cout << "Masukan data student " << i + 1 << endl;
    cout << "First name: ";
    getline(cin, students[i].studentFName);

    cout << "Last name: ";
    getline(cin, students[i].studentLName);

    cout << "Score: ";
    getline(cin, scoreInput);
    students[i].testScore = stoi(scoreInput);
    cout << "========" << endl;
  }
}

// function definition to set student's grade depending on score
void setGrade() {
  for (int i = 0; i < SIZE; i++){
    if (students[i].testScore > 90 && students[i].testScore <= 100)
    {
      students[i].grade = 'A';
    }
    else if (students[i].testScore > 80)
    {
      students[i].grade = 'B';
    }
    else if (students[i].testScore > 70)
    {
      students[i].grade = 'C';
    }
    else if (students[i].testScore > 60)
    {
      students[i].grade = 'D';
    }
    else if (students[i].testScore <= 60 && students[i].testScore >= 0)
    {
      students[i].grade = 'E';
    }
  }
}

// function definition to get highest student's score
int getMaxScore() {
  int currHighest = students[0].testScore;

  for (int i = 0; i < SIZE; i++) {
    int currValue = students[i].testScore;
    int currIndex = i;
    if (currValue > currHighest)
    {
      currHighest = currValue;
      highestScoreIndex = currIndex;
    }
  }

  return currHighest;
}

// function definitinon to print student's name with highest score
void getHighestScoreName() {
  string studentName = students[highestScoreIndex].studentFName + " " + students[highestScoreIndex].studentLName;
  cout << "Student Name: " << studentName << endl;
}

int main() {

  getData();

  setGrade();

  int highestStudentScore = getMaxScore();
  cout << "\nhighest score: " << highestStudentScore << endl;

  getHighestScoreName();
  return 0;
}