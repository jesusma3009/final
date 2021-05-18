#ifndef _CONJUNTOPARTICULA_
#define _CONJUNTOPARTICULA_
#include "Particula.h"
#include <iostream>
const int MIN_SIZE = 5;
const int TAM_BLOQUE = 3;
using std::cout;
using std::endl;
class ConjuntoParticulas
{
    private:
        Particula *set;
        int capacidad;
        int utiles;
        void Redimensiona(bool agrandar);
        void Iniciar(int tamanio);
    public:
        ConjuntoParticulas(int tamanio = 0);
        void liberar();
        int GetCapacidad() const;
        int GetUtiles() const;
        void AgregaParticula(const Particula p);
        void BorraParticula(const int pos);
        Particula ObtieneParticula(int pos) const { return set[pos]; };
        void ReemplazaParticula (const int pos, const Particula p);
        void Mover(const int ancho, const int alto);
        void Rebotar(const int ancho, const int alto);
        void Mostrar();
};
#endif