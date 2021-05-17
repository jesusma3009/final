all: bin/main
bin/main: obj/main.o obj/Particula.o obj/ConjuntoParticulas.o
	g++ -g -o bin/main obj/main.o obj/Particula.o obj/ConjuntoParticulas.o
obj/main.o: src/main.cpp include/Particula.h
	g++ -g -c -o obj/main.o src/main.cpp -I ./include
obj/Particula.o: src/Particula.cpp include/Particula.h
	g++ -g -c -o obj/Particula.o src/Particula.cpp -I ./include
obj/ConjuntoParticulas.o: src/ConjuntoParticulas.cpp include/ConjuntoParticulas.h
	g++ -g -c -o obj/ConjuntoParticulas.o src/ConjuntoParticulas.cpp -I ./include
clean:
	echo limpiando...
	rm obj/*.o
