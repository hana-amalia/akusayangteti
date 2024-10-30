#include <iostream>
#define SIZE 20
using namespace std;

struct StudentType {
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

//def array of StudentType with the size of 'SIZE'
StudentType students[SIZE];

//function definition to get data from user's input
void getData(){
    for (int i = 0; i < SIZE; i++)
    {
        string scoreInput;

        cout << "Insert Student's Data" << i + 1 << endl;
        cout << "First Name: ";
        getline(cin, students[i].studentFName);

        cout << "Last Name: ";
        getline(cin, students[i].studentLName);

        cout << "Score: ";
        getline(cin, scoreInput);
        students[i].testScore = stoi(scoreInput);
        cout << "=================" << endl;
    }
}


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

// get students highest score
int getMaxScore() {
    int currHighest = students[0].testScore;

    for (int i = 0; i < SIZE; i++) {
        int currValue = students[i].testScore;
        if (currValue > currHighest)
        {
            currHighest = currValue;
        }
    }

    return currHighest;
}

int main() {

    getData();

    setGrade();

    int highestStudentScore = getMaxScore();
    cout << "Highest Score: " << highestStudentScore << endl;

    return 0;
}



