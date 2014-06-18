/*
 *  Newton.h
 *  TrabMetodos
 */

#ifndef NEWTON_H
#define NEWTON_H
#import <sstream>
#import <iostream>
#import "Interpolacao.h"
#import "Xis.h"

using namespace std;

class Newton : public Interpolacao
{
public:
	
	Newton ();
	~Newton ();
	
	string calcular ();
	double plotar (double x);
private:
	vector<Xis> polinomio;
	struct FuncaoNewton
	{
		vector<Xis> f;
	};
	void addBack (vector<Xis> &a, vector<Xis> &b);
	void copy (vector<Xis> &a, vector<Xis> &b);
};

#endif