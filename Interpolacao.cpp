/*
 *  Interpolacao.cpp
 *  TrabMetodos
 */

#include "Interpolacao.h"

Interpolacao::Interpolacao ()
{
	qtd = 0;
	grau = 0;
}
Interpolacao::~Interpolacao () 
{
	clear ();
}
void Interpolacao::insertX (double &x)
{
	qtd++;
	this->x.push_back (x);
}
void Interpolacao::insertF (double &f)
{
	this->f.push_back (f);
}
int Interpolacao::length ()
{
	return qtd;
}
void Interpolacao::clear ()
{
	x.clear ();
	f.clear ();
}
string Interpolacao::tabela ()
{
	stringstream temp;
	temp << "\n"
		 << "Valores informados são:" << "\n"
		 << " x  :" << "\t";
	for (vector<double>::iterator i = x.begin(); i != x.end(); i++)
	{
		temp << *i << "\t";
	}
	temp << "\n"
		 << "f(x):" << "\t";
	for (vector<double>::iterator i = f.begin(); i != f.end(); i++)
	{
		temp << *i << "\t";
	}
	temp << "\n";
	return temp.str ();
}