/*
 *  Lagrange.cpp
 *  TrabMetodos
 */

#include "Lagrange.h"
#include <iostream>

Lagrange::Lagrange () : Interpolacao () 
{
}
Lagrange::~Lagrange () 
{
	// Apaga da memória todos os objetos FuncaoLagrange do vetor
	for (vector<FuncaoLagrange*>::iterator i = L.begin (); i != L.end (); ++i)
	{
		delete *i;
	}
	L.clear ();
}

string Lagrange::calcular ()
{
	cout << "Funções parciais:" << endl;
	// Gera as funções parciais de Lagrange L(x)
	for (int i = 0; i < qtd; i++)
	{
		L.push_back ( new FuncaoLagrange (i, x, f) );
	}
	// Aplica a distributiva com os f(x)s para gerar o polinomio de aproxinação
	polinomio = *L[0];
	for (vector<FuncaoLagrange>::size_type i = 1; i < L.size (); i++)
	{
		polinomio = polinomio + *L[i];
	}
	return polinomio.toString ();
}
double Lagrange::plotar (double x)
{
	return polinomio.plotar (x);
}