#include<iostream>
using namespace std;

void leggi(int A[],int dim)
{
  int i=0;
  while(i<dim)
    {
      cin>>A[i];
      i=i+1;
    }
}

int calcolaMatch(int A[], int dimA, int P[], int dimP, int posInizio)
{
	int posFine = -1;

	for(int i=posInizio, i2=0; i < dimA && i2 < dimP; i++)
	{
		if (A[i] == P[i2])
		{
			if (i2 == dimP - 1)
				posFine = i;
			i2++;
		}			
	}

	return posFine;
}

int main()
{
  int A[100],P[20],dimA,dimP,lungmin=100,inizio=-1;
  cin>>dimA>>dimP;
  leggi(A,dimA);
  leggi(P,dimP);
  int lungCalc;

  for(int i=0; i < dimA; i++)
  {
	  lungCalc = calcolaMatch(A, dimA, P, dimP, i)- i + 1;
	  cout << "lung calc: " << lungCalc << endl;
	  cout << "posIniziale: " << i << endl;

	  if (lungmin > lungCalc && lungCalc > 0)
	  {
		  lungmin = lungCalc;
		  inizio = i;
	  }		  
  }
  
  if(inizio==-1)
    cout<< "nessun match trovato"<< endl;
  else
    cout<<"il miglior match inizia in "<< inizio << " e ha larghezza "<< lungmin << endl;
}
