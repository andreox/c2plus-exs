#include <iostream>
#include "complex.h"

using namespace std ;

int main() {

	Complesso c1, c2, somma, prodotto;
	cout << "Leggo c1 : " ;
	leggiComplex(c1) ;
	cout << "Leggo c2 : " ;
	leggiComplex(c2) ;
	cout << "modulo c1 : " << moduloComplex(c1) << endl ;
	cout << "modulo c2 : " << moduloComplex(c2) << endl ;
	somma = sommaComplex(c1,c2 ) ;
	cout << " somma : " ;
	stampaComplex(somma) ;
	prodotto = prodottoComplex(c1,c2) ;
	cout << "Prodotto : " ;
	stampaComplex(prodotto) ;

	return 0 ;
}