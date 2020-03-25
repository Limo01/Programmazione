#include<iostream>
using namespace std;

//PRE = (X contiene lim2 * lim3 valori e n_ele contiene il numero di elementi da stampare)
void stampaS(int* X, int lim2, int lim3, int n_ele)
{
	if (n_ele > lim2* lim3)//Se il numero di elementi da stampare è maggiore del numero di elementi contenuti nella matrice
		n_ele = lim2 * lim3;//Imposta il numero di elementi da stampare uguale al numero di elementi della matrice

	for (int i = 0, r = 0; (i < n_ele) & (r < lim2); r++)
	{
		cout << "r" << r << ": ";
		for (int c = 0; (i < n_ele) & (c < lim3); i++, c++)
		{
			cout << X[i] << " ";
		}
		cout << endl;
	}
}
//POST= (Stampa a video tutti gli elementi appartenenti allo strato divisi per righe)

int main()
{
	int n_ele, lim1, lim2, lim3, X[400];
	cin >> n_ele;
	for (int i = 0; i < n_ele; i = i + 1)
		cin >> X[i];

	cin >> lim1 >> lim2 >> lim3;//X[lim1][lim2][lim3]

	cout << "start" << endl;

	for (int i = 0; (i < lim1) & (n_ele > 0); i++, n_ele -= (lim2 * lim3))
	{
		cout << "strato" << i << ":" << endl;
		stampaS(X + (i * lim2 * lim3), lim2, lim3, n_ele);
		cout << endl;
	}

	cout << "end" << endl;
}