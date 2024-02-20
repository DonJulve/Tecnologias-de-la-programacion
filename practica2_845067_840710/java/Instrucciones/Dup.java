/**
 * Autor: Jorge Jaime Modrego   Nip: 845067 
 * Autor: Javier Julve Yubero       Nip: 840710
 *            
 * Coms: En este fichero se encuentra la implemetacion
 *       de la instruccion "Dup" en java
**/

package Instrucciones;

import java.util.Scanner;
import java.util.Stack;

/**
 * Duplica el elemnto que se encuentra en 
 * la cima de pila
 */
public class Dup extends Instrucciones {

    public Dup(String nom) {
        super(nom);
    }

    public int op(Stack<Integer> p, int pc, Scanner sc){
        int valor = p.peek();
        p.pop();
        p.push(valor);
        p.push(valor);
        return pc + 1;
    }
}
