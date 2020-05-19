#include<iostream>
using namespace std;
struct nodo { int info; nodo* next; nodo(int a = 0, nodo* b = 0) { info = a; next = b; } };


nodo* faiL(int n)
{
	if (n)
	{
		int x;
		cin >> x;
		return new nodo(x, faiL(n - 1));
	}
	return 0;

}


void stampa(nodo* L)
{
	if (L)
	{
		cout << L->info << ' ';
		stampa(L->next);
	}
	else
		cout << endl;

}

nodo* check_match(nodo*& T, nodo* P, bool& fine)
{
	if (!P)
	{
		fine = !T;
		return T;
	}
	if (!T) return 0;
	else if (T->info == P->info)
	{
		return check_match(T->next, P->next, fine);
	}
	return 0;
}

//PRE = (L(T) e L(P) sono ben formate)
nodo* match(nodo*& T, nodo* P)
{
	if (!T) return 0;
	else
	{
		bool fine = false;
		nodo* x = check_match(T, P, fine);
		if (!x && !fine) match(T->next, P);
		else
		{;
			T = x;
			return P;
		}
	}
}
//POST = (se inT c’è un match di P contiguo e completo, allora la funzione estrae i nodi del match più a sinistra e la restituisce col return mentre T è la lista che resta, se non c’è match la funzione restituisce 0  e L(T) non cambia)

int main()
{
	int m, n;
	cin >> m >> n;
	nodo* T = faiL(m);
	nodo* P = faiL(n);
	P = match(T, P);
	stampa(P);
	stampa(T);
}
