/*
 *  FuncaoLagrange.h
 *  TrabMetodos
 */

#ifndef FUNCLAGRANGE_H
#define FUNCLAGRANGE_H
#include "Xis.h"
#include <vector>

using namespace std;

class FuncaoLagrange
{
	public:
		
		FuncaoLagrange (int i, vector<double> &x, vector<double> &f);
		FuncaoLagrange (vector<Xis> &p);
		FuncaoLagrange (Xis &x);
		FuncaoLagrange ();
		~FuncaoLagrange ();
	
		FuncaoLagrange   operator + (const FuncaoLagrange &L);
		FuncaoLagrange   operator * (const FuncaoLagrange &L);
		FuncaoLagrange & operator = (const FuncaoLagrange &L);
		
		string toString ();
		double plotar (double x);
	
	private:
		vector<Xis> polinomio;
		void copy (vector<Xis> &a, vector<Xis> &b);
};

#endif