#
# Program: Assignment 4
# Programmer: Josue Ballona
# Logon ID: Z1832823
# Date Due: Feb 23
#

# Compiler Variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assignment4.exe: assignment4.o
	g++ $(CCFLAGS) -o assignment4.exe assignment4.o

# Rules to compile source code file to object code
assignment4.o: assignment4.cc assignment4.h
	g++ $(CCFLAGS) -c assignment4.cc

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment4.exe

