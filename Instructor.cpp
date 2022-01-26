#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "Instructor.h"
#include "Student.h"

using namespace std;

/* A method to allow the instructor to login and access the class features.
   Given a username and password, checks if that is an instructor and their
   password, then returns True if the instructor succeeded or False if not.
*/
bool Instructor::login(string u, string p) {
    bool log;
    if (u == userName && p == password) {
        log = true;
    } else {
        log = false;
    }
    return log;

} // login

/* Retreives the instructor's full name so that the message "You are now
   logged in as ____" can be displayed.
*/
string Instructor::getInstructorName() {
    return fullName;
} // getinstructorname

string Instructor::getUserName() {
    return userName;
}

/* Given the username of a student, allows the instructor to see the grades
   of the student provided.
*/
Student Instructor::getStudent(Student students[], string username, int numStuds) {
    Student stu;
    int i;
    string user = username;
    for (i = 0; i < numStuds; i++) {
        if (students[i].getUserName() == user) {
            return students[i];
            stu = students[i];
            return stu;
        }
    }
    cout << "Student username is not valid" << endl;
    return stu;
} // getstudent

/* Retrieves the student with the lowest grade of a given type. */
void Instructor::getMinStudent(Student students[], int gradeType, int numStuds) {
    Student stu;
    int i;
    int min = 100;
    if (gradeType == 1) {
        for (i = 0; i < numStuds; i++) {
            if (students[i].getProjectGrade() < min) {
                min = students[i].getProjectGrade();
                stu = students[i];
            }
        }
        cout << min << "%\t(" << stu.getStudentName() << ")" << endl;
    } else if (gradeType == 2) {
        for (i = 0; i < numStuds; i++) {
            if (students[i].getQuizGrade() < min) {
                min = students[i].getQuizGrade();
                stu = students[i];
                }
        }
        cout << min << "%\t(" << stu.getStudentName() << ")" << endl;
    } else if (gradeType == 3) {
        for (i = 0; i < numStuds; i++) {
            if (students[i].getMidtermGrade() < min) {
                min = students[i].getMidtermGrade();
                stu = students[i];
            }
        }
        cout << min << "%\t(" << stu.getStudentName() << ")" << endl;
    } else if (gradeType == 4) {
        for (i = 0; i < numStuds; i++) {
            if (students[i].getFinalGrade() < min) {
                min = students[i].getFinalGrade();
                stu = students[i];
            }
        }
        cout << min << "%\t(" << stu.getStudentName() << ")" << endl;
    } else if (gradeType == 5) {
        for (i = 0; i < numStuds; i++) {
            if (students[i].getOverallGrade() < min) {
                min = students[i].getOverallGrade();
                stu = students[i];
            }
        }
        cout << min << "%\t(" << stu.getStudentName() << ")" << endl;
    } else {
        cout << "Invalid grade type, please enter 1 - 5." << endl;
    }

} // getminstudent

/* Retrieves the student with the highest grade of a given type. */
void Instructor::getMaxStudent(Student students[], int gradeType, int numStuds) {
    Student stu;
    int i;
    int max = 0;
    if (gradeType == 1) {
        for (i = 0; i < numStuds; i++) {
            if (students[i].getProjectGrade() > max) {
                max = students[i].getProjectGrade();
                stu = students[i];
            }
        }
        cout << max << "%\t(" << stu.getStudentName() << ")" << endl;
    } else if (gradeType == 2) {
        for (i = 0; i < numStuds; i++) {
            if (students[i].getQuizGrade() > max) {
                max = students[i].getQuizGrade();
                stu = students[i];
            }
        }
        cout << max << "%\t(" << stu.getStudentName() << ")" << endl;
    } else if (gradeType == 3) {
        for (i = 0; i < numStuds; i++) {
            if (students[i].getMidtermGrade() > max) {
                max = students[i].getMidtermGrade();
                stu = students[i];
            }
        }
        cout << max << "%\t(" << stu.getStudentName() << ")" << endl;
    } else if (gradeType == 4) {
        for (i = 0; i < numStuds; i++) {
            if (students[i].getFinalGrade() > max) {
                max = students[i].getFinalGrade();
                stu = students[i];
            }
        }
        cout << max << "%\t(" << stu.getStudentName() << ")" << endl;
    } else if (gradeType == 5) {
        for (i = 0; i < numStuds; i++) {
            if (students[i].getOverallGrade() > max) {
                max = students[i].getOverallGrade();
                stu = students[i];
            }
        }
        cout << max << "%\t(" << stu.getStudentName() << ")" << endl;
    } else {
        cout << "Invalid grade type, please enter 1 - 5." << endl;
    }
} // getmaxstudent

/* Retrieves the average grade of all students for a given grade type */
void Instructor::getAvg(Student students[], int gradeType, int numStuds) {
    Student stu;
    int i;
    double avg = 0;
    double sum = 0;

    if (gradeType == 1) {
        for (i = 0; i < numStuds; i++) {
            sum = sum + students[i].getProjectGrade();
        }
        avg = sum / numStuds;
    } else if (gradeType == 2) {
        for (i = 0; i < numStuds; i++) {
            sum = sum + students[i].getQuizGrade();
        }
        avg = sum / numStuds;
    } else if (gradeType == 3) {
        for (i = 0; i < numStuds; i++) {
            sum = sum + students[i].getMidtermGrade();
        }
        avg = sum / numStuds;
    } else if (gradeType == 4) {
        for (i = 0; i < numStuds; i++) {
            sum = sum + students[i].getFinalGrade();
        }
        avg = sum / numStuds;
    } else if (gradeType == 5) {
        for (i = 0; i < numStuds; i++) {
            sum = sum + students[i].getOverallGrade();
        }
        avg = sum / numStuds;
    } else {
        cout << "Invalid grade type, please enter 1 - 5." << endl;
    }
    cout << avg << "%" << endl;
} // getavg

/* Sets the name of the instructor that has logged in. */
void Instructor::setInstructorName(string fname, string lname) {
    fullName = fname + " " + lname;
}

void Instructor::setUserName(string uname) {
    userName = uname;
}

void Instructor::setPassword(string pass) {
    password = pass;
}
