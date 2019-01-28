#include "vector.h"
#include <iostream>

using namespace std ;

void LeggiElementi( Vettore vet, int &nelem ) {

	cout << "Quanti elementi vuoi inserire ? " ;
	cin >> nelem ;

	for ( int i = 0 ; i < nelem ; i++ ) leggiComplex( vet[i]) ;

} 

void StampaVettore( const Vettore vet , const int nelem ) {

	for ( int i = 0 ; i < nelem ; i++ ) stampaComplex( vet[i] ) ;

}

void ModuloBubbleSort( Vettore vet, const int nelem ) {

	for ( int i = 0 ; i < nelem-1 ; i++ ) {

		for ( int j = i+1 ; j < nelem ; j++ ) {

			if ( moduloComplex( vet[i] ) > moduloComplex( vet[j]) ) {

				Complesso tmp = vet[i] ;
				vet[i] = vet[j] ;
				vet[j] = tmp ;
			}
		}
	}
}

