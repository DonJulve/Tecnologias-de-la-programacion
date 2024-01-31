#include "rational.h"

// Auxiliares

int Rational::mcd(int a, int b)
{
	return ( b == 0 ? a : mcd(b,a%b));
}

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

// Operaciones aritmeticas

Rational Rational::add(const Rational& that)
{
	return Rational(this->num * that.den + that.num * this->den, this->den * that.den);
}

Rational Rational::sub(const Rational& that)
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

// Operaciones logicas

bool Rational::equal(const Rational& that)
{
	return this->num == that.num && this->den == that.den;
}

bool Rational::lesser_than(const Rational& that)
{
	return this->num * that.den < that.num * this->den;
}

bool Rational::greater_than(const Rational& that)
{
	return this->num * that.den > that.num * this->den;
}
