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
	int num;
	int den;
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

	// Operadores aritmeticos

	// Funcion que suma dos fracciones
	Rational add(const Rational& that) const;

	// Funcion que resta dos fracciones
	Rational sub(const Rational& that) const;

	// Funcion que multiplica dos fracciones
	Rational mul(const Rational& that);

	// Funcion que divide dos fracciones
	Rational div(const Rational& that);

	// Operaciones logicas

	// Funcion que devuelve true si dos fracciones son iguales
	bool equal(const Rational& that) const;

	// Funcion que devuelve true si una fraccion es menor que otra
	bool lesser_than(const Rational& that) const;

	// Funcion que devuelve true si una fraccion es mayor que otra
	bool greater_than(const Rational& that) const;

	// Operadores aritmeticos

	// Operador suma
	Rational operator+(const Rational& that) const;
	
	// Operador resta
	Rational operator-(const Rational& that) const;

	// Operador multiplicacion
	friend Rational operator*(const Rational& that, const Rational& r);

	// Operador division
	friend Rational operator/(const Rational& that, const Rational& r);

	// Operadores logicos

	// Operador igualdad
	bool operator==(const Rational& that) const;

	// Operador menor que
	bool operator<(const Rational& that) const;

	// Operador mayor que
	bool operator>(const Rational& that) const;

	// Friends, en su caso

	// Operador de flujo de entrada
	friend std::ostream& operator<<(std::ostream& os, const Rational& r);

	// Operador de flujo de salida
	friend std::istream& operator>>(std::istream& is, Rational& r);
};

// Operadores aritmeticos

// Operador multiplicacion
Rational operator*(const Rational& that, const Rational& r);

// Operador division
Rational operator/(const Rational& that, const Rational& r);

// Entrada/salida

// Operador de entrada
std::ostream& operator<<(std::ostream& os, const Rational& r);

// Operador de flujo de salida
std::istream& operator>>(std::istream& is, Rational& r);
