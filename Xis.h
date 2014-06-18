/*
 *  Xis.h
 *  TrabMetodos
 *
 *  Created by Edson Hilios on 07/11/08.
 *  Copyright 2008 Mackenzie. All rights reserved.
 *
 */

#ifndef XIS_H
#define	XIS_H
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

class Xis
{
	public:
		int potencia;
		double multiplicador;
		// Métodos para operaçoes matemáticas
		Xis   operator + (const Xis &x);
		Xis   operator - (const Xis &x);
		Xis   operator * (const Xis &x);
		Xis   operator / (const Xis &x);
		Xis & operator = (const Xis &x);
		
		Xis (double multiplicador = 1.0, int potencia = 0);
		~Xis ();
		
		string toString ();
		double setX (double x = 1.0);
};

#endif