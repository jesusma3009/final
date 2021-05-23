#ifndef _PINTAR_
#define _PINTAR_
#include "ConjuntoParticulas.h"
#include "Particula.h"
#include "raylib.h"
void pintarParticula(const  Particula & p, Color c);

void pintarConjunto(const ConjuntoParticulas &cp, Color c);
#endif