//--------------------------------------------------------------------------------
// File: rational.cc
// Author: Jorge Jaime Modrego (845067) y Javier Julve Yubero (840710)
// Date: Febrero 2024
//--------------------------------------------------------------------------------
#include "rational.h"

using namespace std;
// Auxiliares

//Funcion que devuelve el maximo comun divisor de dos numeros
int Rational::mcd(int a, int b)
{
	return ( b == 0 ? a : mcd(b,a%b));
}

// Funcion que reduce una fraccion
void Rational::reduce()
{
	int aux = mcd(this->num, this->den);
	this->num = this->num / aux;
	this->den = this->den / aux;
}

// Constructores

Rational::Rational() : num(0), den(1) {}

Rational::Rational(int num, int den) : num(num), den(den)
{
	this->reduce();
}

// Operadores aritmeticos

// Funcion que suma dos fracciones
Rational Rational::add(const Rational& that) const
{
	return Rational(this->num * that.den + that.num * this->den, this->den * that.den);
}

// Funcion que resta dos fracciones
Rational Rational::sub(const Rational& that) const
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

//Modificación de los operadores aritméticos

// Operador suma
Rational Rational::operator+(const Rational& that) const
{
	return this->add(that);
}

// Operador resta
Rational Rational::operator-(const Rational& that) const
{
	return this->sub(that);
}

// Operador multiplicación
Rational operator*(const Rational& that, const Rational& r)
{
	return Rational(that.num * r.num, that.den * r.den);
}

// operador división
Rational operator/(const Rational& that, const Rational& r)
{
	return Rational(that.num * r.den, that.den * r.num);
}


// Operadores logicos

// Funcion que devuelve true si dos fracciones son iguales
bool Rational::equal(const Rational& that) const
{
	return this->num == that.num && this->den == that.den;
}

// Funcion que devuelve true si una fraccion es menor que otra
bool Rational::lesser_than(const Rational& that) const
{
	return this->num * that.den < that.num * this->den;
}

// Funcion que devuelve true si una fraccion es mayor que otra
bool Rational::greater_than(const Rational& that) const
{
	return this->num * that.den > that.num * this->den;
}



//Modificación de los operadores lógicos

// Operador igualdad
bool Rational::operator==(const Rational& that) const
{;
	return this->equal(that);
}

// Operador menor que
bool Rational::operator<(const Rational& that) const
{
	return this->lesser_than(that);
}

// Operador mayor que
bool Rational::operator>(const Rational& that) const
{
	return this->greater_than(that);
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

//Modificación operadores entrada/salida

// Operador de salida
std::ostream& operator<<(std::ostream& os, const Rational& r)
{
	r.write(os);
	return os;
}

// Operador de entrada
std::istream& operator>>(std::istream& is, Rational& r)
{
	r.read(is);
	return is;
}
