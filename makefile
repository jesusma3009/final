all: bin/main
bin/main: obj/main.o obj/particula.o obj/ConjuntoParticulas.o
	g++ -g -o bin/main obj/main.o obj/particula.o obj/ConjuntoParticulas.o
obj/main.o: src/main.cpp include/particula.h
	g++ -g -c -o obj/main.o src/main.cpp -I ./include
obj/particula.o: src/particula.cpp include/particula.h
	g++ -g -c -o obj/particula.o src/particula.cpp -I ./include
obj/ConjuntoParticulas.o: src/ConjuntoParticulas.cpp include/ConjuntoParticulas.h
	g++ -g -c -o obj/ConjuntoParticulas.o src/ConjuntoParticulas.cpp -I ./include
clean:
	echo limpiando...
	rm obj/*.o
