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
  int A[100],P[20],dimA,dimP;
  cin>>dimA>>dimP;
  leggi(A,dimA);
  leggi(P,dimP);
  
  for(int i=0; i < dimA; i++)
  {
	  int j=0;
	  for(int y=i; y < dimA && j < dimP && A[y] == P[j]; j++, y++){}

	  if(j==dimP)
	  {
		  cout << "trovato match che inizia in posizione " << i << " di A" << endl;
	  }
  }
}
