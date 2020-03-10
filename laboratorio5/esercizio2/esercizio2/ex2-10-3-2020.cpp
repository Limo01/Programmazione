#include <iostream>
using namespace std;

int f1(int B[], int nBit)
{
	int x = 0;
	int potenzaDiDue = 1;

	for (int i = nBit - 1; i >= 0; i--)
	{
		if (B[i] == 1)
		{
			x += potenzaDiDue;
		}
		potenzaDiDue *= 2;
	}
	return x;
}

double f2(int B[], int nBit)
{
	double y = 0;
	int potenzaDiDue = 2;

	for (int i = 0; i < nBit; i++)
	{
		if (B[i] == 1)
		{
			y += 1.0 / potenzaDiDue;
		}
		potenzaDiDue *= 2;
	}
	return y;
}


int main()
{
	int B[10];

	for (int i = 0; i < 10; i++)
		cin >> B[i];

	int pi = f1(B, 4); //traduci parte intera
	double pdec = f2(B + 4, 6);//traduci parte decimale

	cout << "value=" << pi + pdec << endl;
}
