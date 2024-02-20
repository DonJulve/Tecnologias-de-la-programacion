/**
 * Autor: Jorge Jaime Modrego   Nip: 845067 
 * Autor: Javier Julve Yubero       Nip: 840710
 *            
 * Coms: En este fichero se encuentra toda la implementacion
 *       del programa "Factorial".
**/

package Programas;

import java.util.Scanner;
import Instrucciones.*;

/**
 * Este programa pide al usuario un numero entero y mostrara en pantalla el 
 * factorial del numero introducido.
 */
public class Factorial extends Programas {

    public Factorial(int n, Scanner sc_main){
        super(n, sc_main);
        v[0] = new Push(1,"Push");
        v[1] = new Read("Read");
        v[2] = new Swap("Swap");
        v[3] = new Over("Over");
        v[4] = new Mul("Mul");
        v[5] = new Swap("Swap");
        v[6] = new Push(-1,"Push");
        v[7] = new Add("Add");
        v[8] = new Dup("Dup");
        v[9] = new Push(-2,"Push");
        v[10] = new Add("Add");
        v[11] = new Jumpif(2,"Jumpif");
        v[12] = new Swap("Swap");
        v[13] = new Write("Write");
    }
}