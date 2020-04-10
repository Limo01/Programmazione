#include<iostream>
using namespace std;

void stampa(int* fetta, int lung)
{
	for (int i = 0; i < lung; i++)
		cout << fetta[i] << " ";
	cout << endl;
}

void getFetta(int* X, int* fetta, int lim1, int lim2, int lim3, int f, int n_ele, int& lung)
{
	lung = 0;

	for (int i = f * lim3, j = i; (i < n_ele) && (j < n_ele); i += lim2 * lim3)
	{
		for (j = i; (j < i + lim3) && (j < n_ele); j++, lung++)
		{
			fetta[lung] = X[j];
		}
	}
}

void elimina_e_compatta(int* fetta, int pos, int& lung)
{
	for (int i = pos; i < lung - 1; i++)
	{
		fetta[i] = fetta[i + 1];
	}
	lung--;
}

bool contienePatternCompleto(int* fetta, int lungF, int* pattern, int lungP)
{
	int i = 0;

	for (int j = 0; (j < lungF) && (i < lungP); j++)
	{
		if (fetta[j] == pattern[i])
			i++;
	}
	return i == lungP;
}

int main()
{
	int X[400], P[20], n_ele, nP, lim1, lim2, lim3;

	cin >> n_ele;

	for (int i = 0; i < n_ele; i++)
		cin >> X[i];

	cin >> lim1 >> lim2 >> lim3;

	if (lim1 * lim2 * lim3 < n_ele)
		n_ele = lim1 * lim2 * lim3;

	cin >> nP;

	for (int i = 0; i < nP; i++)
		cin >> P[i];

	cout << "start" << endl;

	int hf;
	cin >> hf;//fetta da trattare

	int lung;// lunghezza della H-fetta hf
	int fetta[300];
	getFetta(X, fetta, lim1, lim2, lim3, hf, n_ele, lung);

	if (contienePatternCompleto(fetta, lung, P, nP))
	{
		int i = 0;

		for (int j = 0; (j < lung) && (i < nP);)
		{
			if (fetta[j] == P[i])
			{
				i++;
				elimina_e_compatta(fetta, j, lung);
			}
			else
				j++;
		}
		cout << "H-fetta " << hf << " rimasti i seguenti " << lung << " valori:" << endl;	
	}
	else
	{
		cout << "H-fetta " << hf << " non è cambiata, i suoi " << lung << " valori seguono:" << endl;
	}
	stampa(fetta, lung);
	cout << "end" << endl;
}
