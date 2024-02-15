/**
 * Autor: Alejandro Benedi Andrés   Nip: 843826 
 * Autor: Javier Julve Yubero       Nip: 840710
 *            
 * Coms: En este fichero se encuentra toda la implementacion
 *       del programa "Sumar".
**/

package Programas;

import java.util.Scanner;
import Instrucciones.*;

/**
 * Este programa pide al usario 2 numeros enteros y mostrará por pantalla
 * la suma de los 2 numeros introducidos
 */
public class Sumar extends Programas {

    public Sumar(int n, Scanner sc_main){
        super(n, sc_main);
        super.v[0] = new Read ("Read");
        super.v[1] = new Read ("Read");
        super.v[2] = new Add ("Add");
        super.v[3] = new Write ("Write");
    }
}