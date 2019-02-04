#include "Garage.h"
#include "NoAuth.h"
#include <string>
#include <iostream>

using mynsp::Veicolo ;
using mynsp::NoAuth ;

int Garage::push( const T& v ) {

	if ( last_ins == MAX ) {

		NoAuth no( "Garage pieno",0) ;
		throw no ;
		return -1 ;

	}
	else if ( last_ins < MAX ) {

		garage[last_ins] = v ;
		last_ins++ ;
	}

	return (last_ins-1) ;

}

T& Garage::pop( int pos ) {

	if ( pos >= last_ins || pos < 0 || pos >= MAX ) {

		NoAuth no( "Posto non trovato o vuoto" , 1 ) ;
		throw no ;

	}

	else return garage[pos] ;

}

void Garage::print() const {

	std::string s ;
	for ( int i = 0 ; i < last_ins ; i++ ) {

		s = garage[i]->ToText() ;
		cout << s << endl ;

		//oppure

		cout << *garage[i] << endl ;
	}
}

void Garage::print( ostream& of ) const {

	for ( int i = 0 ; i < last_ins ; i++ ) {

		of << *garage[i] ;

	}
}
