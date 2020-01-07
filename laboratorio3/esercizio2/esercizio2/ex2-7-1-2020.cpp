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

int main()
{
  int A[100],P[20],dimA,dimP,lungmax=0, inizio=0;
  cin>>dimA>>dimP;
  leggi(A,dimA);
  leggi(P,dimP);

  for(int i=0; i < dimA; i++)
    {
  	  int j=0;
  	  for(int y=i; j < dimP && y < dimA && A[y]==P[j]; j++, y++){}

  	  if(j > lungmax)
  	  {
  		lungmax= j;
  		inizio= i;
  	  }
    }

  cout<<"il massimo match ha lunghezza "<< lungmax<< " e inizia in posizione "<< inizio <<" di A"<<endl;  	
}
