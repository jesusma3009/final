all: bin/capturaOvnis
bin/capturaOvnis: obj/capturaOvnis.o obj/Particula.o obj/ConjuntoParticulas.o
	g++ -g -o bin/capturaOvnis obj/capturaOvnis.o obj/Particula.o obj/ConjuntoParticulas.o -std=c++14 -lraylib
bin/pruebaConjunto: obj/pruebaConjunto.o obj/Particula.o obj/ConjuntoParticulas.o
	g++ -g -o bin/pruebaConjunto obj/pruebaConjunto.o obj/Particula.o obj/ConjuntoParticulas.o -std=c++14
obj/pruebaConjunto.o: src/pruebaConjunto.cpp include/Particula.h
	g++ -g -c -o obj/pruebaConjunto.o src/pruebaConjunto.cpp -I ./include -std=c++14
obj/capturaOvnis.o: src/capturaOvnis.cpp include/Particula.h
	g++ -g -c -o obj/capturaOvnis.o src/capturaOvnis.cpp -I ./include -std=c++14
obj/Particula.o: src/Particula.cpp include/Particula.h
	g++ -g -c -o obj/Particula.o src/Particula.cpp -I ./include -std=c++14
obj/ConjuntoParticulas.o: src/ConjuntoParticulas.cpp include/ConjuntoParticulas.h
	g++ -g -c -o obj/ConjuntoParticulas.o src/ConjuntoParticulas.cpp -I ./include -std=c++14
clean:
	echo limpiando...
	rm obj/*.o
