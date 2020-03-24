#include<iostream>
using namespace std;

//PRE = (Xcontiene strati * 4 * 5 valori e 0 <= fetta < 4)
void stampaH(int X[][4][5], int n_elementi, int fetta)
{
	int* p = X[0][0];

	if (fetta*5 < n_elementi)
	{
		for (int i = fetta*5; i < n_elementi; i += 15)
		{
			for(; i < n_elementi; i++)
				cout << p[i] << " ";
		}
	}
	else
		cout << "fetta richiesta vuota" << endl;
}
//POST=(stampa la H-fetta fetta)

//PRE=(Xcontiene strati*4*5 valori e 0<= fetta < 5)
void stampaV(int X[][4][5], int n_elementi, int fetta)
{
	int* p = X[0][0];

	if(fetta < n_elementi)
	{
		for (int i = fetta; i < n_elementi; i += 5)
		{
			cout << p[i] << " ";
		}
	}
	else
		cout << "fetta richiesta vuota" << endl;
}
//POST=(stampa la V-fetta fetta)

int main()
{
	cout << "start" << endl;
	int A[3][4][5], * p = A[0][0], n_ele;
	cin >> n_ele;
	
	for (int i = 0; i < n_ele; i++)
		cin >> p[i];
	
	char c;
	int f;
	cin >> c >> f;

	if (c == 'H')
		stampaH(A, n_ele, f);
	else
		stampaV(A, n_ele, f);

	cout << "end" << endl;
}