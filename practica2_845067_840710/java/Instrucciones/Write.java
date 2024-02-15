/**
 * Autor: Alejandro Benedi Andrés   Nip: 843826 
 * Autor: Javier Julve Yubero       Nip: 840710
 *            
 * Coms: En este fichero se encuentra la implemetacion
 *       de la instruccion "Write" en java
**/

package Instrucciones;

import java.util.Scanner;
import java.util.Stack;

/**
 * Se desapila un elemento y se muestra por pantalla
 */
public class Write extends Instrucciones {

    public Write(String nom) {
        super(nom);
    }

    public int op(Stack<Integer> p, int pc, Scanner sc){
        int res = 0;
        res = p.peek();
        p.pop();
        System.out.println(res);
        return pc + 1;
    }
}