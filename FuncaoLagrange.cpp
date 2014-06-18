/*
 *  FuncaoLagrange.cpp
 *  TrabMetodos
 */

#include "FuncaoLagrange.h"
#include "Xis.h"
#include <iostream>

FuncaoLagrange::FuncaoLagrange (int n, vector<double> &x, vector<double> &f)
{
	Xis div (1, 0); // Inicia o divisor
	
	// Calcula o divisor
	for (vector<double>::size_type i = 0; i < x.size(); i++)
	{
		if (i != n)
			div = div * ( Xis (x[n], 0) - Xis (x[i], 0) );
	}
	// Calcula o polinomio superior
	for (vector<double>::size_type i = 0; i < x.size (); i++)
	{
		if (i != n)
		{
			if (polinomio.size () == 0)
			{
				polinomio.push_back ( Xis (1.0, 1) );			// Cria a incognita x
				polinomio.push_back ( Xis ( x[i] * -1.0, 0 ) ); // Cria o segundo termo do par só que invertendo o sinal
			}
			else
			{
				// Aplica a distributiva
				vector<Xis> temp;
				for (vector<double>::size_type j = 0; j < polinomio.size (); j++)
				{
					temp.push_back ( polinomio[j] * Xis ( 1.0, 1 ) );         // Multiplica pela incognita
					temp.push_back ( polinomio[j] * Xis ( x[i] * -1.0, 0 ) ); // Multiplica pelo valor do x
				}
				copy (temp, polinomio);
				temp.clear ();
			}
		}
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
		polinomio[i] = polinomio[i] / div;
	}
	// Exibe as funções de Lagrange finais
	cout << "L" << n << "(x) = ";
	for (vector<double>::size_type j = 0; j < polinomio.size (); j++)
	{
		cout << polinomio[j].toString ();
	}
	//cout << " / " << div.toString ();
	cout << endl;
	// Multiplica pelo valor de f(x) correpondente
	Xis fx (f[n], 0);
	for (vector<Xis>::size_type i = 0; i < polinomio.size (); i++)
	{
		polinomio[i] = polinomio[i] * fx;
	}
}
double FuncaoLagrange::plotar (double x)
{
	double calc = 0.0;
	for (vector<Xis>::size_type i = 0; i < polinomio.size (); i++)
		calc += polinomio[i].setX (x);
	
	return calc;
}
FuncaoLagrange::FuncaoLagrange (vector<Xis> &p)
{
	copy (p, polinomio);
}
FuncaoLagrange::FuncaoLagrange (Xis &x)
{
	polinomio.push_back ( x );
}
FuncaoLagrange::FuncaoLagrange ()
{
	
}
FuncaoLagrange::~FuncaoLagrange ()
{

}
void FuncaoLagrange::copy (vector<Xis> &a, vector<Xis> &b)
{
	b.clear ();
	for (vector<Xis>::size_type i = 0; i < a.size (); i++)
	{
		b.push_back ( a[i] );
	}
}
string FuncaoLagrange::toString ()
{
	stringstream temp;
	for (vector<Xis>::size_type i = 0; i < polinomio.size (); i++)
	{
		temp << polinomio[i].toString ();
	}
	temp << endl;
	return temp.str ();
}
FuncaoLagrange   FuncaoLagrange::operator + (const FuncaoLagrange &L)
{
	vector<Xis> temp;
	vector<int> potencia;
	for (vector<Xis>::size_type i = 0; i < polinomio.size (); i++)
	{
		bool somou = false;
		potencia.push_back ( polinomio[i].potencia ); // Salva a potencia do elemento em um vetor para posterior verificação
		for (vector<Xis>::size_type j = 0; j < L.polinomio.size (); j++)
		{
			if (polinomio[i].potencia == L.polinomio[j].potencia)
			{
				somou = true;
				temp.push_back ( polinomio[i] + L.polinomio[j] );
			}
		}
		// Caso ele não tenha somado com nada insere o valor no vetor temporario
		if (!somou)
			temp.push_back ( polinomio[i] );
	}
	// Por ultimo verfica se há todos os graus do vetor informado
	// no vetor temporario, e caso esteja faltando algum, insere o valor no vetor
	for (vector<Xis>::size_type i = 0; i < L.polinomio.size (); i++)
	{
		bool find = false;
		for (vector<int>::size_type j = 0; j < potencia.size (); j++)
		{
			if (L.polinomio[i].potencia == potencia[j])
			{
				find = true; // Caso eu ache um elemento com a mesma potencia eu sei que ele já foi inserido no temporario
				break;
			}
		}
		// Caso não eu insiro ele
		if (!find)
			temp.push_back ( L.polinomio[i] );
	}
	return FuncaoLagrange ( temp );
}
FuncaoLagrange   FuncaoLagrange::operator * (const FuncaoLagrange &L)
{
	vector<Xis> temp;
	for (vector<Xis>::size_type i = 0; i < polinomio.size (); i++)
	{
		for (vector<Xis>::size_type j = 0; j < L.polinomio.size (); j++)
		{
			temp.push_back ( polinomio[i] * L.polinomio[j] );
		}
	}
	return FuncaoLagrange ( temp ); 
}
FuncaoLagrange & FuncaoLagrange::operator = (const FuncaoLagrange &L)
{
	polinomio = L.polinomio;
	return *this;
}