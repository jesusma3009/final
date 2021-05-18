#include "raylib.h"
#include "Particula.h"
#include "ConjuntoParticulas.h"
#include "Pintar.h"
#include <cmath>
#include <iostream>


using namespace std;

const int screenWidth = 800;
const int screenHeight = 450;
const int TAM_JUGADOR = 15;
const int TAM_PARTICULAS = 10;
const float  DESP = 5.0;
bool haterminado = false;


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

char Direccion(){
    char dir = ' ';
        if (IsKeyDown(KEY_LEFT))
            dir = 'L';
        
        if (IsKeyDown(KEY_RIGHT))
            dir = 'R';

        return dir;
}

void IniciarParticulas(ConjuntoParticulas &bolas, int N)
{
    for (int i = 0; i < N; i++)
    {
        Particula p(rand() % GetScreenWidth(), rand() % GetScreenHeight()/2.0f , 5.0 * pow(-1,rand()%2), 4.0 * pow(-1,rand()%2), TAM_PARTICULAS);
        bolas.AgregaParticula(p);
    }
}

void DetectarColision(Particula &jugador, ConjuntoParticulas &cp)
{
    int N = cp.GetUtiles();
    for (int i = 0; i < N; i++)
        if (jugador.Colision(cp.ObtieneParticula(i)))
            cp.BorraParticula(i);
    if (cp.GetUtiles() == 0) haterminado = true;
}

int main(void)
{
    // Initialization
    //---------------------------------------------------------
    unsigned t0, t1;
    t0 = time(0);
    int total_time;
    const int N = 10;   // Cantidad de bolas
    InitWindow(screenWidth, screenHeight, "Minijuego");
    ConjuntoParticulas bolas;
    IniciarParticulas(bolas, N);
 
    Particula jugador(GetScreenWidth()/2.0f, GetScreenHeight()-TAM_JUGADOR, DESP, 0, TAM_JUGADOR);
    
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //----------------------------------------------------------

    char dir;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //-----------------------------------------------------
            dir = Direccion();
            
            jugador.MoverGrid(dir, screenWidth, screenHeight);
            
            bolas.Mover(screenWidth, screenHeight);
            bolas.Rebotar(screenWidth, screenHeight);
            DetectarColision(jugador, bolas);
            if (!haterminado)
            {
                t1 = time(0);
                total_time = t1-t0;
            }
            
        //-----------------------------------------------------
        // Draw
        //-----------------------------------------------------
        BeginDrawing();

        DrawText("ESC para salir", 10, 10 , 20, BLACK);
        ClearBackground(RAYWHITE);
        if (!haterminado)
        {
            pintarConjunto(bolas, RED);
            pintarParticula(jugador, BLACK);
            string infoParticulas = "";
            infoParticulas = "Particulas-> " + to_string(bolas.GetUtiles()) + " Cap: " + to_string(bolas.GetCapacidad()) + "    TIEMPO: " + to_string(total_time);
            const char *cstr = infoParticulas.c_str();
            DrawText(cstr, 10, 40 , 20, BLACK);
        }
        else
        {
            string infoEndGame = "Final de la partida\nTiempo total: " + to_string(total_time);
            const char *cstr = infoEndGame.c_str();
            DrawText(cstr, GetScreenWidth()/10.0f, GetScreenHeight()/4.0f, 50, BLACK);
        }

                
            
        EndDrawing();
        //-----------------------------------------------------
    }

    // De-Initialization
    //---------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //----------------------------------------------------------

    return 0;
}