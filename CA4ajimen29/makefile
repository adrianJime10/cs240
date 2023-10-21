#
# Specifiy the target
all:	list

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
list:	main.o pc.o player.o game.o tournament.o
	g++ main.o pc.o player.o game.o tournament.o -g -o list.exe

# Specify how the object files should be created from source files
main.o:		main.cpp
	g++ -c main.cpp

pc.o:	pc.cpp
	g++ -c pc.cpp

player.o: player.cpp
	g++ -c player.cpp

game.o: game.cpp
	g++ -c game.cpp

tournament.o: tournament.cpp
	g++ -c tournament.cpp
# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o *.gch list.exe
