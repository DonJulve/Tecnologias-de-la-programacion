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

	static int mcd(int a, int b);
	void reduce();

public:
	// Constructores

	Rational();
	Rational(int num, int den);

	// Entrada/salida

	void write(std::ostream& os) const;
	void read(std::istream& is);

	// Operaciones aritmeticas

	Rational add(const Rational& that);
	Rational sub(const Rational& that);
	Rational mul(const Rational& that);
	Rational div(const Rational& that);

	// Operaciones logicas

	bool equal(const Rational& that);
	bool lesser_than(const Rational& that);
	bool greater_than(const Rational& that);
};
