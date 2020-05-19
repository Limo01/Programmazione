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

nodo* clone(nodo* L)
{
	if (L)
	{
		return new nodo(L->info, clone(L->next));
	}
	return 0;


}

//PRE = (Lista(L) ben formata)
nodo* elimOne(nodo* L, int x)
{
	if (!L)
	{
		return 0;
	}
	else if (L->info == x)
	{
		nodo* next = L->next;
		delete L;
		return next;
	}
	L->next = elimOne(L->next, x);
	return L;
}
//POST = (restituisce una lista che contiene tutti i nodi di Lista(L) a parte il primo con info = x, che, se esiste, va anche deallocato)

//PRE=(Lista(L) ben formata e non vuota e col primo nodo tale che il suo campo info non sia x, vLista(L)=Lista(L))
void elimOne2(nodo* L, int  x)
{
	if (L->next && L->next->info == x)
	{
		nodo* next = L->next->next;
		delete L->next;
		L->next = next;
	}
	else if (L->next)
		elimOne2(L->next, x);
}
//POST=(Lista(L) contiene tutti i nodi di vLista(L) a parte il primo con info=x, che, se esiste, va anche deallocato)

//PRE=(Lista(L) ben formatae VLista(L)=Lista(L))
void elimOne3(nodo*& L, int x)
{
	if (L && L->info == x)
	{
		nodo* next = L->next;
		delete L;
		L = next;
	}
	else if(L && L->next)
		elimOne(L->next, x);
}
//POST=(Lista(L) è come vLista(L) a parte il primo nodo con info=x, che, se esiste, va anche deallocato)

int main()
{
	int m, x;
	cin >> m >> x;
	nodo* L = faiL(m);

	nodo* L2, * L3;
	L2 = clone(L);
	if (L2->info == x)
		L2 = new nodo(x + 1, L2);
	L3 = clone(L);

	L = elimOne(L, x);
	elimOne2(L2, x);
	elimOne3(L3, x);

	stampa(L);
	stampa(L2);
	stampa(L3);
}