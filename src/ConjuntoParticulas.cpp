#include "ConjuntoParticulas.h"
ConjuntoParticulas::ConjuntoParticulas()
{
    Iniciar(0);
}
ConjuntoParticulas::ConjuntoParticulas(int tamanio)
{
    Iniciar(tamanio);
}
void ConjuntoParticulas::Iniciar(int tamanio)
{
    utiles = tamanio;
    set = new Particula[tamanio];
    capacidad = tamanio;
}
void ConjuntoParticulas::liberar()
{
    delete[] set;
    capacidad = 0;
    utiles = 0;
}
void ConjuntoParticulas::AgregaParticula(const Particula p)
{
    if (utiles >= capacidad) Redimensiona(true);
    set[utiles++] = p;
}
void ConjuntoParticulas::Redimensiona(bool agrandar)
{
    int capacidad_nueva;
    if (agrandar)
    {
        capacidad_nueva = TAM_BLOQUE + capacidad;
    }
    else if (!agrandar && capacidad - utiles > TAM_BLOQUE)
    {
        capacidad_nueva = capacidad - TAM_BLOQUE;
    }
    else return;
    int util_ant = utiles;
    Particula *temp_set;
    temp_set = new Particula[capacidad_nueva];
    for (int i =0; i < utiles; i++)
        temp_set[i] = set[i];
    delete[] set;
    set = temp_set;
    capacidad = capacidad_nueva;
    utiles = util_ant;
}
void ConjuntoParticulas::BorraParticula(const int pos)
{
    for (int i {pos + 1}; i < utiles; i++)
        set[i-1] = set[i];
    utiles--;
    Redimensiona(false);
}
void ConjuntoParticulas::ReemplazaParticula(const int pos, const Particula p)
{
    if (pos > 0 && pos < utiles) set[pos] = p;
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
int ConjuntoParticulas::GetCapacidad()
{
    return capacidad;
}
int ConjuntoParticulas::GetUtiles()
{
    return utiles;
}