#include<iostream>
using namespace std;

void superC(int x[][10], int righe, int& sc, int& rip) {
	int colonnaAttuale, ripCA;
	bool colonneUguali;
	sc = 0, rip = 0;

	for (int i = 0; i < 9; ++i) {
		colonnaAttuale = i, ripCA = 0;

		for (int j = i; j < 10; ++j) {
			colonneUguali = true;

			for (int k = 0; k < righe; ++k) {
				if (x[k][i] != x[k][j]) {
					colonneUguali = false;
				}
			}

			if (colonneUguali) ripCA++;
		}

		if (ripCA > rip) {
			rip = ripCA;
			sc = colonnaAttuale;
		}
	}
}

int main() {
	int X[5][10];

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> X[i][j];
		}
	}

	int supc, rip;
	superC(X, 5, supc, rip);
	cout << "la super colonna è " << supc << " e ripete " << rip << " volte" << endl;
}