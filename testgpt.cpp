#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int NUM_STUDENTS = 3;

struct studentType {
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

// Function prototypes
void readData(studentType students[], int size);
void assignGrades(studentType students[], int size);
int findHighestScore(studentType students[], int size);
void printHighestScorers(studentType students[], int size, int highestScore);
void printStudentsData(const studentType students[], int size);

int main() {
    studentType students[NUM_STUDENTS];
    
    readData(students, NUM_STUDENTS);
    assignGrades(students, NUM_STUDENTS);
    int highestScore = findHighestScore(students, NUM_STUDENTS);
    
    cout << "\nStudents' Data:\n";
    printStudentsData(students, NUM_STUDENTS);
    
    cout << "\nHighest Scorers:\n";
    printHighestScorers(students, NUM_STUDENTS, highestScore);
    
    return 0;
}

void readData(studentType students[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter first name of student " << (i + 1) << ": ";
        cin >> students[i].studentFName;
        cout << "Enter last name of student " << (i + 1) << ": ";
        cin >> students[i].studentLName;
        cout << "Enter test score (0-100) for " << students[i].studentFName << " " << students[i].studentLName << ": ";
        cin >> students[i].testScore;
    }
}

void assignGrades(studentType students[], int size) {
    for (int i = 0; i < size; i++) {
        if (students[i].testScore >= 90)
            students[i].grade = 'A';
        else if (students[i].testScore >= 80)
            students[i].grade = 'B';
        else if (students[i].testScore >= 70)
            students[i].grade = 'C';
        else if (students[i].testScore >= 60)
            students[i].grade = 'D';
        else
            students[i].grade = 'F';
    }
}

int findHighestScore(studentType students[], int size) {
    int highest = students[0].testScore;
    for (int i = 1; i < size; i++) {
        if (students[i].testScore > highest) {
            highest = students[i].testScore;
        }
    }
    return highest;
}

void printHighestScorers(studentType students[], int size, int highestScore) {
    for (int i = 0; i < size; i++) {
        if (students[i].testScore == highestScore) {
            cout << students[i].studentLName << ", " << students[i].studentFName << endl;
        }
    }
}

void printStudentsData(const studentType students[], int size) {
    for (int i = 0; i < size; i++) {
        cout << left << setw(15) << students[i].studentLName + ", " + students[i].studentFName;
        cout << students[i].testScore << " " << students[i].grade << endl;
    }
}
