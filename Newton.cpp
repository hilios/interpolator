/*
 *  Newton.cpp
 *  TrabMetodos
 */

#include "Newton.h"

Newton::Newton () : Interpolacao () 
{
}
Newton::~Newton () 
{
}

string Newton::calcular ()
{
	stringstream stream;
	vector<FuncaoNewton*> ordem;
	// Salva os fxs dentro do vetor ordem[0]
	ordem.push_back ( new FuncaoNewton () );
	for (vector<double>::size_type i = 0; i < f.size (); i++)
		ordem[0]->f.push_back ( Xis (f[i], 0) );
	
	// Calcula as ordens
	for (vector<double>::size_type i = 0; i < x.size ()-1; i++)
	{
		ordem.push_back ( new FuncaoNewton () );
		for (vector<FuncaoNewton>::size_type j = 1; j < ordem[i]->f.size (); j++)
		{
			Xis df = ordem[i]->f[j] - ordem[i]->f[j-1];
			Xis dx = Xis (x[j+i]) - Xis (x[j-1]);
			Xis dd = df / dx;
			ordem[i+1]->f.push_back ( dd );
		}
	}
	// Coloca no vetor polinomio os primeiros valores de cada ordem
	vector<Xis> transicao;
	for (vector<FuncaoNewton>::size_type i = 0; i < ordem.size (); i++)
		transicao.push_back ( ordem[i]->f[0] );
	
	// Aplica a distributiva
	for (vector<Xis>::size_type i = 0; i< transicao.size (); i++)
	{
		vector<Xis> temp;
		temp.push_back ( transicao[i] );
		
		for (int j = 0; j < i; j++)
		{
			vector<Xis> distributiva;
			for (vector<Xis>::size_type k = 0; k < temp.size (); k++)
			{
				distributiva.push_back ( temp[k] * Xis (1.0, 1) );
				distributiva.push_back ( temp[k] * Xis (x[j] * -1.0, 0) );
			}
			copy (distributiva, temp);
		}
		addBack (temp, polinomio);
		temp.clear ();
	}
	// Soma os elementos iguais e depois divide cada um pelo divisor
	for (vector<Xis>::size_type i = 0; i < polinomio.size (); i++)
	{
		for (vector<Xis>::size_type j = polinomio.size ()-1; j > i ; j--)
		{
			if (polinomio[j].potencia == polinomio[i].potencia)
			{
				polinomio[i] = polinomio[i] + polinomio[j];
				
				if (j == polinomio.size ()-1) // Caso seja o ultimo elemento usa a função pop_back
					polinomio.pop_back ();    // Isso precisa ser assim pq a função erase NÃO apaga o ultimo elemento
				else
					polinomio.erase ( polinomio.begin () + j );
			}
		}
	}
	//Gospe o resultado
	for (vector<Xis>::size_type i = 0; i < polinomio.size (); i++)
		stream << polinomio[i].toString ();
	
	stream << endl;
	
	return stream.str ();
}
double Newton::plotar (double x)
{
	double calc = 0.0;
	for (vector<Xis>::size_type i = 0; i < polinomio.size (); i++)
		calc += polinomio[i].setX (x);
	
	return calc;
}
void Newton::addBack (vector<Xis> &a, vector<Xis> &b)
{
	for (vector<Xis>::size_type i = 0; i < a.size (); i++)
		b.push_back ( a[i] );
}
void Newton::copy (vector<Xis> &a, vector<Xis> &b)
{
	b.clear ();
	addBack (a, b);
}