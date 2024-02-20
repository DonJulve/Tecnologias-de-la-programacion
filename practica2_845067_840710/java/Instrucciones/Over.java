/**
 * Autor: Jorge Jaime Modrego   Nip: 845067 
 * Autor: Javier Julve Yubero       Nip: 840710
 *            
 * Coms: En este fichero se encuentra la implemetacion
 *       de la instruccion "Over" en java
**/

package Instrucciones;

import java.util.Scanner;
import java.util.Stack;

/**
 * Copia el elemento que esta tran la cima de pila
 */
public class Over extends Instrucciones {
    
    public Over(String nom) {
        super(nom);
    }

    public int op(Stack<Integer> p, int pc, Scanner sc){
        int num1 = p.peek();
        p.pop();
        int num2 = p.peek();
        p.push(num1);
        p.push(num2);
        return pc + 1;
    }
}