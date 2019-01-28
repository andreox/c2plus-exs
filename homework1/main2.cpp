#include "vector.h"
#include <iostream>

using namespace std ;

int main( int argc, char** argv ) {

	Vettore V ;
	Complesso C ;
	int n ;
	cout << "Inserimento del vettore di numeri complessi : " << endl ;
	LeggiElementi( V,n ) ;
	cout << "Stampa del vettore inserito" << endl ;
	StampaVettore( V, n ) ;
	cout << "Stampa sequenziale dei moduli del vettore non ordinato " ;
	for ( int i = 0 ; i < n ; i++ ) cout << moduloComplex(V[i]) << endl ;

	cout << "Ordino il vettore per moduli crescenti" << endl ;
	ModuloBubbleSort(V,n) ;
	cout << "Stampa sequenziale dei moduli nel vettore ordinato " << endl ;
	for ( int i = 0 ; i < n ; i++ ) cout << moduloComplex(V[i]) << endl ;

	return 0  ;
}