/**
 * Autor: Jorge Jaime Modrego   Nip: 845067 
 * Autor: Javier Julve Yubero       Nip: 840710
 *            
 * Coms: En este fichero se encuentra la definicion e 
 *       implementacion de la clase padre "Programas"
 *       De esta "super clase" saldran los 3 programas
 *       de test: "Factorial", " Cuenta atras", "Suma"
**/

package Programas;

import Instrucciones.*;
import Interprete.Interprete;

import java.util.Scanner;

public class Programas{
    protected Instrucciones[] v;          // Vector que contiene las instrucciones
    protected int num_instrucciones;    // Numero de instrucciones que contiene <v>
    protected Scanner sc;              

    /**
     * @param n Representa el numero de instrucciones del programa
     * @param sc_main Se introduce el <scanner> desde el "Main"
     */
    public Programas(int n, Scanner sc_main){
        num_instrucciones = n;
        v = new Instrucciones[n];    
        sc = sc_main;           // El scanner es controlado desde el main, es decir se crea y se cierra en el main
    }

    /**
     * Este metodo es el encargado de llamar al interprete pare ejecutar 
     * el programa de test
     */
    public void ejecutar_programa(){
        Interprete vbox = new Interprete(num_instrucciones, sc);
        vbox.ejecutar_programa(v);
    }

};

