#include <iostream>
#include "Particula.h"
#include <cmath>

using namespace std;
int main(){
    int ANCHO = 10;
    int ALTO = 10;
    
    Particula p(5, 5, 1, 1, 3);
    cout << "Estado 0: " << p.ToString() << endl;
    
    p.Mover(ANCHO, ALTO);
    cout << "Estado 1: " << p.ToString() << endl;
    
    p.Mover(ANCHO, ALTO);
    cout << "Estado 2: " << p.ToString() << endl;
    
    p.Mover(ANCHO, ALTO);
    cout << "Estado 3: " << p.ToString() << endl;
    
    
    float grados = 180;
    float rads = grados * (M_PI / 180.0);
    p.Rotar(5, 5, rads);
    cout << "Estado 4: " << p.ToString() << endl;
    
    
    p.SetXY(6, 5);
    p.SetDY(0);
    p.SetDX(1);
    for(int i = 0; i < 10; i++){
        p.Mover(ANCHO, ALTO);
        p.RebotaBordes(ANCHO, ALTO);
        cout << "Paso: " << i << " " << p.ToString() << endl;
    }
    
    Particula otra(1, 1, 1, 1, 2);
    
    cout << "Distancia entre:\n" << otra.ToString() << "\n" << p.ToString();
    cout << "\nEs: " << p.Distancia(otra) << " Colision " << otra.Colision(p) << endl;
    otra.Mover(ANCHO, ALTO);
    otra.Mover(ANCHO, ALTO);
    
    cout << "Distancia entre:\n" << otra.ToString() << "\n" << p.ToString();
    cout << "\nEs: " << p.Distancia(otra) << " Colision " <<  otra.Colision(p) << endl;
    
    
    
    
}
