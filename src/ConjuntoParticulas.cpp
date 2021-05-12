#include "ConjuntoParticulas.h"
#include "particula.h"
#include <iostream>
ConjuntoParticulas::ConjuntoParticulas()
{
    Iniciar(MIN_SIZE);
}
ConjuntoParticulas::ConjuntoParticulas(int tamanio)
{
    Iniciar(tamanio);
}
void ConjuntoParticulas::Iniciar(int tamanio)
{
    set = new Particula[tamanio];
    capacidad = tamanio;
    utiles = 0;
}
void ConjuntoParticulas::liberar()
{
    delete[] set;
    capacidad = 0;
    utiles = 0;
}
void ConjuntoParticulas::AgregaParticula(const Particula p)
{
    if (utiles >= capacidad) Redimensiona(capacidad + 1);
    set[++utiles] = p;
}
void ConjuntoParticulas::Redimensiona(const int capacidad_nueva)
{
    Particula *temp = new Particula[capacidad_nueva];

    for (int i {0}; i < capacidad; i++)
        temp[i] = set[i];
    liberar();
    set = temp;
    capacidad = capacidad_nueva;
    utiles = capacidad_nueva - 1;
}
void ConjuntoParticulas::BorraParticula(const int pos)
{
    for (int i {pos + 1}; i < utiles; i++)
        set[i-1] = set[i];
    utiles--;
    Redimensiona(capacidad - 1);
}
void ConjuntoParticulas::ReemplazaParticula(const Particula p, const int pos)
{
    set[pos] = p;
}
void ConjuntoParticulas::Mover(const int ancho, const int alto)
{
    for (int i {0}; i < utiles; i++)
        set[i].Mover(ancho, alto);
}
void ConjuntoParticulas::Rebotar(const int ancho, const int alto)
{
    for (int i {0}; i < utiles; i++)
        set[i].RebotaBordes(ancho, alto);
}
void ConjuntoParticulas::Mostrar()
{
    cout << "Capacidad: " << capacidad << endl;
    cout << "Utiles: " << utiles << endl;
    for (int i {0}; i < utiles; i++)
        cout << set[i].ToString() << endl;
}