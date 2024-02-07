//--------------------------------------------------------------------------------
// File: rational.cc
// Author: Jorge Jaime Modrego (845067) y Javier Julve Yubero (840710)
// Date: Febrero 2024
//--------------------------------------------------------------------------------
#include "rational.h"

// Auxiliares

//Funcion que devuelve el maximo comun divisor de dos numeros
int Rational::mcd(int a, int b)
{
	return ( b == 0 ? a : mcd(b,a%b));
}

// Funcion que reduce una fraccion
void Rational::reduce()
{
	int m = mcd(this->num, this->den);
	while (m != 1)
	{
		this->num /= m;
		this->den /= m;
		m = mcd(this->num, this->den);
	}
	
}

// Constructores

Rational::Rational() : num(0), den(1) {}

Rational::Rational(int num, int den) : num(num), den(den)
{
	this->reduce();
}

// Entrada/salida

// Funcion que escribe una fraccion
void Rational::write(std::ostream& os) const
{
	os << this->num << "/" << this->den;
}

// Funcion que lee una fraccion
void Rational::read(std::istream& is)
{
	char c;
	is >> this->num >> c >> this->den;
	this->reduce();
}

// Operaciones aritmeticas

// Funcion que suma dos fracciones
Rational Rational::add(const Rational& that)
{
	return Rational(this->num * that.den + that.num * this->den, this->den * that.den);
}

// Funcion que resta dos fracciones
Rational Rational::sub(const Rational& that)
{
	return Rational(this->num * that.den - that.num * this->den, this->den * that.den);
}

// Funcion que multiplica dos fracciones
Rational Rational::mul(const Rational& that)
{
	return Rational(this->num * that.num, this->den * that.den);
}

// Funcion que divide dos fracciones
Rational Rational::div(const Rational& that)
{
	return Rational(this->num * that.den, this->den * that.num);
}

// Operaciones logicas

// Funcion que devuelve true si dos fracciones son iguales
bool Rational::equal(const Rational& that)
{
	return this->num == that.num && this->den == that.den;
}

// Funcion que devuelve true si una fraccion es menor que otra
bool Rational::lesser_than(const Rational& that)
{
	return this->num * that.den < that.num * this->den;
}

// Funcion que devuelve true si una fraccion es mayor que otra
bool Rational::greater_than(const Rational& that)
{
	return this->num * that.den > that.num * this->den;
}
