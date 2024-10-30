#include <iostream>
#include <iomanip>
#define SIZE 20
using namespace std;

struct StudentType {
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

// Define array of StudentType with size of `SIZE`
StudentType students[SIZE];
int highestScoreIndex = 0;

// Function definition to get data from user input
void getData() {
    for (int i = 0; i < SIZE; i++) {
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

// Function definition to set student's grade depending on score
void setGrade() {
    for (int i = 0; i < SIZE; i++) {
        if (students[i].testScore >= 90) {
            students[i].grade = 'A';
        } else if (students[i].testScore >= 80) {
            students[i].grade = 'B';
        } else if (students[i].testScore >= 70) {
            students[i].grade = 'C';
        } else if (students[i].testScore >= 60) {
            students[i].grade = 'D';
        } else {
            students[i].grade = 'F';
        }
    }
}

// function definition highest student score
int getMaxScore() {
    int currHighest = students[0].testScore;

    for (int i = 0; i < SIZE; i++) {
        int currValue = students[i].testScore;
        int currIndex = i;
        if (currValue > currHighest) {
            currHighest = currValue;
            highestScoreIndex = currIndex;
        }
    }
    return currHighest;
}

// function definition to print students data
void printStudentsData() {
    cout << left << setw(15) << "Name"
         << setw(10) << "Score"
         << "Grade" << endl;

    for (int i = 0; i < SIZE; i++) {
        cout << left << setw(20) << students[i].studentLName + ", " + students[i].studentFName
             << setw(10) << students[i].testScore
             << students[i].grade << endl;
    }
}

// printing names of student with highest score
void getHighestScoreName() {
    int highestScore = getMaxScore();
    cout << "\nHighest Score: " << highestScore << endl;
    cout << "Students with highest score: " << endl;
    for (int i = 0; i < SIZE; i++) {
        if (students[i].testScore == highestScore) {
            cout << students[i].studentLName << ", " << students[i].studentFName << endl;
        }
    }
}

int main() {
    getData();
    setGrade();

    cout << "\nStudents' Data:\n";
    printStudentsData();

    getHighestScoreName();
    return 0;
}