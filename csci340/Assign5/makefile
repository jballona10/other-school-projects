#
# Program: Assignment 5
# Programmer: Josue Ballona
# Logon ID: Z1832823
# Date Due: March 2
#

# Compiler Variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assignment5.exe: assignment5.o
	g++ $(CCFLAGS) -o assignment5.exe assignment5.o

# Rules to compile source code file to object code
assignment5.o: assignment5.cc assignment5.h
	g++ $(CCFLAGS) -c assignment5.cc

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment5.exe

