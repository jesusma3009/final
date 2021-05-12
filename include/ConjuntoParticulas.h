#ifndef _CONJUNTOPARTICULA_
#define _CONJUNTOPARTICULA_
#include "particula.h"
#include <iostream>
const int MIN_SIZE {5};
using std::cout;
using std::endl;
class ConjuntoParticulas
{
    private:
        Particula *set;
        int capacidad;
        int utiles;
        void Redimensiona(const int capacidad_nueva);
        void Iniciar(int tamanio);
    public:
        ConjuntoParticulas(int tamanio);
        ConjuntoParticulas();
        void liberar();
        int GetCardinal() const { return capacidad; };
        int GetUtiles() const { return utiles; };
        void AgregaParticula(const Particula p);
        void BorraParticula(const int pos);
        Particula ObtieneParticula(int pos) const { return set[pos]; };
        void ReemplazaParticula (const Particula p, const int pos);
        void Mover(const int ancho, const int alto);
        void Rebotar(const int ancho, const int alto);
        void Mostrar();
};
#endif