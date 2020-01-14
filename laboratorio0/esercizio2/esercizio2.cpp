#include<iostream>
using namespace std;
main() {
 int n, max, min;
 cout << "Inserisci il numero di interi che vuoi confrontare: ";
 cin >> n;
 
 if(n>0){
  int interi[n];
  for(int i=0; i<n; i++){
    cin >> interi[i];
  }
 
  min= interi[0];
  max=min;
  for(int i=1; i<n; i++){
    if(interi[i] > max) max= interi[i];
    if(interi[i] < min) min= interi[i];
  }
  cout << "min= " << min << endl;
  cout << "max= " << max << endl;
 }
 else cout << "Il numero di interi da confrontare deve essere maggiore di zero" << endl;
}
