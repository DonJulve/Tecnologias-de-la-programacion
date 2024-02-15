/**
 * Autor: Alejandro Benedi Andrés   Nip: 843826 
 * Autor: Javier Julve Yubero       Nip: 840710
 *            
 * Coms: En este fichero se encuentra el "Main". En el
 * se crean y se mandan a ejecutar los 3 programas test
**/

#include "programas.h"
using namespace std;

int main(){

    Programas* P1 = new Sumar();        // Crea el primer programa Suma
    P1->ejecutar_programa();            // Ejecuta Suma
    cout << endl;
    Programas* P2 = new Cuenta_atras(); // Crea el segundo programa Cuenta atras
    P2->ejecutar_programa();            // Ejecuta Cuenta atras
    cout << endl;
    Programas* P3 = new Factorial();    // Crea el tercer programa Factorial
    P3->ejecutar_programa();            // Ejecuta Factorial
    
    delete P1, P2, P3;
    return 0;
}