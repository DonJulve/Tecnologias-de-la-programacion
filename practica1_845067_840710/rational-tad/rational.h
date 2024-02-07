//--------------------------------------------------------------------------------
// File: rational.h
// Author: Jorge Jaime Modrego (845067) y Javier Julve Yubero (840710)
// Date: Febrero 2024
//--------------------------------------------------------------------------------
#pragma once

#include <iostream>

// Solucion con atributos privados.

struct Rational
{
private:
   // Atributos, a definir
   int num;
   int den;
   // Declaraciones de friends, en su caso...

   // Modifica el numerador de un numero racional
   friend void setNum(Rational& r, int num);

   // Modifica el denominador de un numero racional
   friend void setDen(Rational& r, int den);

   // Devuelve el numerador de un numero racional
   friend int getNum(const Rational& r);

   // Devuelve el denominador de un numero racional
   friend int getDen(const Rational& r);

};

//Inicializadores

// Inicializa un numero racional a 0/1
void init(Rational& r);

// Inicializa un numero racional a num/den
void init(Rational& r,int num, int den);

// Entrada/salida

// Escribe un numero racional en un flujo de salida
void write(std::ostream& os, const Rational& r);

// Lee un numero racional de un flujo de entrada
void read(std::istream& is,Rational& r);

// Operaciones aritmeticas

// Suma dos numeros racionales
Rational add(const Rational& r1, const Rational& r2);

// Resta dos numeros racionales
Rational sub(const Rational& r1, const Rational& r2);

// Multiplica dos numeros racionales
Rational mul(const Rational& r1, const Rational& r2);

// Divide dos numeros racionales
Rational div(const Rational& r1, const Rational& r2);

// Operaciones logicas

// Comprueba si dos numeros racionales son iguales
bool equal(const Rational& r1, const Rational& r2);

// Comprueba si un numero racional es menor que otro
bool lesser_than(const Rational& r1, const Rational& r2);

// Comprueba si un numero racional es mayor que otro
bool greater_than(const Rational& r1, const Rational& r2);

