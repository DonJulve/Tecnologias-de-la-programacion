#include "rational.h"

using namespace std;
// Auxiliares

int Rational::mcd(int a, int b)
{
	return ( b == 0 ? a : mcd(b,a%b));
}

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

Rational Rational::add(const Rational& that) const
{
	return Rational(this->num * that.den + that.num * this->den, this->den * that.den);
}

Rational Rational::sub(const Rational& that) const
{
	return Rational(this->num * that.den - that.num * this->den, this->den * that.den);
}

Rational Rational::mul(const Rational& that)
{
	return Rational(this->num * that.num, this->den * that.den);
}

Rational Rational::div(const Rational& that)
{
	return Rational(this->num * that.den, this->den * that.num);
}

//Modificación de los operadores aritméticos

Rational Rational::operator+(const Rational& that) const
{
	return this->add(that);
}

Rational Rational::operator-(const Rational& that) const
{
	return this->sub(that);
}

Rational operator*(const Rational& that, const Rational& r)
{
	return Rational(that.num * r.num, that.den * r.den);
}

Rational operator/(const Rational& that, const Rational& r)
{
	return Rational(that.num * r.den, that.den * r.num);
}


// Operadores logicos
bool Rational::equal(const Rational& that) const
{
	return this->num == that.num && this->den == that.den;
}

bool Rational::lesser_than(const Rational& that) const
{
	return this->num * that.den < that.num * this->den;
}

bool Rational::greater_than(const Rational& that) const
{
	return this->num * that.den > that.num * this->den;
}



//Modificación de los operadores lógicos

bool Rational::operator==(const Rational& that) const
{;
	return this->equal(that);
}

bool Rational::operator<(const Rational& that) const
{
	return this->lesser_than(that);
}

bool Rational::operator>(const Rational& that) const
{
	return this->greater_than(that);
}

// Entrada/salida
void Rational::write(std::ostream& os) const
{
	os << this->num << "/" << this->den;
}

void Rational::read(std::istream& is)
{
	char c;
	is >> this->num >> c >> this->den;
	this->reduce();
}

//Modificación operadores entrada/salida

std::ostream& operator<<(std::ostream& os, const Rational& r)
{
	r.write(os);
	return os;
}

std::istream& operator>>(std::istream& is, Rational& r)
{
	r.read(is);
	return is;
}
