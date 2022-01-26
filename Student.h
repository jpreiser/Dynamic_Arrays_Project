#ifndef STUDENT_H
#define  STUDENT_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

class Student {
public:

    /* A method to allow the student to login and view their grades
       if they provide a correct username and password.
     */
    bool login(string username, string password);

    /* A method for getting the student's name so that a welcome message
       can be displayed.
     */
    string getStudentName();

    /* A method for retrieving the username of a student */
    string getUserName();

    /* Get's the student's project grade. */
    int getProjectGrade();

    /* Get's the student's quiz grade. */
    int getQuizGrade();

    /* Get's the student's midterm grade. */
    int getMidtermGrade();

    /* Get's the student's final grade. */
    int getFinalGrade();

    /* Get's the student's overall, weighted grade */
    double getOverallGrade();

    /* Sets the student's name based on the given login credentials. */
    void setStudentName(string firstName, string lastName);

    /* Sets the student's project grade based on the given login credentials. */
    void setProjectGrade(int grade);

    /* Sets the student's quiz grade based on the given login credentials. */
    void setQuizGrade(int grade);

    /* Sets the student's midterm grade based on the given login credentials. */
    void setMidtermGrade(int grade);

    /* Sets the student's final grade based on the given login credentials. */
    void setFinalGrade(int grade);

    void setUserName(string user);

    void setPassword(string pass);

    bool isSet();
private:

    string fullName;

    string userName;

    string password;

    int projectGrade;

    int quizGrade;

    int midtermGrade;

    int finalGrade;

    bool set;
};

#endif
