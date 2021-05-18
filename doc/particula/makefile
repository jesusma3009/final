all: testParticula
testParticula: testParticula.o Particula.o
	g++ -g -o testParticula testParticula.o Particula.o -std=c++14
testParticula.o: testParticula.cpp Particula.h
	g++ -g -c -o testParticula.o testParticula.cpp -I ./include -std=c++14
Particula.o: Particula.cpp Particula.h
	g++ -g -c -o Particula.o Particula.cpp -I ./include -std=c++14
clean:
	echo limpiando...
	rm *.o
