/*
 *  X.cpp
 *  TrabMetodos
 */

#include "Xis.h"

Xis::Xis (double multiplicador, int potencia)
{
	this->multiplicador = multiplicador;
	this->potencia = potencia;
}
Xis::~Xis () {}
Xis Xis::operator * (const Xis &x)
{
	return Xis (multiplicador * x.multiplicador, potencia + x.potencia);
}
Xis Xis::operator / (const Xis &x)
{
	if (x.multiplicador != 0)
		return Xis (multiplicador / x.multiplicador, potencia - x.potencia);
	else
		return *this;
}
Xis Xis::operator + (const Xis &x)
{
	if (potencia == x.potencia)
		return Xis (multiplicador + x.multiplicador, potencia);
	else
		return *this;
}
Xis Xis::operator - (const Xis &x)
{
	if (potencia == x.potencia)
		return Xis (multiplicador - x.multiplicador, potencia);
	else
		return *this;
}
Xis & Xis::operator = (const Xis &x)
{
	multiplicador = x.multiplicador;
	potencia = x.potencia;
	return *this;
}
string Xis::toString ()
{
	if (multiplicador == 0.0)
		return "";
	
	stringstream temp;
	temp << (multiplicador < 0.0 ? "-" : "+") ;
	// Não exibe o multiplicador quando esse for 1 e tiver um x
	if (fabs (multiplicador) != 1 || potencia == 0)
		temp << fabs (multiplicador);
	
	if (potencia == 1)
		temp << "x";
	else if (potencia != 0)
		temp << "x^" << potencia;
	return temp.str();
}
double Xis::setX (double x)
{
	if (multiplicador == 0.0)
		return 0.0;
	
	if (potencia == 0)
		return multiplicador;
	
	return multiplicador * pow (x, double (potencia) );
}