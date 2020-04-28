#include <iostream>

using namespace std;

// PRE = S e' una stringa di lunghezza n >= 0
bool palindroma(char *S, int n)
{
	if (n == 1)
		return true;
	else if (n == 2)
		return S[0] == S[1];
	else
	{
		if (S[0] == S[n - 1])
			return palindroma(S + 1, n - 2);
		else
			return false;
	}
}
// POST = ritorna true se e solo se S e' palindroma

int main() 
{
    int lung;
    char S[100];
    cin.getline(S, 100);        // legge una riga di caratteri da cin
    lung = cin.gcount() - 1;    // gcount ritorna il numero di caratteri letti(compreso il terminatore '\n')

	if (palindroma(S, lung))
		cout << "la stringa e' palindroma" << endl;
	else
		cout << "la stringa non e' palindroma" << endl;
}