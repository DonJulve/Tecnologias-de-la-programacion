/**
 * Autor: Alejandro Benedi Andrés   Nip: 843826 
 * Autor: Javier Julve Yubero       Nip: 840710
 *            
 * Coms: En este fichero se encuentra el "Main". En el
 * se crean y se mandan a ejecutar los 3 programas test
**/

import java.util.Scanner;
import Programas.*;

public class Main {
    public static void main(String[] args){

        Scanner sc_main = new Scanner(System.in);         // Abrimos el scanner que se va usar en los 3 programas

        Sumar p1 = new Sumar(4, sc_main);               // Crea el primer programa Suma
        p1.ejecutar_programa();                           // Ejecuta Suma
        System.out.println();
        Cuenta_atras p2 = new Cuenta_atras(7, sc_main); // Crea el segundo programa Cuenta atras
        p2.ejecutar_programa();                           // Ejecuta Cuenta atras
        System.out.println();
        Factorial p3 = new Factorial(14, sc_main);     // Crea el tercer programa Factorial
        p3.ejecutar_programa();                          // Ejecuta Factorial

        sc_main.close();                                 // Cerramos scanner
    }
}
