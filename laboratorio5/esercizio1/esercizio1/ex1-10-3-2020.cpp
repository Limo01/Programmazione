#include <iostream>
using namespace std;

void X2B(int x, int B[], int nBit)
{
	for(int i=nBit-1; i>=0; i--)
	{
		if (x % 2 == 0)
		{
			B[i] = 0;
		}
		else B[i] = 1;
		x /= 2;
	}
}

void Y2B(float y, int B[], int nBit)
{
	for (int i = 0; i < nBit; i++)
	{
		y *= 2;

		if (y >= 1)
		{
			B[i] = 1;
			y -= 1;
		}
		else B[i] = 0;
	}
}

int main()
{
  int X;
  int B[10];
  float Y;
  cin >> X >> Y;
  X2B(X,B,4);
  Y2B(Y,B+4,6);
  for(int i=0; i<10; i++)
    cout<<B[i]<<' ';
  cout<<endl;
} 
