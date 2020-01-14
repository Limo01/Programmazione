#include<iostream>
using namespace std;
main() { 
	int x,pippo,pluto;
	cin >> x >> pippo>> pluto;
	if(x < pippo)
		if(x < pluto) cout<< x << endl;
		else cout<< pluto << endl;
	else if(pippo< pluto)
		cout<< pippo << endl;
	else cout<< pluto << endl; 
}
