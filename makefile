#Makefile for the new and improved text-based adventure Zuul2.

Zuul2:	main.o Game.o Room.o Parser.o tinyxml2.o
	g++ -g -o Zuul2 main.o Game.o Room.o Parser.o tinyxml2.o

main.o:	main.cpp
	g++ -g -c main.cpp

Game.o:	Game.cpp Game.h
	g++ -g -c Game.cpp

Room.o: Room.cpp Room.h
	g++ -g -c Room.cpp

Parser.o:	Parser.cpp Parser.h
	g++ -g -c Parser.cpp

tinyxml2.o:	tinyxml2.cpp tinyxml2.h
	g++ -g -c tinyxml2.cpp

clean:
	/bin/rm/ -f *.o *.exe *.stackdump
