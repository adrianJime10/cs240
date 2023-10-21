#
# Specifiy the target
all:	Voter

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
Voter:	main.o VoterDB.o Voter.o
	g++  main.o VoterDB.o Voter.o -o Voter.exe

# Specify how the object files should be created from source files
main.o:		main.cpp
	g++ -c main.cpp

Voter.o:	Voter.cpp Voter.h VoterDB.h
	g++ -c Voter.cpp Voter.h VoterDB.h

VoterDB.o:	VoterDB.cpp VoterDB.h
	g++ -c VoterDB.cpp VoterDB.h

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o *.gch Voter.exe

