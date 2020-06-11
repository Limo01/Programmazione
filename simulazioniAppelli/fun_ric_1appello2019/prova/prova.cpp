#include <iostream>
using namespace std;

struct nodo
{
	int info;
	nodo* next;

	nodo(int a = 0, nodo* b=0)
	{
		info = a;
		next = b;
	}
};

void stampaL(nodo* n)
{
	if(n)
	{
		cout << n->info << " ";
		stampaL(n->next);
	}
}

//PRE=(Lista(L) bel formata, A ha nA elementi, vL=L)
nodo* patt_match(nodo*& L, int* A, int nA)
{
	if (!L)
		return 0;
	if (nA == 0)
	{
		nodo* n = L;
		L = 0;
		return n;
	}
	if (A[0] == L->info)
		return patt_match(L->next, A + 1, nA - 1);
	else
	{
		nodo* n = L;
		L = L->next;
		n->next = patt_match(L, A, nA);
		return n;
	}
}
//POST=(L è la lista che consiste dei nodi di vL che matchano con A e col return restituisce la lista degli altri nodi di vL)

int main()
{
	//L= 4 -> 2 -> 0 -> 3 -> 11 -> 2 -> 10
	nodo* a = new nodo(4, new nodo(2, new nodo(0, new nodo(3, new nodo(11, new nodo(2, new nodo(10)))))));
	//stampaL(a);
	int A[4] = { 4, 0, 11, 0 };

	nodo* nodiNonMatchati = patt_match(a, A, 4);
	stampaL(nodiNonMatchati);
	cout << endl;
	stampaL(a);
}

/*
CORRETTEZZA patt_match

	CASO BASE 1:		if(!L)
						Se !L, vuol dire che la lista è vuota => non ci sono elementi da matchare => return 0 => POST

	CASO BASE 2:		if(nA==0)
						Se si arriva a questo caso vuol dire che L non è vuota. nA==0 implica che non ci sono più elementi in L da matchare con A, quindi bisogna restituire col return tutti gli elementi di L e impostare L a lista vuota perchè non ha nodi che matchano con A => POST

	CASO RICORSIVO 1:	patt_match(L->next, A+1, nA-1)
						Questa chiamata avviene quando A[0]==L->info, quindi quando c'è un match. In questo caso non bisogna modificare la lista L e bisogna solamente passare al prossimo elemento del match e della lista
						Da PRE	L->next deve essere ben formata => dalle condizione del CASO BASE 1 sappiamo che L!=0, quindi L->next è ben formata
								nA-1 sono il numero di elementi di A => il numero di elementi deve essere sempre >=0 (non può essere negativo), dalle condizioni del CASO BASE 2 sappiamo che nA > 0, quindi nA-1 è sicuramente maggiore o uguale a zero e di conseguenza A+1 è una locazione di memoria valida
						=> PREric1 rispetta la PRE

	CASO RICORSIVO 2:	patt_match(L, A, nA)
						Questa chiamata avviene quando non c'è un match fra il nodo e l'elemento di A. In questo caso bisogna elimare da L l'elemento che non matcha e creare una lista dei nodi che non matchano tramite la chiamata ricorsiva
						Da PRE	L deve essere ben formata => dalle condizioni del CASO BASE 1 sicuramente L!=0, siccome nel blocco L diventa uguale a L->next per rimuovere l'elemento non matchato dalla lista, al massimo L può essere lista vuota, perciò sarà sempre ben formata
								nA rimane lo stesso valore attuale, quindi sarà sicuramente maggiore di zero dalle condizioni del CASO BASE 2 e perchè il numero di elementi di A deve essere >=0 (non può essere negativo)
						=> PREric2 rispetta la PRE
*/