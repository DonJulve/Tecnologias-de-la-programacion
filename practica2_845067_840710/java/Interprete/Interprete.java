package Interprete;

import java.util.Stack;
import java.util.Scanner;

import Instrucciones.*;

public class Interprete {
    protected Stack<Integer> p;        
    protected int pc;               // El pc (Program counter)  es el que va indicar que instruccion ejecutar
    protected int num_instrucciones;    // Numero de instrucciones que contiene <v>
    protected Scanner sc;

    public Interprete(int n, Scanner sc_main){
        p = new Stack<Integer>();
        pc = 0;
        num_instrucciones = n;
        sc = sc_main;                   // El scanner es controlado desde el main, es decir se crea y se cierra en el main
    }

    /**
     * Este metodo es el encargado de ejecutar los programas.
     * Inicialmente mostrara las instrucciones del programa.
     * Posteriormente mostrara la propia ejecucion del programa
     */
    public void ejecutar_programa(Instrucciones[] v ){
        System.out.println("Programa: ");
        for (int i = 0; i < num_instrucciones; i++){
            System.out.println(i + "   " + v[i].listar());
        }

        System.out.println("\nEjecucion: ");
        while (pc < num_instrucciones){
            //System.out.println(pc+"");
            pc = v[pc].op(p, pc, sc);       // La instruccion devuelve el pc de la proxima instruccion a ejecutr
           
        } 
    }
}
