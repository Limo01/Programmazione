#include<iostream>
using namespace std;

//PRE =(A contiene dimA elementi, dimA>=0, A=vA) 
void elimina(int A[], int& dimA, int x)
{
	int i = 0;
	
	while(i < dimA - 1)
	{
		if(A[i] == x)
		{
			dimA--;
			for(int j=i; j<dimA; j++)
			{
				A[j] = A[j + 1];
			}
		}
		else
		{
			i++;
		}
	}
}
//POST(A[0..dimA-1]contiene gli elementi di vA diversi da x nell’ordine relativo che essi avevano in vA)

int main()
{
	int A[20], dimA, x, i = 0;
	cin >> dimA;

	while (i < dimA)
	{
		cin >> A[i];
		i = i + 1;
	}
	cin >> x;

	elimina(A, dimA, x);

	i = 0;

	while (i < dimA)
	{
		cout << A[i] << ' ';
		i = i + 1;
	}
	cout << endl;
}