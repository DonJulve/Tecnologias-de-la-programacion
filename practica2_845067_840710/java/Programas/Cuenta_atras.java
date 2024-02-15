/**
 * Autor: Alejandro Benedi Andrés   Nip: 843826 
 * Autor: Javier Julve Yubero       Nip: 840710
 *            
 * Coms: En este fichero se encuentra toda la implementacion
 *       del programa "Cuenta atras".
**/

package Programas;

import java.util.Scanner;
import Instrucciones.*;

/**
 * Este programa pide al usuario un número ( entero y positivo ) y 
 * mostrará por pantalla una cuenta atrás desde ese número, de uno en uno hasta 
 * llegar a cero.
 */
public class Cuenta_atras extends Programas {

    public Cuenta_atras(int n, Scanner sc_main){
        super(n, sc_main);
        v[0] = new Read("Read");
        v[1] = new Dup("Dup");
        v[2] = new Write("Write");
        v[3] = new Push(-1,"Push");
        v[4] = new Add("Add");
        v[5] = new Dup("Dup");
        v[6] = new Jumpif(1,"Jumpif");
    }
}