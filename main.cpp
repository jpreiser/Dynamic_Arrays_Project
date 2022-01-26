#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>
#include <limits>
#include "Student.h"
#include "Instructor.h"

using namespace std;

Student students[20];
Instructor instructors[3];

/* A method to print the greeting to the user */
void printGreeting() {
    cout << "User types,\n\t1 - Instructor\n\t2 - Student" << endl;
} // printGreeting

void createStudents() {

    int i = 0;
    ifstream sFile ("students.txt");

    if (sFile.is_open()) {

        string username, password, fname, lname;
        int pgrade, qgrade, mgrade, fgrade;

        while (sFile >> username >> password >> fname >> lname >> pgrade >>
               qgrade >> mgrade >> fgrade && i <= 20) {
            students[i].setUserName(username);
            students[i].setPassword(password);
            students[i].setStudentName(fname, lname);
            students[i].setProjectGrade(pgrade);
            students[i].setQuizGrade(qgrade);
            students[i].setMidtermGrade(mgrade);
            students[i].setFinalGrade(fgrade);
            i = i + 1;
        }
    }
    sFile.close();

} // createStudents

void createInstructors() {

    int j = 0;
    ifstream iFile("instructors.txt");

    if (iFile.is_open()) {
        string username, password, fname, lname;
        while(iFile >> username >> password >> fname >> lname && j <= 3) {
            instructors[j].setUserName(username);
            instructors[j].setPassword(password);
            instructors[j].setInstructorName(fname, lname);
            cout << "creating teacher " << j << endl;
            cout << instructors[j].getUserName() << endl;
            j = j + 1;
            //cout << username << " " << password << endl;
        }
    }

} // createInstructors

