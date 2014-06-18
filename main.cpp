#include <iomanip>
#include <iostream>
#include "Lagrange.h"
#include "Newton.h"

using namespace std;

bool repeat (string mensagem)
{
	char decisao;
	cout << mensagem << " " << "S: Sim, N: Não = "; cin >> decisao;
	switch (decisao)
	{
		case 83  : // S
		case 115 : // s
			return true;
			break;
		default :
			return false;
			break;
	}
}

int main (int argc, char * const argv[]) 
{
    // Define a precisão de 4 casas decimais
	//cout << fixed << setprecision( 4 );
	
	cout <<
	"                  Trabalho de Métodos Numéricos"                    << endl <<
	"------------------------------------------------------------------" << endl <<
	"|                    Programa de Interpolação                    |" << endl <<
	"------------------------------------------------------------------" << endl;
	
	do
	{
		int func;
		cout << endl
			 << "Qual função de interpolação deseja utilizar?" << endl
			 << "1: Lagrange, 2: Newton = ";
		cin  >> func;
		
		Interpolacao* I;
		switch (func)
		{
			case 1 :
				I = new Lagrange ();
				break;
			case 2 :
				I = new Newton ();
				break;
			default :
				cout << "Voce digitou uma opção inválida." << endl;
				break;
		}
		
		
		if (func == 1 || func == 2)
		{
			int i = 0;
			cout << "Digite os valores de X" << endl;
			do
			{
				cout << "x(" << i++ << ") = ";
				double j; cin >> j;
				I->insertX ( j );
			} while ( repeat ("Deseja digitar outro valor?") );
			
			cout << "Digite os valores de f(x)" << endl;
			for (int i = 0; i < I->length (); i++)
			{
				cout << "f(x_" << i << ") = ";
				double j; cin >> j;
				I->insertF ( j );
			}
			cout << I->tabela () << endl;
			cout << "A função de aproximação é:" << endl
			<< "P(x) = " << I->calcular () << endl;
			
			if ( repeat ("Quer plotar um ponto com esta função?") )
			{
				double x;
				cout << "x = "; cin >> x;
				cout << "P(" << x << ") = " << I->plotar (x) << endl << endl;
			}
			
			delete I;
		}
		
	} while ( repeat ("Deseja repetir a operação?") );
    
    return 0;
}
