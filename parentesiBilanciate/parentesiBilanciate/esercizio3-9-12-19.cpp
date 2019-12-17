#include<iostream>
using namespace std;
int main()
{
   cout << "start"<<endl; 

   int contaParentesi = 0;
   char input = 'a';

   while(input != '0' && contaParentesi>=0)
   {
	   cin >> input;
	   if (input == '(') 
		   contaParentesi++;
	   else if (input == ')') 
		   contaParentesi--;
   }
   
   if (contaParentesi == 0)
	   cout << "la sequenza e' bilanciata" << endl;
   else
   {
	   cout << "la sequenza non e' bilanciata: ";
	   (contaParentesi > 0) ? cout << "ci sono parentesi aperte senza match" << endl : cout << "ci sono parentesi chiuse senza match" << endl;
   }
	   
    cout << "end"<<endl; 
}