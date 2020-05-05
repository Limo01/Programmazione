#include<iostream>
using namespace std;

struct nodo { int colonna, val; nodo* next; nodo(int a = 0, int c = 0, nodo* b = 0) { colonna = a; val = c; next = b; } };

void leggi(int* X, int n)
{

	for (int i = 0; i < n * n; i++)
		cin >> X[i];
}

void stampa(nodo* X, int n)
{
	if (X)
	{
		cout << "riga:" << n << " colonna=" << X->colonna << " val=" << X->val << endl;
		stampa(X->next, n + 1);
	}
}

nodo* searchPath_ric(int* B, int r, int c, int n)
{
	if (r == n - 1)
	{
		if (B[r * n + c])
			return new nodo(c, B[r * n + c]);
		else
			return 0;
	}
	else if (c >= 0 && c < n && B[n * r + c])
	{
		nodo* lista = new nodo(c, B[r * n + c]);
		lista->next = searchPath_ric(B, r + 1, c - 1, n);
		if (!lista->next)
		{
			lista->next = searchPath_ric(B, r + 1, c, n);
			if (!lista->next)
				lista->next = searchPath_ric(B, r + 1, c + 1, n);
		}
		return lista;
	}
	else
		return 0;
}

int impostaValPath(nodo* lista)
{
	if (!lista)
		return 0;
	else
	{
		lista->val += impostaValPath(lista->next);
		return lista->val;
	}
}

int contaNodi(nodo* lista)
{
	int i = 1;
	for (; lista; i++, lista = lista->next);
	return i;
}

nodo* searchPath(int* B, int r, int c, int n)
{
	nodo* lista = searchPath_ric(B, r, c, n);
	if (!lista || contaNodi(lista)<=n)
		return 0;
	impostaValPath(lista);
	return lista;
}

int main()
{
	int n;
	cin >> n;
	int* B = new int[n * n];
	leggi(B, n);

	nodo* x = 0;

	for (int i = 0; i < n; i++)
	{
		nodo* y = searchPath(B, 0, i, n);
		if (!x && y)
			x = y;
		else if (x && y && x->val < y->val)
			x = y;
	}

	if (!x)
		cout << "non c'e' cammino" << endl;
	else
		stampa(x, 0);
}


