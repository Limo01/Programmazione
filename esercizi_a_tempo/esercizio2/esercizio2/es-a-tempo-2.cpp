#include<iostream>
using namespace std;

//PRE = (X contiene almeno n_ele elementi, n_ele, lim1, lim2 e lim3 sono > 0, cincontiene n_ele valori)
void leggiV(int* X, int n_ele, int lim1, int lim2, int lim3)
{
	for (int colonne = 0, i = 0; (colonne < lim3) & (i < n_ele); colonne++)//INVARIANTE: (i contatore degli elementi attualmemnte inseriti nell'Array) & (colonne è l'indice della colonna che andiamo a rimpire) & (0 <= i < n_ele) & (0 <= colonne <= lim3)
	{
		for (int strati = 0; (strati < lim1) & (i < n_ele); strati++)//INVARIANTE: (i contatore degli elementi attualmemnte inseriti nell'Array) & (colonne è l'indice della colonna che andiamo a rimpire) & (strati indica lo strato della colonna che andiamo a riempire) & (0 <= i < n_ele) & (0 <= colonne <= lim3) & (0 <= strato < lim1)
		{
			for (int righe = 0; (righe < lim2) & (i < n_ele); righe++, i++)//INVARIANTE: (i contatore degli elementi attualmemnte inseriti nell'Array) & (colonne è l'indice della colonna che andiamo a rimpire) & (strati indica lo strato della colonna che andiamo a riempire) & (righe è l'indice della riga che andiamo a riempire X[strati][righe][colonne]) & (0 <= i < n_ele) & (0 <= colonne <= lim3) & (0 <= strato < lim1) & (0 <= righe < lim2)
			{
				cin >> *(X + (strati*lim2*lim3)+(righe*lim3)+colonne);
			}
		}
	}
}
//POST=(in X vista come int[lim1][lim2][lim3]sono stati letti gli n_ele valori di cin per V-fette)

/*CORRETTEZZA LEGGIV():	Per inserire gli elementi nell'Array per V-Fette bisogna riempire per l'Array tridimensionale per colonne. Quindi sarà necessario riempire per prima la posizione X[0][0][0], poi X[0][1][0], poi ancora X[0][1...lim2][0].
						Quando completiamo uno strato, si passa al successivo, quindi X[1][0][0] e si riempiono tutte le posizioni della colonna zero e si ripete per ogni strato, quindi X[0...lim1][...][...]. Ovviamente per si riempie fino a quando il contatore i
						è minore di n_ele. Sfruttiamo le allocazioni contigue degli Array per intepretare le tre dimensioni in un'unica dimensione. La formula per calcolare la posizione nell'Array ad una dimensione di una posizione in tre dimensioni [strati][righe][colonne]
						è (strati*lim2*lim3)+(righe*lim3)+colonne.
*/

void stampaS(int* X, int n_ele, int lim1, int lim2, int lim3, int strato)
{
	if (n_ele > lim1* lim2* lim3)
		n_ele = lim1 * lim2 * lim3;

	for(int i=strato*lim2*lim3, n=(strato*lim2), r=0; (n < n_ele) && (r < lim2); i+=lim3, n++, r++)
	{
		cout << "r" << r << ": ";
		for(int j=i, n2=n; (n2 < n_ele); j++, n2+=lim1*lim2)
		{
			cout << *(X+j) << " ";
		}
		cout << endl;
	}
}

int main()
{
	int A[400], n_ele, lim1, lim2, lim3, strato;
	cin >> n_ele >> lim1 >> lim2 >> lim3 >> strato;
	
	leggiV(A, n_ele, lim1, lim2, lim3);
	stampaS(A, n_ele, lim1, lim2, lim3, strato);
}