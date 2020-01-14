#include<iostream>
using namespace std;

int main()
{
	cout << "start" << endl;
	
	int n;
	cin >> n;

	char mossaG1, mossaG2;
	int vittorieG1=0, vittoreG2=0;

	for (int i = 0; i < n; i++)
	{
		cin >> mossaG1;
		cin >> mossaG2;

		if ((mossaG1 == 's' || mossaG1 == 'c' || mossaG1 == 'f') && (mossaG2 == 's' || mossaG2 == 'c' || mossaG2 == 'f'))
		{
			if (mossaG1 != mossaG2)
			{
				if ((mossaG1 == 's' && mossaG2 == 'f') || (mossaG1 == 'c' && mossaG2 == 's') || (mossaG1 == 'f' && mossaG2 == 'c'))
				{
					vittorieG1++;
				}
				else vittoreG2++;
			}
		}
		else {
			cout << "mossa non valida ripetere tentativo" << endl;
			i--;
		}
	}
	if (vittorieG1 == vittoreG2) cout << "Pareggio" << endl;
	else (vittorieG1 > vittoreG2) ? cout << "Vince il Giocatore 1" << endl : cout << "Vince il Giocatore 2" << endl;
	
	cout << "end" << endl;
}