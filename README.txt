Jacob Reiser
810 687 011
Data Structures Assignment 1

To compile the code, type 'make' into the command line.

To run, type './make instructors.txt students.txt' into the command line.

To clean the directory, type 'make clean' into the directory.

Currently ./main runs on the supplied instructors.txt and students.txt files. For a different
set of students and instructors, either alter the provided files or delete and replace
them with files of the same name.

A really interesting project. The first time I've worked this extensively with classes as
a data structure and I really enjoyed it!. The program starts in main, checks that the
program was initialized in the above format and then checks the files for the number of
lines to determine the number of students and instructures to be read. These values are then
used to create dynamic arrays that are then initialized using their own methods. The main
loop of the program then begins, asking if the user would like to sign in as an Instructor
or as a student. Depending on which is selected, a method for either the Instructor or Student
loop is run, respectively. These methods contain the loops that retreive the desired data once
login credentials are supplied.
