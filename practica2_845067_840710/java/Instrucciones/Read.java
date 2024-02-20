/**
 * Autor: Jorge Jaime Modrego   Nip: 845067 
 * Autor: Javier Julve Yubero       Nip: 840710
 *            
 * Coms: En este fichero se encuentra la implemetacion
 *       de la instruccion "Read" en java
**/

package Instrucciones;

import java.util.Scanner;
import java.util.Stack;

/**
 * Se pide al usuario un numero y este es 
 * introducido en la pila
 */
public class Read extends Instrucciones {
    
    public Read(String nom) {
        super(nom);
    }

    public int op(Stack<Integer> p, int pc, Scanner sc) {
        System.out.print("? ");
        int num;
        num = sc.nextInt();
        p.push(num);
        return pc + 1;
        
    }
}
