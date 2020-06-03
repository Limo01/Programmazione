#include<iostream>
#include "BST.h"
using namespace std;
using namespace BST;

//PRE=(r BST ben definito)
void BST::stampa_l(nodo* r)
{
	if (!r)
		cout << "_";
	else
	{
		cout << r->info << "(";
		stampa_l(r->left);
		cout << ",";
		stampa_l(r->right);
		cout << ")";
	}
}
//POST=(stampa lineare del BST)

//PRE=(r BST ben formato, non vuoto)
nodo* BST::insert(nodo* r, int i)
{
	if (!r)
		return new nodo(i);
	if (r->info > i)
		r->left = insert(r->left, i);
	else if (r->info < i)
		r->right = insert(r->right, i);
	return r;
}
//POST=(Restituisce il nuovo nodo inserito)

//PRE=(r BST ben formato) 
bool BST::search(nodo* r, int i)
{
	if (!r)
		return false;
	if (r->info == i)
		return true;
	if (r->info > i)
		return search(r->left, i);
	return search(r->right, i);
}
//POST=(Restituisce true se esiste un nodo con campo info==i, false altrimenti)

//PRE=(r BST ben formato e non vuoto)
nodo*& BST::max(nodo*& r)
{
	if (!r->right)
		return r;
	max(r->right);
}
//POST=(Restituisce il nodo con il valore massimo all'interno dell'albero)

//PRE=(r BST ben formato e non vuoto)
nodo*& BST::min(nodo*& r)
{
	if (!r->left)
		return r;
	min(r->left);
}
//POST=(Restituisce il nodo con il valore minimo all'interno dell'albero)

//PRE=(r BST ben formato)
int BST::altezza(nodo* r)
{
	if (!r)
		return -1;
	else
	{
		int altezzaSx = altezza(r->left);
		int altezzaDx = altezza(r->right);

		return altezzaSx > altezzaDx ? altezzaSx + 1 : altezzaDx + 1;
	}
}
//POST=(Restituisce l'altezza dell'albero)

//PRE=(r BST ben formato)
int BST::altMin(nodo* r)
{
	if (!r)
		return 0;
	else
	{
		int altezzaSx = altMin(r->left);
		int altezzaDx = altMin(r->right);

		return altezzaSx < altezzaDx ? altezzaSx + 1 : altezzaDx + 1;
	}
}
//POST=(Restituisce la lunghezza minima tra i cammini che collegano la radice ad una foglia)

//PRE=(r BST ben formato)
void BST::elim(nodo*& r, int y)
{
	if(search(r, y))
	{
		if (r->info > y)
			elim(r->left, y);
		else if (r->info < y)
			elim(r->right, y);
		else
		{
			if (!r->left && !r->right)
				r = 0;
			else if (r->left && r->right)//due figli
			{
				nodo* n = min(r->right);
				elim(r, n->info);
				r->info = n->info;
			}
			else if (r->left)
				r = r->left;
			else
				r = r->right;
		}
	}
}
//POST=(r BST senza il nodo con campo info==y se presente nel BST di partenza)
