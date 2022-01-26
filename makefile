#pragma once

CC = g++
FLAGS = -Wall -pedantic-errors

main: main.o Student.o Instructor.o
	$(CC) $(FLAGS) -o main main.o Student.o Instructor.o

main.o: main.cpp Student.h Instructor.h
	$(CC) $(FLAGS) -c main.cpp

Instructor.o: Instructor.cpp Instructor.h Student.h
	$(CC) $(FLAGS) -c Instructor.cpp

Student.o: Student.cpp Student.h
	$(CC) $(FLAGS) -c Student.cpp

run: compile
	./main

clean:
	rm -f *.o *.gch main
