/*
 *  Lagrange.h
 *  TrabMetodos
 */

#ifndef LAGRANGE_H
#define LAGRANGE_H
#include "Interpolacao.h"
#include "FuncaoLagrange.h"

using namespace std;

class Lagrange : public Interpolacao
{
	public:
		Lagrange ();
		~Lagrange ();
		
		string calcular ();
		double plotar (double x);

	private:
		FuncaoLagrange polinomio;
		vector<FuncaoLagrange*> L;
};

#endif