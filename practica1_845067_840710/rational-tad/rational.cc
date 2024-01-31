#include "rational.h"
#include <iostream>

using namespace std;

// Auxiliares, privadas

int mcd(int a, int b)
{
	return ( b==0 ? a : mcd(b,a%b) );
}

void reduce(Rational& r)
{
	int aux = mcd(getNum(r),getDen(r));
	int n = getNum(r);
	int d = getDen(r);
	while(aux != 1){
		n /= aux;
		d /= aux;
		aux = mcd(n,d);
   }
   setNum(r,n);
   setDen(r,d);
}

// Inicializadores

void init(Rational& r)
{
	r.num = 0;
	r.den = 1;
}

void init(Rational& r,int num, int den)
{
	r.num = num;
	r.den = den;
}

// Entrada/salida

void write(std::ostream& os, const Rational& r)
{
	cout << r.num << "/" << r.den << endl;
}

void read(std::istream& is, Rational& r)
{
	char c;
	cin >> r.num >> c >> r.den;
	reduce(r);
}

// Operaciones aritmeticas

Rational add(const Rational& r1, const Rational& r2)
{
	Rational r;
	r.num = getNum(r1)*getDen(r2) + getNum(r2)*getDen(r1);
	r.den = getDen(r1)*getDen(r2);
	reduce(r);
	return r;
}

Rational sub(const Rational& r1, const Rational& r2)
{
	Rational r;
	r.num = getNum(r1)*getDen(r2) - getNum(r2)*getDen(r1);
	r.den = getDen(r1)*getDen(r2);
	reduce(r);
	return r;
}

Rational mul(const Rational& r1, const Rational& r2)
{
	Rational r;
	r.num = getNum(r1)*getNum(r2);
	r.den = getDen(r1)*getDen(r2);
	reduce(r);
	return r;
}

Rational div(const Rational& r1, const Rational& r2)
{
	Rational r;
	r.num = getNum(r1)*getDen(r2);
	r.den = getDen(r1)*getNum(r2);
	reduce(r);
	return r;
}

// Operaciones logicas

bool equal(const Rational& r1, const Rational& r2)
{
	return (getNum(r1) == getNum(r2) && getDen(r1) == getDen(r2));
}

bool lesser_than(const Rational& r1, const Rational& r2)
{
	return ( r1.num*r2.den - r1.den*r2.num < 0 );
}

bool greater_than(const Rational& r1, const Rational& r2)
{
	return ( r1.num*r2.den - r1.den*r2.num > 0 );
}

// Getters y setters

void setNum(Rational& r, int num)
{
	r.num = num;
}

void setDen(Rational& r, int den)
{
	r.den = den;
}

int getNum(const Rational& r)
{
	return r.num;
}

int getDen(const Rational& r)
{
	return r.den;
}
