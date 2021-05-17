#ifndef _CONJUNTOPARTICULA_
#define _CONJUNTOPARTICULA_
#include "Particula.h"
#include <iostream>
const int MIN_SIZE {5};
using std::cout;
using std::endl;
class ConjuntoParticulas
{
    private:
        Particula *set;
        Particula *temp_set;
        int capacidad;
        int utiles;
        void Redimensiona(int capacidad_nueva);
        void Iniciar(int tamanio);
    public:
        ConjuntoParticulas(int tamanio);
        ConjuntoParticulas();
        void liberar();
        int GetCapacidad();
        int GetUtiles();
        void AgregaParticula(const Particula p);
        void BorraParticula(const int pos);
        Particula ObtieneParticula(int pos) const { return set[pos]; };
        void ReemplazaParticula (const int pos, const Particula p);
        void Mover(const int ancho, const int alto);
        void Rebotar(const int ancho, const int alto);
        void Mostrar();
};
#endif