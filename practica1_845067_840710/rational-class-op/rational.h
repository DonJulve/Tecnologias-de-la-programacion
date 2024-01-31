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

	static int mcd(int a, int b);
	void reduce();

public:
	// Constructores

	Rational();
	Rational(int num, int den);

	// Entrada/salida

	void write(std::ostream& os) const;
	void read(std::istream& is);

	// Operadores aritmeticos

	Rational add(const Rational& that) const;
	Rational sub(const Rational& that) const;
	Rational mul(const Rational& that);
	Rational div(const Rational& that);

	bool equal(const Rational& that) const;
	bool lesser_than(const Rational& that) const;
	bool greater_than(const Rational& that) const;

	Rational operator+(const Rational& that) const;
	Rational operator-(const Rational& that) const;
	friend Rational operator*(const Rational& that, const Rational& r);
	friend Rational operator/(const Rational& that, const Rational& r);

	// Operadores logicos

	bool operator==(const Rational& that) const;
	bool operator<(const Rational& that) const;
	bool operator>(const Rational& that) const;

	// Friends, en su caso
	friend std::ostream& operator<<(std::ostream& os, const Rational& r);
	friend std::istream& operator>>(std::istream& is, Rational& r);
};

// Operadores aritmeticos

Rational operator*(const Rational& that, const Rational& r);
Rational operator/(const Rational& that, const Rational& r);

// Entrada/salida

std::ostream& operator<<(std::ostream& os, const Rational& r);
std::istream& operator>>(std::istream& is, Rational& r);
