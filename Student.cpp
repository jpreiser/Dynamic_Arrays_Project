#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "Student.h"

using namespace std;

/* A method to allow the student to login and view their grades
   if they provide a correct username and password.
*/
bool Student::login(string u, string p) {
    bool log;
    if (u == userName && p == password) {
        log = true;
    } else {
        log = false;
    }
    return log;
} // login

/* A method for getting the student's name so that a welcome message
   can be displayed.
*/
string Student::getStudentName() {
    return fullName;
} // getStudentName

/* A method for returning the user name of a student being searched for by instructor. */
string Student::getUserName() {
    return userName;
} // getUserName

/* Get's the student's project grade. */
int Student::getProjectGrade() {
    return projectGrade;
} // getProjectGrade

/* Get's the student's quiz grade. */
int Student::getQuizGrade() {
    return quizGrade;
} // gQG

/* Get's the student's midterm grade. */
int Student::getMidtermGrade() {
    return midtermGrade;
} // getMidterm

/* Get's the student's final grade. */
int Student::getFinalGrade() {
    return finalGrade;
} // getFinal

/* Get's the student's overall, weighted grade */
double Student::getOverallGrade() {
    double overall;
    overall = (projectGrade * 0.3) + (0.1 * quizGrade) + (0.2 * midtermGrade) +
        (0.4 * finalGrade);
    return overall;
} // getOverall

/* Sets the student's username */
void Student::setUserName(string user) {
    userName = user;
        } //

/* Sets the student's password*/
void Student::setPassword(string pass) {
    password = pass;
} //

/* Sets the student's name based on the given login credentials. */
void Student::setStudentName(string fName, string lastName) {
    fullName = fName + " " + lastName;
} // setname

/* Sets the student's project grade based on the given login credentials. */
void Student::setProjectGrade(int grade) {
    projectGrade = grade;
} // setprojectgrade

/* Sets the student's quiz grade based on the given login credentials. */
void Student::setQuizGrade(int grade) {
    quizGrade = grade;
} // setquizgrade

/* Sets the student's midterm grade based on the given login credentials. */
void Student::setMidtermGrade(int grade) {
    midtermGrade = grade;
} // setmidtermgrade

/* Sets the student's final grade based on the given login credentials. */
void Student::setFinalGrade(int grade) {
    finalGrade = grade;
} // setfinalgrade

bool Student::isSet() {
    if (userName == "") {
        set = false;
    } else {
        set = true;
    }
    return set;
}
