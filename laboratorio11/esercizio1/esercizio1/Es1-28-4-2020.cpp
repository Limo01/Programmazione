#include<iostream>
using namespace std;
struct nodo { int colonna; nodo* next; nodo(int a = 0, nodo* b = 0) { colonna = a; next = b; } };



void leggi(bool* X, int n)
{

	for (int i = 0; i < n * n; i++)
		cin >> X[i];
}


void stampa(nodo* X, int n)
{
	if (X)
	{
		cout << "riga:" << n << " colonna=" << X->colonna << endl;
		stampa(X->next, n + 1);
	}

}

int contaNodi(nodo* lista)
{
	int i = 1;
	for (; lista; i++, lista = lista->next);
	return i;
}

nodo* searchPath(bool* B, int r, int c, int n)
{
	if (r == n - 1)
	{
		if (B[r * n + c])
			return new nodo(c);
		else
			return 0;
	}
	else if (c >= 0 && c < n && B[n * r + c])
	{
		nodo* lista = new nodo(c);
		lista->next = searchPath(B, r + 1, c - 1, n);
		if(!lista->next)
		{
			lista->next = searchPath(B, r + 1, c, n);
			if (!lista->next)
				lista->next = searchPath(B, r + 1, c+1, n);
		}
		return lista;
	}
	else
		return 0;
}

int main()
{
	int n;
	cin >> n;
	bool* B = new bool[n * n];
	leggi(B, n);

	nodo* x = 0;
	for (int i = 0; i < n && !x; i++)
		x = searchPath(B, 0, i, n);	

	if (contaNodi(x)<=n)
		cout << "non c'e' cammino" << endl;
	else
		stampa(x, 0);
}