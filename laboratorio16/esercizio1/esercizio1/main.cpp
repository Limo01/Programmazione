#include<iostream>
#include "BST.h"
using namespace std;
using namespace BST;

int main()
{
	//prepara un albero iniziale non triviale
	nodo* r = new nodo(15, new nodo(7), new nodo(19));
	r->left->right = new nodo(9, new nodo(8));
	r->right->right = new nodo(25, new nodo(22));
	
	bool stop = false;
	while (!stop)
	{
		int x;
		cin >> x;

		switch(x)
		{
			case 0:
				stop = true;
				break;
			case 1:
				stampa_l(r);
				cout << endl;
				break;
			case 2:
				int y;
				cin >> y;
				insert(r, y);
				stampa_l(r);
				cout << endl;
				break;
			case 3:
				int z;
				cin >> z;
				if (search(r, z))
					cout << "valore " << z << " presente" << endl;
				else
					cout << "valore " << z << " non presente" << endl;
				break;
			case 4:
				int w;
				cin >> w;
				if (w == 1)
					cout << max(r)->info << endl;
				else if (w == 2)
					cout << min(r)->info << endl;
				break;
			case 5:
				cout << altezza(r) << endl;
				break;
			case 6:
				cout << altMin(r) << endl;
				break;
		}
	}
}