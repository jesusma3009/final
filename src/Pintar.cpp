#include "Pintar.h"
void pintarParticula(const  Particula & p, Color c)
{
    Vector2 pos = {p.GetX(), p.GetY()};
    DrawCircleV(pos, p.GetRadio(), c);
}

void pintarConjunto(const ConjuntoParticulas &cp, Color c)
{
    int N = cp.GetUtiles();
    for (int i = 0; i < N; i++)
        pintarParticula(cp.ObtieneParticula(i), c);
}