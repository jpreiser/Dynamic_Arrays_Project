#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>
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

        while (sFile >> username >> password >> fname >> lname >> pgrade >> qgrade >> mgrade >> fgrade && i++ < 20) {
            students[i].setUserName(username);
            students[i].setPassword(password);
            students[i].setStudentName(fname, lname);
            students[i].setProjectGrade(pgrade);
            students[i].setQuizGrade(qgrade);
            students[i].setMidtermGrade(mgrade);
            students[i].setFinalGrade(fgrade);
            cout << "Student " << i << " created." << endl;
            cout << username << password << fname << " " << lname << endl;
            cout << "student " << i << "'s username : "<<  students[i].getUserName() << endl;
        }
    }

} // createStudents

void createInstructors() {

    int i = 0;
    ifstream iFile("instructors.txt");
    if (!iFile) {
        perror("File error: ");
        system("pause");
    }
    if (iFile.is_open()) {
        string username, password, name;
        while(iFile >> username >> password >> name && i < 3) {
            instructors[i].setUserName(username);
            instructors[i].setPassword(password);
            instructors[i].setInstructorName(name);
            cout << "creating teacher " << i << endl;
        }
    }

} // createInstructors

/* The method to run if an instructor account is selected. */
int instructorAccount() {

    string iUser, iPass;

    cout << "Enter credentials to login, \n\tEnter username: ";
    cin >> iUser;
    cout << "\tEnter password: ";
    cin >> iPass;

    while(1) {
        for (int i = 0; i < 3; i++) {
            if (instructors[i].login(iUser, iPass)) {
                while(1) {
                    cout << "Query options,\n\t1 - view grades of a student\n\t2 - view stats" << endl;
                }
            } else {

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
                    }
                }
            }
        }
        cout << "Login as student failed" << endl;
        return 0;
    }
    return 0;
} // studentAccount

int main(int argc, char *argv[]) {

    /* Check that program was launched with correct files. */
    if (argc != 3) {
        cout << "Usage: main [instructors_file] [students_file]" << endl;
        return 1;
    } else if (strcmp(argv[1], "instructors.txt") != 0 || strcmp(argv[2], "students.txt") != 0) {
        cout << "Usage: ./main instructors.txt students.txt" << endl;
        return 1;
    }

    int userType;
    createStudents();
    createInstructors();
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
        } else if (!isdigit(userType)) {
            cout << "Invalid option. Please enter a valid option." << endl;
            break;
        } // main interface loop.
    } // while

    return 0;
} // main
