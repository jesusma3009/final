all: bin/main
bin/main: obj/main.o obj/Particula.o obj/ConjuntoParticulas.o
	g++ -g -o bin/main obj/main.o obj/Particula.o obj/ConjuntoParticulas.o -std=c++14
obj/main.o: src/main.cpp include/Particula.h
	g++ -g -c -o obj/main.o src/main.cpp -I ./include -std=c++14
obj/Particula.o: src/Particula.cpp include/Particula.h
	g++ -g -c -o obj/Particula.o src/Particula.cpp -I ./include -std=c++14
obj/ConjuntoParticulas.o: src/ConjuntoParticulas.cpp include/ConjuntoParticulas.h
	g++ -g -c -o obj/ConjuntoParticulas.o src/ConjuntoParticulas.cpp -I ./include -std=c++14
clean:
	echo limpiando...
	rm obj/*.o
