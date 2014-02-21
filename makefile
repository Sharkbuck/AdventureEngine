#Makefile for the new and improved text-based adventure Zuul2.

Zuul2:	main.o Game.o Room.o Parser.o
	g++ -g -o Zuul2 main.o Game.o Room.o Parser.o

main.o:	main.cpp
	g++ -g -c main.cpp

Game.o:	Game.cpp
	g++ -g -c Game.cpp

Room.o: Room.cpp
	g++ -g -c Room.cpp

Parser.o:	Parser.cpp
	g++ -g -c Parser.cpp

clean:
	/bin/rm/ *.o *.exe *.stackdump
