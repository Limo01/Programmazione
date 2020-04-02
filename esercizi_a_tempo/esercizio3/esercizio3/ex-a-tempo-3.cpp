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
	for(int i=0; i < 6; i++)
	{
		B1[r + 1][i] = false;

		if(B[r+1][i])
		{
			if ((i > 0 && B1[r][i - 1]) || B1[r][i] || (i < 5 && B1[r][i+1]))
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

int main()
{
	bool B[6][6], B1[6][6];
	leggi(B);

	for(int i=0; i < 6; i++)
	{
		B1[0][i] = B[0][i];
	}

	int riga;

	for(riga=0; (riga < 5) && !tutta_false(B1, riga); riga++)
		newriga(B, B1, riga);

	stampa(B1, riga + 1);

	if (riga < 5 || tutta_false(B1, riga))
		cout << "non c'e' cammino" << endl;
	else
		cout << "c'e' cammmino" << endl;
}

/*
CORRETTEZZA NEWRIGA:	La funzione newriga ha come parametri formali la matrice bool B, la matrice bool B1 e un int r con l'indice della riga. 
						Dobbiamo calcolare la riga r+1 della matrice B1 usando i valori della riga r di B1 e la riga r+1 di B.
						La precondizione è sempre verificata per come è stato scritto il main, ovvero che 0 <= r <= 4.
						Per calcolare la riga r+1 di B1 si effettuano le seguenti operazioni:
							* Ciclo per scorrere tutte le celle della riga r+1 di B
							* Se B[r+1][i] è true dobbiamo vedere se c'è un 1 nelle posizioni B1[r][i-1], B1[r][i] e B1[r][i+1], facendo i controlli sugli indici.
							  Se è presente almeno un 1 in queste posizioni, salviamo il valore 1 in B1[r+1][i]

						Esempio:
							B:	0	1	0	0
								1	0	0	1
								0	1	0	0
								1	0	0	0

							La riga 0 di B1 verrà copiata da B, quindi B[0][0...3]={0	1	0	0}
						
							Calcoliamo la riga 1 di B1 con la funzione newriga:
								B[1][0...3]={1	 0	 0	1}
								B1[0][0...3]={0	 1	0	0}

								In B[1][0] troviamo un 1. Dobbiamo controllare la presenza di un 1 nelle posizioni B1[0][0] e B1[0][1] e troviamo che B1[0][1]=1, perciò B1[1][0]=1.
								Anche in B[1][3] troviamo un 1. Dobbiamo controllare la presenza di un 1 nelle posizioni B1[0][2] e B1[0][3] siccome tutte e due sono uguali a zero, B1[1][3]=0.
								Non ci sono più 1, quindi la riga B1[1][0...3]={1	0	0	0}

							Calcoliamo la riga 2 di B1:
								B[2][0...3]={0	 1	 0	0}
								B1[1][0...3]={1	0	0	0}

								In B[2][1] troviamo un 1. Nelle posizioni B1[1][0], B1[1][1] e B1[1][2] troviamo che B1[1][0]=1, perciò B1[2][1]=1.
								Non ci sono più 1, quindi la riga B1[2][0...3]={0	1	0	0}

							Calcoliamo la riga 3 di B1:
								B[3][0...3]={1	 1	 1	1}
								B1[2][0...3]={0	 1	0	0}

								In B[3][0] troviamo un 1. Nelle posizioni B1[2][0], B1[2][1] e B1[2][2] troviamo che B1[2][1]=1, perciò B1[3][0]=1.
								Non ci sono più 1, quindi la riga B1[3][0...3]={1	0	0	0}

							Siccome l'ultima riga di B1 non è di tutti zeri, il programma darà come risultato "c'è un cammino"
*/