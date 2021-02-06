#
# Program: Assignment 6
# Programmer: Josue Ballona
# Logon ID: Z1832823
# Date Due: March 28
#

# Compiler Variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assignment6.exe: assignment6.o assignment5.o
	g++ $(CCFLAGS) -o assignment6.exe assignment6.o assignment5.o

# Rules to compile source code file to object code
assignment5.o: assignment5.cc assignment5.h 
	g++ $(CCFLAGS) -c assignment5.cc 

assignment6.o:  assignment6.h assignment6.cc assignment6main.cc 
	g++ $(CCFLAGS) -c  assignment6main.cc assignment6.cc 


# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment6.exe

