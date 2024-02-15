/**
 * Autor: Alejandro Benedi Andrés   Nip: 843826 
 * Autor: Javier Julve Yubero       Nip: 840710
 *            
 * Coms: En este fichero se encuentra la implemetacion
 *       de la instruccion "Add" en java
**/

package Instrucciones;

import java.util.Scanner;
import java.util.Stack;

/**
 * Se desapilan 2 elementos, se calcula la suma y el resultado 
 * de esta se vuelve a apilar.
 */
public class Add extends Instrucciones {

    public Add(String nom) {
        super(nom);
    }
    
    
    public int op(Stack<Integer> p, int pc, Scanner sc){
        int num_uno, num_dos;
        num_uno = p.peek();
        p.pop();
        num_dos = p.peek();
        p.pop();
        p.push(num_dos + num_uno);
        return pc + 1;
    }
    
}