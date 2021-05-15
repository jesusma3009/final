
#include "particula.h"
#include "ConjuntoParticulas.h"
#include <iostream>

using namespace std;

const float ANCHO = 800.0;
const float ALTO = 800.0;

void test1(string s) {
    cout << s << endl;
    ConjuntoParticulas cp1;
    ConjuntoParticulas cp2(10);
}

void test2(string s) {
    cout << s << endl;
    ConjuntoParticulas cp1(7);

    Particula nueva(5.0, 5.0, 0.0, 0.0, 5);
    int n = cp1.GetUtiles();
    for (int i = -1; i <= n + 1; i++)
        cp1.ReemplazaParticula(i, nueva);
}

void test3(string s) {
    cout << s << endl;
    ConjuntoParticulas cp1;

    cout << "Capacidad " << cp1.GetCapacidad() << " utiles: " << cp1.GetUtiles() << endl;

    int n = cp1.GetUtiles();
    for (int i = 0; i < n+2; i++) {
        Particula nueva;
        cp1.AgregaParticula(nueva);
    }

    cout << "Capacidad " << cp1.GetCapacidad() << " utiles: " << cp1.GetUtiles() << endl;
}

void test4(string s) {
    cout << s << endl;
    ConjuntoParticulas cp1(11);

    cout << "Capacidad " << cp1.GetCapacidad() << " utiles: " << cp1.GetUtiles() << endl;

    int n = cp1.GetUtiles();
    for (int i = 0; i < n; i++) {
        int nro = cp1.GetUtiles();
        if (nro > 0)
            cp1.BorraParticula(random() % nro);
    }
    cout << "Capacidad " << cp1.GetCapacidad() << " utiles: " << cp1.GetUtiles() << endl;
}

void test5(string s) {
    cout << s << endl;
    int N = 10;
    // creación de objetos
    //---------------------------------------------------------
    ConjuntoParticulas nube(N);
    for (int i = 0; i < 2000; i++) {
        if ((random() % 10) > 5)
            for (int j = 0; j < 7; j++) {
                Particula nueva;
                nube.AgregaParticula(nueva);
            } else {
            for (int j = 0; j < 7; j++) {
                int nro = nube.GetUtiles();
                if (nro > 0)
                    nube.BorraParticula((random() % nro));
            }
        }
        nube.Mover(ANCHO, ALTO);
        nube.Rebotar(ANCHO, ALTO);

    }

}

int main(void) {

    test1("Test 1");
    test2("Test 2");
    test3("Test 3");
    test4("Test 4");
    test5("Test 5");
    return 0;
}