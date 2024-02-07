//--------------------------------------------------------------------------------
// File: rational.cc
// Author: Jorge Jaime Modrego (845067) y Javier Julve Yubero (840710)
// Date: Febrero 2024
//--------------------------------------------------------------------------------
#include "rational.h"
#include <iostream>

using namespace std;

// Auxiliares, privadas

//Funcion que devuelve el maximo comun divisor de dos numeros
int mcd(int a, int b)
{
	return ( b==0 ? a : mcd(b,a%b) );
}

// Funcion que reduce una fraccion
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

// Inicializa un numero racional a 0/1
void init(Rational& r)
{
	setNum(r,0);
	setDen(r,1);
}

// Inicializa un numero racional a num/den
void init(Rational& r,int num, int den)
{
	setNum(r,num);
	setDen(r,den);
}

// Entrada/salida

// Escribe un numero racional en un flujo de salida
void write(std::ostream& os, const Rational& r)
{
	cout << getNum(r) << "/" << getDen(r) << endl;
}

// Lee un numero racional de un flujo de entrada
void read(std::istream& is, Rational& r)
{
	char c;
	int n,d;
	cin >> n >> c >> d;
	setNum(r,n);
	setDen(r,d);
	reduce(r);
}

// Operaciones aritmeticas

// Suma dos numeros racionales
Rational add(const Rational& r1, const Rational& r2)
{
	Rational r;
	int n,d;
	n = getNum(r1)*getDen(r2) + getNum(r2)*getDen(r1);
	d = getDen(r1)*getDen(r2);
	setNum(r,n);
	setDen(r,d);
	reduce(r);
	return r;
}

// Resta dos numeros racionales
Rational sub(const Rational& r1, const Rational& r2)
{
	Rational r;
	int n,d;
	n = getNum(r1)*getDen(r2) - getNum(r2)*getDen(r1);
	d = getDen(r1)*getDen(r2);
	setNum(r,n);
	setDen(r,d);
	reduce(r);
	return r;
}

// Multiplica dos numeros racionales
Rational mul(const Rational& r1, const Rational& r2)
{
	Rational r;
	int n,d;
	n = getNum(r1)*getNum(r2);
	d = getDen(r1)*getDen(r2);
	setNum(r,n);
	setDen(r,d);
	reduce(r);
	return r;
}

// Divide dos numeros racionales
Rational div(const Rational& r1, const Rational& r2)
{
	Rational r;
	int n,d;
	n = getNum(r1)*getDen(r2);
	d = getDen(r1)*getNum(r2);
	setNum(r,n);
	setDen(r,d);
	reduce(r);
	return r;
}

// Operaciones logicas

// Compara si dos numeros racionales son iguales
bool equal(const Rational& r1, const Rational& r2)
{
	return (getNum(r1) == getNum(r2) && getDen(r1) == getDen(r2));
}

// Compara si un numero racional es menor que otro
bool lesser_than(const Rational& r1, const Rational& r2)
{
	return ( getNum(r1)*getDen(r2) - getDen(r1)*getNum(r2) < 0 );
}

// Compara si un numero racional es mayor que otro
bool greater_than(const Rational& r1, const Rational& r2)
{
	return ( getNum(r1)*getDen(r2) - getDen(r1)*getNum(r2) > 0 );
}

// Getters y setters

// Modifica el numerador de un numero racional
void setNum(Rational& r, int num)
{
	r.num = num;
}

// Modifica el denominador de un numero racional
void setDen(Rational& r, int den)
{
	r.den = den;
}

// Devuelve el numerador de un numero racional
int getNum(const Rational& r)
{
	return r.num;
}

// Devuelve el denominador de un numero racional
int getDen(const Rational& r)
{
	return r.den;
}
