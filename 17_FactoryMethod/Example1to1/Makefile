run:
	./test

all: documentcreator code main
	g++ -o test DocumentCreator.o Code.o main.o

documentcreator:
	g++ -c DocumentCreator.cpp

code:
	g++ -c Code.cpp

main:
	g++ -c main.cpp

clean:
	rm -f *.o test
