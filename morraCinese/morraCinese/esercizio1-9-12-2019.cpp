#include<iostream>
using namespace std;

int main()
{
	cout << "start" << endl;
	char mossaG1, mossaG2;

	cin >> mossaG1;
	cin >> mossaG2;

	if ((mossaG1 == 's' || mossaG1 == 'c' || mossaG1 == 'f') && (mossaG2 == 's' || mossaG2 == 'c' || mossaG2 == 'f'))
	{
		if (mossaG1 != mossaG2)
		{
			if ((mossaG1 == 's' && mossaG2 == 'f') || (mossaG1 == 'c' && mossaG2 == 's') || (mossaG1 == 'f' && mossaG2 == 'c'))
			{
				cout << "vince il giocatore 1" << endl;
			}
			else cout << "vince il giocatore 2" << endl;
		}
		else cout << "pareggio" << endl;
	}
	else cout << "mossa non valida" << endl;
	cout << "end" << endl;
}