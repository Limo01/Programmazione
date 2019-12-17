#include<iostream>
using namespace std;
int main()
{
	char input;
	bool moreParentesiChiuse = false, parentesiAccavallata = false;
	string s = "";

	do{
		cin >> input;

		if (input == '(' || input == '[' || input == '{')
			s += input;
		else if(input == ')' || input == ']' || input == '}')
		{
			if (s.length() == 0)
				moreParentesiChiuse = true;
			else if ((input == ')' && s.at(s.length() - 1) == '(') || (input == ']' && s.at(s.length() - 1) == '[') || (input == '}' && s.at(s.length() - 1) == '{'))
			{
				if (s.length() == 1)
					s = "";
				else
					s = s.substr(0, s.length() - 1);
			}
			else
				parentesiAccavallata = true;
		}
	} while (input != '0' && !parentesiAccavallata && !moreParentesiChiuse);
	/*
	* INVARIANTE: (ultima lettura è in input) && (prima di input nessuno '0') && 
	*			  (!parentesiAccavallata => Non ci sono parentesi accavallate in s) &&
				  (!moreParentesiChiuse => Non c'è un numero di parantesi chiuse maggiore di quelle aperte in s)
	*/

	if (parentesiAccavallata)
		cout << "Parentesi accavallate" << endl;
	else if (moreParentesiChiuse)
		cout << "Troppe parentesi chiuse" << endl;
	else if (s.length() > 0)
		cout << "Troppe parentesi aperte" << endl;
	else
		cout << "Sequenza bilanciata" << endl;
}