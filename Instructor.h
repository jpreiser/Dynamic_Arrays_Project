#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "Student.h"

using namespace std;

class Instructor {
public:
    /* A method to allow the instructor to login and access the class features.
      Given a username and password, checks if that is an instructor and their
      password, then returns True if the instructor succeeded or False if not.
    */
    bool login(string username, string password);

    /* Retreives the instructor's full name so that the message "You are now
       logged in as ____" can be displayed.
     */
    string getInstructorName();

    /* A method for retrieving the username of the instructor logged in. */
    string getUserName();

    /* Given the username of a student, allows the instructor to see the grades
       of the student provided.
     */
    Student getStudent(Student students[], string username);

    /* Retrieves the student with the lowest grade of a given type. */
    void getMinStudent(Student students[], int gradeType);

    /* Retrieves the student with the highest grade of a given type. */
    void getMaxStudent(Student students[], int gradeType);

    /* Retrieves the average grade of all students for a given grade type */
    void getAvg(Student students[], int gradeType);

    /* Sets the name of the instructor that has logged in. */
    void setInstructorName(string fName, string lName);

    /* Sets the username of the instructor created. */
    void setUserName(string uname);

    /* Sets the password of the instructor created. */
    void setPassword(string pass);

private:
    string fullName;
    string userName;
    string password;
}; // instuctor class

#endif
