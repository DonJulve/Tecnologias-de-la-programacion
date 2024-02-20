/**
 * Autor: Jorge Jaime Modrego   Nip: 845067 
 * Autor: Javier Julve Yubero       Nip: 840710
 *            
 * Coms: En este fichero se encuentra toda las definiciones 
 *       de los metodos de la clase padre de las "Instrucciones"
 *       De esta "super clase" saldran todas las instrucciones 
 *       de la practica
**/

package Instrucciones;

import java.util.Scanner;
import java.util.Stack;

interface operacion {
    public int op(Stack<Integer> p, int pc, Scanner sc);
}

public abstract class Instrucciones
    implements operacion  {
    protected int parametro;            // Parametro de la instruccion si tiene
    protected String nombre;            // Nombre de la instruccion
    protected boolean tiene_parametro;  // Es "True" cuando tiene la instruccion tiene parametro

    /**
     * Este constructor se usara si la instruccion tiene
     * un parametro 
     * @param num   Parametro de la instruccion
     * @param nom   Nombre de la instruccion
     */
    public Instrucciones(int num, String nom) {
        nombre = new String();
        parametro = num;
        nombre = nom;
        tiene_parametro = true;
    }

    /**
     * Este constructor se usara para todas aquellas
     * instrucciones que no tengan un parametro
     * @param nom   Nombre de la instruccion
     */
    public Instrucciones(String nom){
        nombre = new String();
        nombre = nom;
        tiene_parametro = false;
    }

    /**
     * Devuelve ul nombre de la instruccion y el parametro
     * si tiene
     * @return Lista la instruccion
     */
    public String listar(){
        if(tiene_parametro){
            return nombre + " " + parametro + "";
        }
        return nombre;
    }

    /**
     * Al ser una clase abstracta, los hijos tendran que implementar y redefinir 
     * este metedo. La instruccion devolvera el numero de la instruccion siguiente
     * que se va ejecutar.
     */
    public int op(Stack<Integer> p, int pc, Scanner sc){return 0;}

}
