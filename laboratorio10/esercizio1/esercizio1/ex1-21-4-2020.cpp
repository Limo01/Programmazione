#include<iostream>
using namespace std;

int getHfetta(int* X, int fetta, int* ris, int lim1, int lim2, int lim3, int nele)
{
	int pos = 0;
	int ele = 0;

	for (int s = 0; s < lim3; s++)
	{
		ele= fetta + lim2 * s;
		for (int i = fetta * lim3 + s * lim2 * lim3; ele < nele && i<lim1*lim2*lim3; i++, pos++)
		{
			ele += lim1 * lim2;
			ris[pos] = i;
		}
	}
	return pos;
}

int& f(int* x, int lim1, int lim2, int lim3, int nele, int fex, int n)
{
	int ris[200];
	int lung = getHfetta(x, fex, ris, lim1, lim2, lim3, nele);

	if (n < lung)
		return x[ris[n]];
	else
		throw(1);
}

int main()
{
	int X[400], lim1, lim2, lim3, nele;
	cin >> lim1 >> lim2 >> lim3 >> nele;
	int nfvp = nele / (lim1 * lim2), resto = nele % (lim1 * lim2);

	for (int i = 0; i < nfvp; i++)
		for (int r = 0; r < lim2 * lim1; r++)
			cin >> X[i + r * lim3];

	for (int r = 0; r < resto; r++)
		cin >> X[nfvp + r * lim3];


	bool avanti = true;
	while (avanti)
	{
		int fex, n;
		cin >> fex;
		if (fex == -1)
			avanti = false;
		else
		{
			try
			{
				cin >> n;
				int& y = f(X, lim1, lim2, lim3, nele, fex, n);
				cout << "elemento n." << n << " della H-fetta " << fex << " e' =" << y << endl;
			}
			catch (int x)
			{
				cout << "elemento non esiste" << endl;
			}
		}

	}

}
