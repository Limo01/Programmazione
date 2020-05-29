#include<iostream>
using namespace std;

struct nodo {
	int info;
	nodo* left;
	nodo* right;

	nodo(int x = 0, nodo* l = 0, nodo* r = 0) {
		info = x;
		left = l;
		right = r;
	}
};

// FUNZIONI AUSILIARIE FORNITE
nodo* buildTree(int arr[], int i, int n) {

	if (i >= n) {
		return NULL;
	}
	nodo* root = new nodo(arr[i]);
	// insert left child
	root->left = buildTree(arr, 2 * i + 1, n);
	// insert right child
	root->right = buildTree(arr, 2 * i + 2, n);

	return root;

}

int height(nodo* root) {
	if (!root) {
		return 0;
	}
	return 1 + max(height(root->left), height(root->right));
}

void stampa_l(nodo* r)
{
	if (r)
	{
		cout << r->info << '(';
		stampa_l(r->left);
		cout << ',';
		stampa_l(r->right);
		cout << ')';
	}
	else
		cout << '_';
}
void sc(int* C)
{
	cout << *C << ' ';
	if (*C != -1)
		sc(C + 1);
}

//PRE = (albero(r) ben formato, k > 0)
int stampaASPre(nodo* r, int n, int k)
{
	if (!r)
		return n;
	else
	{
		if(n==0)
		{
			cout << r->info << " ";
			n = k - 1;
		}
		else
		{
			n--;
		}
		n = stampaASPre(r->left, n, k);
		return stampaASPre(r->right, n, k);
	}
}
//POST=(considerando I nodi di albero®in ordine prefisso, salta n nodi e poi stampa quello successivo e dopone salta k-1 e poi stampa il successivo, restituisce il numero di nodi che vanno saltati nelle successive parti dell’albero)

//PRE = (albero(r) ben formato, k > 0)
int stampaASInf(nodo* r, int n, int k)
{
	if (!r)
		return n;
	else
	{
		n = stampaASInf(r->left, n, k);
		if (n == 0)
		{
			cout << r->info << " ";
			n = k - 1;
		}
		else
		{
			n--;
		}		
		return stampaASInf(r->right, n, k);
	}
}
//POST=(considerando I nodi di albero®in ordine infisso, salta n nodi e poi stampa quello successivo e dopone salta k-1 e poi stampa il successivo, restituisce il numero di nodi che vanno saltati nelle successive parti dell’albero)

int main() {
	int dim;
	cin >> dim;
	int* a = new int[dim];
	for (int i = 0; i < dim; i++)
		cin >> a[i];

	nodo* root = NULL;
	root = buildTree(a, 0, dim);
	//stampa_l(root);

	int k;
	cin >> k;

	int a1 = stampaASPre(root, k-1, k);
	cout << " con avanzo " << a1 << endl;
	int b1 = stampaASInf(root, k-1, k);
	cout << " con avanzo " << b1 << endl;
}
