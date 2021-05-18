all: ejemplo3
ejemplo3: ejemplo3.o Particula.o
	g++ -g -o ejemplo3 ejemplo3.o Particula.o -std=c++14 -lraylib
ejemplo3.o: ejemplo3.cpp ../particula/Particula.h
	g++ -g -c -o ejemplo3.o ejemplo3.cpp -I ../particula -std=c++14
Particula.o: ../particula/Particula.cpp ../particula/Particula.h
	g++ -g -c -o Particula.o ../particula/Particula.cpp -I ../particula -std=c++14
clean:
	echo limpiando...
	rm *.o
