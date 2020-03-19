#include<iostream>
using namespace std;

void stampa(int A[10][5])
{
	for (int r = 0; r < 10; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			cout << A[r][c] << " ";
		}
		cout << endl;
	}
}

void stampa(bool A[10][5])
{
	for (int r = 0; r < 10; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			cout << A[r][c] << " ";
		}
		cout << endl;
	}
}

void riempi(int A1[10][5], int A2[10][5])
{
	int i = 0;
	int nInput;

	while (i < 50)
	{
		cin >> nInput;

		A1[i/5][i%5] = nInput;

		A2[i%10][i/10] = nInput;

		i++;
	}

	stampa(A1);
	cout << endl;
	stampa(A2);
	cout << endl;
}

bool elementiComuni(int A1[10][5], int A2[10][5], int i, int j)
{
	bool elementiComuni = false;

	for(int a=0; a < 5 && !elementiComuni; a++)//Ciclo 1
	{
		for(int b=0; b < 10 && !elementiComuni; b++)//Ciclo 2
		{
			elementiComuni = A1[i][a] == A2[b][j];
		}
	}

	return elementiComuni;
}


void cross(int A1[10][5], int A2[10][5], bool B[10][5])
{
	for (int i = 0; i < 10; i++)//Ciclo 1
	{
		for (int j = 0; j < 5; j++)//Ciclo 2
		{
			B[i][j] = elementiComuni(A1, A2, i, j);
		}
	}
	stampa(B);
}

int main()
{
	int A1[10][5], A2[10][5];
	riempi(A1, A2);
	bool B[10][5];
	cross(A1, A2, B);
}

/*
	INAVARIANTI CROSS:
		INVARIANTE CICLO 1:	[R] = (0 <= i <= 10) & (i è l'indice della riga della matrice B)

		INVARINATE CICLO 2: [R] = (0 <= i <= 10) & (0 <= j <= 5) & (i è l'indice della riga della matrice B) & (j è l'indice della colonna della matrice B)

	INVARIANTI ELEMENTICOMUNI:
		INVARIANTE CICLO 1:	[R] = (0 <= a <= 5) & (a è l'indice della colonna di B[i][]) & (elementiComuni == false => Non sono stati trovati elementi comuni) & (elementiComuni == true => Sono stati trovati elementi comuni)

		INVARIANTE CICLO 2:	[R] = (0 <= a <= 5) & (0 <= b <= 10) & (a è l'indice della colonna di B[i][]) & (b è l'indice della riga di B[][j]) & (elementiComuni == false => Non sono stati trovati elementi comuni) & (elementiComuni == true => Sono stati trovati elementi comuni)
*/
