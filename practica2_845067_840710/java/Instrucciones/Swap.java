/**
 * Autor: Alejandro Benedi Andrés   Nip: 843826 
 * Autor: Javier Julve Yubero       Nip: 840710
 *            
 * Coms: En este fichero se encuentra la implemetacion
 *       de la instruccion "Swap" en java
**/

package Instrucciones;

import java.util.Scanner;
import java.util.Stack;

/**
 * Intercambia de posicion 2 elementos de la pila 
 */
public class Swap extends Instrucciones {
    
    public Swap(String nom) {
        super(nom);
    }

    public int op(Stack<Integer> p, int pc, Scanner sc){
        int num_uno, num_dos;
        num_uno = p.peek();
        p.pop();
        num_dos = p.peek();
        p.pop();
        p.push(num_uno);
        p.push(num_dos);
        return pc + 1;
    }
}