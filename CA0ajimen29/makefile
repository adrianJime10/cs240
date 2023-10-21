#
# Specifiy the target
all:	Hello

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
Hello:	JimenezAdrian-ajimen29-Hello.o Hello_Class.o
	g++  JimenezAdrian-ajimen29-Hello.o Hello_Class.o -o Hello.exe

# Specify how the object files should be created from source files
JimenezAdrian-ajimen29-Hello.o:	JimenezAdrian-ajimen29-Hello.cpp
	g++ -c JimenezAdrian-ajimen29-Hello.cpp

Hello_Class.o:	Hello_Class.cpp
	g++ -c Hello_Class.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o Hello.exe

