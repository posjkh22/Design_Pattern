run:
	./test

all: documentcreator code main
	g++ -o test DocumentCreator.o Code.o main.o

documentcreator:
	g++ -std=c++11 -c DocumentCreator.cpp

code:
	g++ -std=c++11 -c Code.cpp

main:
	g++ -std=c++11 -c main.cpp

clean:
	rm -f *.o test
