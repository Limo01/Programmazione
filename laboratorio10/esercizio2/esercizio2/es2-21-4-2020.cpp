#include<iostream>
using namespace std;

struct nodo { int info; nodo* next; nodo(int a = 0, nodo* b = NULL) { info = a; next = b; } };

void stampa(nodo* y)
{
	while (y)
	{
		cout << y->info << ' ';
		y = y->next;
	}
	cout << endl;
}

void append(nodo** testa, int info)
{
	nodo* nuovo_nodo = new nodo(info);
	nodo* coda = *testa;

	if (*testa == NULL)
		*testa = nuovo_nodo;
	else
	{
		while (coda->next != NULL)
			coda = coda->next;
		coda->next = nuovo_nodo;
	}
}

void match(int* X, int* P, int dimP)
{
	bool match = true;
	for (int i = 0; i < dimP && match; i++)
		match = X[i] == P[i];
		

	if (!match)
		throw(-1);
}

nodo* matchStrato(int* X, int inizio, int lungS, int* P, int dimP, int nele)
{
	nodo* testa = NULL;
	nodo* lista = NULL;
	
	for(int i=0, nMatch=0; i<=lungS-dimP && inizio+i<nele;)
	{
		try
		{
			match(X + inizio + i, P, dimP);
			
			append(&testa, inizio + i);

			nMatch++;
			i += dimP;
		}
		catch(int e)
		{
			i++;
		}
	}
	return testa;
}

nodo* getCoda(nodo* lista)
{
	if(lista!=NULL)
	{
		while (lista->next != NULL)
			lista = lista->next;
		return lista;
	}
}

int main()
{

	int X[100], lim1, lim2, lim3, nele;
	cin >> lim1 >> lim2 >> lim3 >> nele;
	for (int i = 0; i < nele; i++)
		cin >> X[i];
	int P[20], dimP;
	cin >> dimP;
	for (int i = 0; i < dimP; i++)
		cin >> P[i];
	nodo* Y = NULL;

	Y = matchStrato(X, 0, lim2 * lim3, P, dimP, nele);

	nodo* lista_conc;
	for(int s=1; s<lim1; s++)
	{
		lista_conc = matchStrato(X, s * lim2 * lim3, lim2 * lim3, P, dimP, nele);

		if (Y == NULL)
			Y = lista_conc;
		else
			getCoda(Y)->next = lista_conc;
	}
	
	stampa(Y);
}
