#include <iostream>
#include <cmath>
#include "complex.h"

using namespace std ;

void leggiComplex( Complesso &c ) {

	cout << "Inserisci la parte reale : " ;
	cin >> c.Re ;

	cout << "Inserisci la parte imm : " ;
	cin >> c.Imm ;

}

void stampaComplex( const Complesso c ) {

	cout << " Re : " << c.Re << " Imm : " << c.Imm << endl ;

}

Complesso sommaComplex( const Complesso c1 , const Complesso c2 ) {

	Complesso tot ;
	tot.Re = c1.Re + c2.Re ;
	tot.Imm = c1.Imm + c2.Imm ;
	return tot ;

}

Complesso prodottoComplex( const Complesso c1, const Complesso c2 ) {

	Complesso tot ;
	tot.Re = (c1.Re * c2.Re) - (c1.Imm*c2.Imm) ;
	tot.Imm = ( c1.Re*c2.Imm) + ( c1.Imm*c2.Re) ;
	return tot ;
}

double moduloComplex( const Complesso c ) { return sqrt( (c.Re)*(c.Re) + (c.Imm)*(c.Imm)) ; } 