#include<iostream>
using namespace std;

void leggi(bool(*X)[6])
{
	bool* y = *X;
	for (int i = 0; i < 36; i++)
		cin >> y[i];
}

void stampa_r(bool(*X)[6], int r)
{
	cout << "riga:" << r << '=';

	for (int i = 0; i < 6; i++)
		cout << X[r][i] << ' ';
	cout << endl;
}

void stampa(bool(*X)[6], int r)
{
	for (int i = 0; i < r; i++)
		stampa_r(X, i);
}

//PRE=(0<=r<=4)&&(le righe r di B e B1 sono definite)
void newriga(bool(*B)[6], bool(*B1)[6], int r)
{
	for (int i = 0; i < 6; i++)
	{
		B1[r + 1][i] = false;

		if (B[r + 1][i])
		{
			if ((i > 0 && B1[r][i - 1]) || B1[r][i] || (i < 5 && B1[r][i + 1]))
				B1[r + 1][i] = true;
		}
	}
}
//POST=(calcola,nel modo descritto prima, la nuova riga r+1 di B1 usando la riga r+1 di B e la riga r di B1)

bool tutta_false(bool(*X)[6], int r)
{
	for (int i = 0; i < 6; i++)
		if (X[r][i])
			return false;
	return true;
}

int trovaInizio(bool(*B1)[6], int r)
{
	for(int i=0; i<6; i++)
	{
		if (B1[r][i])
			return i;
	}
}

void costruisciCammino(int* T, bool(*B1)[6])
{
	int c_iniziale = trovaInizio(B1, 5);
	T[5] = c_iniziale;

	for(int r=4; r>-1; r--)
	{
		if((c_iniziale > 0 && B1[r][c_iniziale - 1]))
		{
			T[r] = c_iniziale-1;
			c_iniziale--;
		}
		else if(B1[r][c_iniziale])
		{
			T[r] = c_iniziale;
		}
		else if((c_iniziale < 5 && B1[r][c_iniziale + 1]))
		{
			T[r] = c_iniziale+1;
			c_iniziale++;
		}
	}
}


void stampaCammino(int* T)
{
	for(int i=0; i<6; i++)
	{
		cout << "riga " << i << ", colonna " << T[i] << endl;
	}
}

int main()
{
	bool B[6][6], B1[6][6];
	leggi(B);

	for (int i = 0; i < 6; i++)
	{
		B1[0][i] = B[0][i];
	}

	int riga;

	for (riga = 0; (riga < 5) && !tutta_false(B1, riga); riga++)
		newriga(B, B1, riga);

	stampa(B1, riga + 1);

	if (riga < 5 || tutta_false(B1, riga))
		cout << "non c'e' cammino" << endl;
	else
	{
		cout << "Un cammino e':" << endl;
		int T[6];
		costruisciCammino(T, B1);
		stampaCammino(T);
	}	
}