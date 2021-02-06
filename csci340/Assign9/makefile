#
# Program: Assignment 9
# Programmer: Josue Ballona
# Logon ID: Z1832823
# Date Due:May 4
#

# Compiler Variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assignment9.exe: assignment9.o
	g++ $(CCFLAGS) -o assignment9.exe assignment9.o

# Rules to compile source code file to object code
assignment9.o: assignment9.cc assignment9.h
	g++ $(CCFLAGS) -c assignment9.cc

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment9.exe

