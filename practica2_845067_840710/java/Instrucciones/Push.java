/**
 * Autor: Jorge Jaime Modrego   Nip: 845067 
 * Autor: Javier Julve Yubero       Nip: 840710
 *            
 * Coms: En este fichero se encuentra la implemetacion
 *       de la instruccion "Push" en java
**/

package Instrucciones;

import java.util.Scanner;
import java.util.Stack;

/*
 * Se apila el parametro de la instruccion
 */
public class Push extends Instrucciones {

    public Push(int num, String nom) {
        super(num, nom);        // Esta instruccion tiene parametro
    }
    
    public int op(Stack<Integer> p, int pc, Scanner sc){
        p.push(super.parametro);
        return pc + 1;
    }
}