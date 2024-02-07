//--------------------------------------------------------------------------------
// File: rational.h
// Author: Jorge Jaime Modrego (845067) y Javier Julve Yubero (840710)
// Date: Febrero 2024
//--------------------------------------------------------------------------------
#pragma once

#include <iostream>

// Solucion con atributos privados.

class Rational
{
private:
	// Atributos
	int num, den;
private:
	// Auxiliares

	// Funcion que calcula el maximo comun divisor de dos numeros
	static int mcd(int a, int b);

	// Funcion que reduce una fraccion
	void reduce();

public:
	// Constructores

	Rational();
	Rational(int num, int den);

	// Entrada/salida

	// Funcion que escribe una fraccion
	void write(std::ostream& os) const;

	// Funcion que lee una fraccion
	void read(std::istream& is);

	// Operaciones aritmeticas

	// Funcion que suma dos fracciones
	Rational add(const Rational& that);

	// Funcion que resta dos fracciones
	Rational sub(const Rational& that);

	// Funcion que multiplica dos fracciones
	Rational mul(const Rational& that);

	// Funcion que divide dos fracciones
	Rational div(const Rational& that);

	// Operaciones logicas

	// Funcion que devuelve true si dos fracciones son iguales
	bool equal(const Rational& that);

	// Funcion que devuelve true si una fraccion es menor que otra
	bool lesser_than(const Rational& that);

	// Funcion que compara devuelve true si una fraccion es mayor que otra
	bool greater_than(const Rational& that);
};
