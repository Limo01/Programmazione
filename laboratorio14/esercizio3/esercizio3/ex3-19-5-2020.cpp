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
		return new nodo(L->info, clone(L->next));
	return 0;
}


nodo* insOrd_ric(nodo* L, nodo* x)
{
	if (!L) return x;
	if (x->info >= L->info) L->next = insOrd_ric(L->next, x);
	else
	{
		x->next = L;
		return x;
	}
}

//PRE = (L(L) è ben formata)
nodo* ord_ric(nodo* L, nodo* newL)
{
	if (L)
	{
		nodo* succ = L->next;
		L->next = 0;
		newL = insOrd_ric(newL, L);
		L = succ;
		return ord_ric(L, newL);
	}
	else return newL;
}
//POST = (restituisce una lista ordinata composta con tutti i nodi di L(n))


nodo* insOrd_iter(nodo* L, nodo* x)
{
	if (!L) return x;
	else if (x->info < L->info)
	{
		x->next = L;
		L = x;
	}
	else
	{
		nodo* pL = L;
		while (pL->next && x->info >= pL->next->info)
		{
			pL = pL->next;
		}

		if (!pL->next)
			pL->next = x;
		else
		{
			x->next = pL->next;
			pL->next = x;
		}
	}
	return L;
}

//PRE = (L(L) è ben formata)
nodo* ord_iter(nodo* L)
{
	nodo* newL = 0;
	nodo* succ;
	while(L)
	{
		succ = L->next;
		L->next = 0;
		newL= insOrd_iter(newL, L);
		L = succ;
	}
	return newL;
}
//POST = (restituisce una lista ordinata composta con tutti i nodi di L(n))


int main()
{
	int m;
	cin >> m;
	nodo* L = faiL(m);
	nodo* P = clone(L);

	L = ord_ric(L, 0);
	P = ord_iter(P);
	stampa(L);
	stampa(P);
}
