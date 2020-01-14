#include<iostream>
using namespace std;

void leggi(int A[], int dim)
{
	int i = 0;
	while (i < dim)
	{
		cin >> A[i];
		i = i + 1;
	}
}

int main()
{
	int A[100], dimA, lungmax = 1, inizio = 0, inizioMax = 0;
	cin >> dimA;
	leggi(A, dimA);

	for(int i=0; i < dimA; i++)
	{
		inizio = i;
		while (A[i] < A[i + 1]) { i++;}
		if(lungmax < i - inizio + 1)
		{
			lungmax = i - inizio + 1;
			inizioMax = inizio;
		}
	}

	cout << "il più lungo SC inizia in " << inizioMax << " e ha lunghezza " << lungmax << endl;
}
