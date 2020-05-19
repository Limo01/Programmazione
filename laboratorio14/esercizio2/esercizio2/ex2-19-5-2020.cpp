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

//PRE = (Lista(L) ben formata e ordinata, x punta ad un nodo)
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
//POST = (restituisce vL(L) con x aggiunto in modo che la nuova lista sia ancora ordinata)

int main()
{
	int m, x;
	cin >> m >> x;
	nodo* L = faiL(m);
	nodo* L1 = clone(L);

	L = insOrd_ric(L, new nodo(x));
	L1 = insOrd_iter(L1, new nodo(x));
	stampa(L);
	stampa(L1);
}