/* The method to run if an instructor account is selected. */
int instructorAccount() {

    Student stu;
    Instructor inst;
    string iUser, iPass, sUser;
    int query;

    // login loop
    cout << "Enter credentials to login, \n\tEnter username: ";
    cin >> iUser;
    cout << "\tEnter password: ";
    cin >> iPass;

    while(1) {
        for (int i = 0; i < 3; i++) {
            if (instructors[i].login(iUser, iPass)) {
                inst = instructors[i];
                cout << "You are now logged in as instructor " << inst.getInstructorName()
                     << "." << endl;
                while(1) {
                    cout << "Query options,\n\t1 - view grades of a student\n\t2 - view stats"
                         << endl;
                    cout << "Enter option number: ";
                    cin >> query;
                    if (query == 1) {
                        cout << "Enter student username to view grades: ";
                        cin >> sUser;
                        stu = inst.getStudent(students, sUser);
                        if (stu.isSet()) {
                            cout << "\tStudent name: " << stu.getStudentName() << endl;
                            cout << "\tProject\t" << stu.getProjectGrade() << "%" << endl;
                            cout << "\tQuiz\t" << stu.getQuizGrade() << "%" << endl;
                            cout << "\tMidterm\t" << stu.getMidtermGrade() << "%" << endl;
                            cout << "\tFinalt\t" << stu.getFinalGrade() << "%" << endl;
                            cout << "\tOverall\t" << stu.getOverallGrade() << "%" << endl;
                            return 0;
                        }
                    } else if ( query == 2) {
                        int gradeType;
                        cout << "Grade types,\n\t1 - Project grade\n\t2 - Quiz grade\n\t3 - Midterm grade\n\t4 - Final grade\n\t5 - Overall grade\nSelect a grade type to view stats: ";
                        cin >> gradeType;
                        if (gradeType == 1) {
                            cout << "Overall grade stats,\nmin\t";
                            inst.getMinStudent(students, 1);
                            cout << "max\t";
                            inst.getMaxStudent(students, 1);
                            cout << "avg\t";
                            inst.getAvg(students, 1);
                            return 0;
                        } else if (gradeType == 2) {
                            cout << "Overall grade stats,\nmin\t";
                            inst.getMinStudent(students, 2);
                            cout << "max\t";
                            inst.getMaxStudent(students, 2);
                            cout << "avg\t";
                            inst.getAvg(students, 2);
                            return 0;
                        } else if (gradeType == 3) {
                            cout << "Overall grade stats,\nmin\t";
                            inst.getMinStudent(students, 3);
                            cout << "max\t";
                            inst.getMaxStudent(students, 3);
                            cout << "avg\t";
                            inst.getAvg(students, 3);
                            return 0;
                        } else if (gradeType == 4) {
                            cout << "Overall grade stats,\nmin\t";
                            inst.getMinStudent(students, 4);
                            cout << "max\t";
                            inst.getMaxStudent(students, 4);
                            cout << "avg\t";
                            inst.getAvg(students, 4);
                            return 0;
                        } else if (gradeType == 5) {
                            cout << "Overall grade stats,\nmin\t";
                            inst.getMinStudent(students, 5);
                            cout << "max\t";
                            inst.getMaxStudent(students, 5);
                            cout << "avg\t";
                            inst.getAvg(students, 5);
                            return 0;
                        } else {
                            cout << "Invalid option. Please enter a valid option." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    } else {
                        cout << "Invalid option. Please enter a valid option." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    } // instructor decision loop.
                }
            } else {
                cout << "Login as instructor failed." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return 0;
            }
        }
    }
    return 0;
} // instructorAccount

/* The method to run if a student account is selected. */
int studentAccount() {

    string sUser, sPass, viewGrades;
    int i;

    cout << "Enter credentials to login, \n\tEnter username: ";
    cin >> sUser;
    cout << "\tEnter password: ";
    cin >> sPass;

    // main loop of student account
    while(1) {
        // check for successful login
        for (i = 0; i < 20; i++) {
            if (students[i].login(sUser, sPass)) {
                while (1) {
                    cout << "You are now logged in as student " <<
                        students[i].getStudentName() << endl;
                    cout << "Do you want to view grades? (y/n)? ";
                    cin >> viewGrades;
                    if (viewGrades == "y") {
                        cout << "Student name: " << students[i].getStudentName() << endl;
                        cout << "\tProject\t" << students[i].getProjectGrade() << "%" << endl;
                        cout << "\tQuiz\t" << students[i].getQuizGrade() << "%" << endl;
                        cout << "\tMidterm\t" << students[i].getMidtermGrade() << "%" << endl;
                        cout << "\tFinalt\t" << students[i].getFinalGrade() << "%" << endl;
                        cout << "\tOverall\t" << students[i].getOverallGrade() << "%" << endl;
                        return 0;
                    } else if (viewGrades == "n") {
                        return 0;
                    } else {
                        cout << "Invalid option, please try again." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
            }
        }
        cout << "Login as student failed" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return 0;
    }
    return 0;
} // studentAccount

int main(int argc, char *argv[]) {

    int numStuds, numInsts, userType;

    /* Check that program was launched with correct files. */
    if (argc != 3) {
        cout << "Usage: main [instructors_file] [students_file]" << endl;
        return 1;
    } else if (strcmp(argv[1], "instructors.txt") != 0 || strcmp(argv[2], "students.txt") != 0) {
        cout << "Usage: ./main instructors.txt students.txt" << endl;
        return 1;
    }


    createInstructors();
    createStudents();

    cout << "Parsing instructors and students information success.\n..." << endl;

    /* While loop where the user interacts*/
    while(1) {
        printGreeting();
        cout << "Select a login user type or enter 3 to exit: ";
        cin >> userType;
        if (userType == 1) {
            instructorAccount();
        } else if (userType == 2) {
            studentAccount();
        } else if (userType == 3) {
            return(0);
        } else {
            //clear cin so it only displays error once.
            cerr << "Invalid option. Please enter a valid option." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } // main interface loop.
    } // while

    return 0;
} // main
