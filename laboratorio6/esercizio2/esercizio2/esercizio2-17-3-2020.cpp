#include<iostream>
using namespace std;

//PRE =(A contiene dimA elementi, dimA>=0, A=vA) 
void elimina(int A[], int& dimA, int x, int posIniziale)
{
	while (posIniziale < dimA - 1)
	{
		if (A[posIniziale] == x)
		{
			dimA--;
			for (int j = posIniziale; j < dimA; j++)
			{
				A[j] = A[j + 1];
			}
		}
		else
		{
			posIniziale++;
		}
	}
}
//POST(A[posIniziale..dimA-1]contiene gli elementi di vA diversi da x nell’ordine relativo che essi avevano in vA)

//PRE=(A ha dimA elementi, vA=A)
void togliDoppi(int A[], int &dimA)
{
	int i = 0;
	while(i < dimA -1)
	{
		elimina(A, dimA, A[i], i + 1);
		i++;
	}
}
//POST=(in A[0..dimA-1]è prodotto da A togliendo i doppi e mantenendo solo la prima occorrenza di ciascun valore distinto in vA)

int main()
{
	int A[20], dimA, i = 0;
	cin >> dimA;

	while (i < dimA)
	{
		cin >> A[i];
		i = i + 1;
	}

	togliDoppi(A, dimA);
	i = 0;

	while (i < dimA)
	{
		cout << A[i] << ' '; 
		i = i + 1;
	}
	cout << endl;
}