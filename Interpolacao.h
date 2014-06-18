/*
 *  Interpolacao.h
 *  TrabMetodos
 */

#ifndef INTERPOLACAO_H
#define INTERPOLACAO_H
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Interpolacao
{
	public:
		Interpolacao ();
		~Interpolacao ();
	
		void insertX (double &x);
		void insertF (double &f);
	
		int length ();
		void clear ();
		string tabela ();
	
	virtual string calcular () { return ""; };
	virtual double plotar (double x) { return 0.0; }
	
	protected:
		vector<double> x;
		vector<double> f;
		
		unsigned int qtd;
		unsigned int grau;
};

#endif