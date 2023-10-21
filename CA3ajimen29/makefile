#
# Specifiy the target
all:	list

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
list:	main.o
	g++  main.o -o list.exe

# Specify how the object files should be created from source files
main.o:		main.cpp
	g++ -c main.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o *.gch list.exe

