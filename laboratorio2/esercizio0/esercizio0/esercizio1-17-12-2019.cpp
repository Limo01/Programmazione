#include<iostream>
using namespace std;
void leggi(int X[], int m);
int trovaporz(int Y[], int q);

int main()
{
	int A[100], n;
	cin >> n;

	leggi(A, n);
	cout << "k=" << trovaporz(A, n);
}

/*
 * PRE: Array X vuoto e m < X.length
 * POST: Array X riempito con m valori distinti letti da tastiera
 */
void leggi(int X[], int m)
{
	for (int i = 0; i < m; i++)
	{
		cin >> X[i];
	}
}

/*
 * PRE: Array Y contentente valori distinti e q elementi da considerare (a partire dalla poszione 0)
 * POST: Numero k che indica la lunghezza della porzione crescente dell'array (che parte dall'indice 0)
 */
int trovaporz(int Y[], int q)
{
	int k = 1;

	for (int i = 1; i < q && k == i; i++)
	{
		if (Y[i - 1] < Y[i])
			k++;
	}

	return k;
}
