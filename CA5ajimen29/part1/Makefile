#
# Specifiy the target
all:	flight

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
flight:	main.o
	g++ main.o -g -o flight.exe

# Specify how the object files should be created from source files
main.o:	main.cpp
	g++ -c main.cpp

#time.o: time.cpp
#	g++ -c time.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o *.gch flight.exe
