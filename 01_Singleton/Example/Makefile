
run:
	./test

all: main speaker music
	g++ -o test main.o Speaker.o Music.o

main:
	g++ -std=c++11 -c main.cpp

speaker:
	g++ -std=c++11 -c Speaker.cpp

music:
	g++ -std=c++11 -c Music.cpp
