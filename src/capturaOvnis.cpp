#include "raylib.h"
#include "Particula.h"
#include "ConjuntoParticulas.h"
#include "Pintar.h"
#include <iostream>


using namespace std;

const int screenWidth = 800;
const int screenHeight = 450;
const int TAM_JUGADOR = 15;
const int TAM_PARTICULAS = 20;
const float  DESP = 4.0;


void pintarParticula(const  Particula & p, Color c){
    Vector2 pos = {p.GetX(), p.GetY()};
    DrawCircleV(pos, p.GetRadio(), c);
}

char Direccion(){
    char dir = ' ';
        if (IsKeyDown(KEY_LEFT))
            dir = 'L';
        
        if (IsKeyDown(KEY_RIGHT))
            dir = 'R';

        return dir;
}

int main(void)
{
    // Initialization
    //---------------------------------------------------------
    

    InitWindow(screenWidth, screenHeight, "Minijuego");

    Particula bola(GetScreenWidth()/3.0f, GetScreenHeight()/2.0f , 5.0, 4.0, TAM_PARTICULAS);
 
    Particula jugador(GetScreenWidth()/2.0f, GetScreenHeight()-TAM_JUGADOR, DESP, DESP, TAM_JUGADOR);
    
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
            
            bola.Mover(screenWidth, screenHeight);
            bola.RebotaBordes(screenWidth, screenHeight);
            
        //-----------------------------------------------------
        // Draw
        //-----------------------------------------------------
        BeginDrawing();

          ClearBackground(RAYWHITE);
          pintarParticula(bola, RED);
          pintarParticula(jugador, BLACK);
           DrawText("ESC para salir", 10, 10 , 20, BLACK);                
                
            
        EndDrawing();
        //-----------------------------------------------------
    }

    // De-Initialization
    //---------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //----------------------------------------------------------

    return 0;
}
