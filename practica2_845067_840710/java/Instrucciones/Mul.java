/**
 * Autor: Alejandro Benedi Andrés   Nip: 843826 
 * Autor: Javier Julve Yubero       Nip: 840710
 *            
 * Coms: En este fichero se encuentra la implemetacion
 *       de la instruccion "Mul" en java
**/

package Instrucciones;

import java.util.Scanner;
import java.util.Stack;

/**
 * Desapila 2 elementos, los multiplica y el resultado
 * se vuelve a introducir en la pila
 */
public class Mul extends Instrucciones {

    public Mul(String nom) {
        super(nom);
    }

    public int op(Stack<Integer> p, int pc, Scanner sc){
        int num_uno, num_dos;
        num_uno = p.peek();
        p.pop();
        num_dos = p.peek();
        p.pop();
        p.push(num_uno * num_dos);
        return pc + 1;
    }
    
}
