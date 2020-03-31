#include<iostream>
using namespace std;

void stampa(int* X, int n_ele, int colonne)
{
	int nr = n_ele / colonne, resto = n_ele % colonne;
	for (int i = 0; i < nr; i++)
	{
		for (int j = 0; j < colonne; j++)
			cout << X[i * colonne + j] << ' ';
		cout << endl;
	}
	for (int i = 0; i < resto; i++)
		cout << X[nr * colonne + i] << ' ';
	cout << endl;
}

//PRE=(p punta al primo elemento di X e gli altri parametri sono ben definiti)
int& TV(int* p, int lim1, int lim2, int lim3, int n_ele, int f, int n, bool& ok)
{
	ok = ((f + lim3 * n) < n_ele) && (n < lim1*lim2);

	return *(p + (f + lim3 * n));
}
//POST=(ok=true sse l’elemento n della V-fetta di indice f esiste ed è definito) &&(se ok=true allora la funzione restituisce questo elemento per riferimento)

//PRE=(p punta al primo elemento di X e gli altri parametri sono ben definiti)
int& TH(int* p, int lim1, int lim2, int lim3, int n_ele, int f, int n, bool& ok)
{
	int strato = n / lim3;
	n -= strato * lim3;

	ok = ((n + (strato * lim2 * lim3) + (f * lim3)) < n_ele) && (n < lim1 * lim3);

	return *(p + (n + (strato * lim2 * lim3) + (f*lim3)));
}
//POST=(ok=true sse l’elemento n della H-fetta di indice f esiste ed è definito) &&(se ok=true allora la funzione restituisce questo elemento per riferimento)

int main()
{
	int X[100], lim1, lim2, lim3, n_ele;
	cin >> lim1 >> lim2 >> lim3 >> n_ele;
	
	for (int i = 0; i < n_ele; i++)
		cin >> X[i];
	bool stop = false, b1 = true, b2 = true;
	
	while (!stop)
	{
		int fV, nV, fH, nH;
		cin >> fV;
		if (fV == -1)
			stop = true;
		else
		{
			cin >> nV >> fH >> nH;
			
			int& y = TV(X, lim1, lim2, lim3, n_ele, fV, nV, b1);
			int& z = TH(X, lim1, lim2, lim3, n_ele, fH, nH, b2);

			if (b1 && b2)
			{
				int appoggio = y;
				y = z;
				z = appoggio;
			}
			else
				cout << "operazione non consentita" << endl;
		}
	}
	stampa(X, n_ele, lim3);
}
