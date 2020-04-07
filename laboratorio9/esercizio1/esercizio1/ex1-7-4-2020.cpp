#include<iostream>
using namespace std;

struct orario
{
	int ore, minuti, secondi;

	orario(int a = -1, int b = -1, int c = -1)
	{
		ore = a;
		minuti = b;
		secondi = c;
	}

	bool nullo()
	{
		return ore == -1 && minuti == -1 && secondi == -1;
	}

	int inSecondi()
	{
		return ore * (60 * 60) + minuti * 60 + secondi;
	}
};

struct rileva
{
	int ril, corr;
	orario time;

	rileva(int a = -1, int b = -1, orario c = orario()) {
		ril = a;
		corr = b;
		time = c;
	}

	bool nullo()
	{
		return ril == -1 && corr == -1 && time.nullo();
	}
};

struct rilevazioni
{
	int corr;
	rileva partenza, mezzo, arrivo;

	void insertRilevazione(rileva r)
	{
		corr = r.corr;
		switch (r.ril)
		{
		case 0:
			partenza = r;
			break;
		case 1:
			mezzo = r;
			break;
		case 2:
			arrivo = r;
			break;
		}
	}

	string esito()
	{
		if (partenza.nullo() || mezzo.nullo() || arrivo.nullo())
			return "salto sensore";
		else if ((mezzo.time.inSecondi() - partenza.time.inSecondi() < (int)((2.0 * 60 + 45)*(21.975/2))) || (arrivo.time.inSecondi() - mezzo.time.inSecondi() < (int)((2.0 * 60 + 45) * (21.975 / 2))))//se segmento meno di 2' 45'' al km. Tot km=21,975
			return "tempo sospetto";
		return "regolare";
	}
};

istream& operator>>(istream& s, orario& x)
{
	s >> x.ore;
	s >> x.minuti;
	s >> x.secondi;
	return s;
}

istream& operator>>(istream& s, rileva& x)
{
	s >> x.ril;

	if (x.ril != -1)
	{
		s >> x.corr;
		s >> x.time;
	}
	return s;
}

int main()
{
	int ncorr;
	cin >> ncorr;

	orario z;
	cin >> z;

	rilevazioni corridori[100];

	rileva r;
	cin >> r;

	while (r.ril != -1)
	{
		corridori[r.corr].insertRilevazione(r);
		cin >> r;
	}
	
	bool garaRegolare = true;
	for (int i = 0; i < ncorr; i++)
		if(corridori[i].esito()!="regolare")
		{
			garaRegolare = false;
			cout << i << ": " << corridori[i].esito() << endl;
		}
	
	if (garaRegolare)
		cout << "gara regolare" << endl;
}
