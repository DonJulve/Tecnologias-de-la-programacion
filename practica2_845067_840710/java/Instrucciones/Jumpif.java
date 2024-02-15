/**
 * Autor: Alejandro Benedi Andrés   Nip: 843826 
 * Autor: Javier Julve Yubero       Nip: 840710
 *            
 * Coms: En este fichero se encuentra la implemetacion
 *       de la instruccion "Jumpif" en java
**/

package Instrucciones;

import java.util.Scanner;
import java.util.Stack;

/**
 * Si el numero que se encuentra en la cima es mayor
 * que 0, se salta a la instruccion que indique el parametro
 * de la instruccion
 */
public class Jumpif extends Instrucciones {
    public Jumpif(int num, String nom) {
        super(num, nom);        // Esta instruccion tiene parametro
    }

    public int op(Stack<Integer> p, int pc, Scanner sc){
        int num = p.peek();
        p.pop();
        if (num >= 0){
            return super.parametro;
        }
        else{
            return pc + 1;
        }

    }
}