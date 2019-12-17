#include<iostream>
using namespace std;

int main()
{
	int n, numeroSpazi;
	cin >> n;
	numeroSpazi = n - 2;

	if (n >= 3)
	{
		/*
		* INVARIANTE: ((1 <= nStelle <= n+2) => n+2 è il numero di stelle della base dell'albero) && 
		*		      ((numeroSpazi >= 0) => Il numero di spazi per centrare l'albero non può essere negativo)
		*/
		for(int nStelle=1; nStelle <= n+2 && numeroSpazi>=0; nStelle+=2, numeroSpazi--)
		{
			for (int i = 0; i < numeroSpazi; i++)
				cout << "b";
			for (int i = 0; i < nStelle; i++)
				cout << "s";
			cout << endl;
		}
		for (int i = 0; i < n - 2; i++)
			cout << "b";
		cout << "s";
	}
	else
		cout << "Altezza non valida" << endl;
}