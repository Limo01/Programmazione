#include<iostream>
using namespace std;

//PRE = (Xcontiene strati * 4 * 5 valori e 0 <= fetta < 4)
void stampaH(int X[][4][5], int strati, int fetta)
{
	for(int strato=0; strato < strati; strato++)//INAVRIANTE: (strato è l'inidice dello strato da stampare) & (0 <= strato < strati)
	{
		for(int i=0; i < 5; i++)//INVARIANTE: (strato è l'inidice dello strato da stampare) & (i è l'indice della colonna da stampare della riga con indice fetta) & (0 <= strato < strati) & (0<= i < 5)
		{
			cout << X[strato][fetta][i] << " ";
		}
		cout << endl;
	}
}
//POST=(stampa la H-fetta fetta)

//PRE=(Xcontiene strati*4*5 valori e 0<= fetta < 5)
void stampaV(int X[][4][5], int strati, int fetta)
{
	for (int strato = 0; strato < strati; strato++)//INAVRIANTE: (strato è l'inidice dello strato da stampare) & (0 <= strato < strati)
	{
		for (int i = 0; i < 4; i++)//INVARIANTE: (strato è l'inidice dello strato da stampare) & (i è l'indice della riga da stampare della colonna con indice fetta) & (0 <= strato < strati) & (0<= i < 4)
		{
			cout << X[strato][i][fetta] << " ";
		}
		cout << endl;
	}
}
//POST=(stampa la V-fetta fetta)

int main()
{
  int A[3][4][5];
  for(int i=0; i<3; i=i+1)
    for(int j=0; j<4; j=j+1)
      for(int k=0; k<5; k=k+1)
       cin >> A[i][j][k];
  
  cout<<"start"<<endl;
  char c;
  int f;
  cin >> c >> f;

  if(c=='H')
	  stampaH(A, 3, f);
  else
	  stampaV(A, 3, f);

  cout<<"end"<<endl;
}