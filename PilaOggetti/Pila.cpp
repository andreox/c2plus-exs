#include "Pila.h"

Pila::Pila( const Pila& p ) {

	riemp = p.riemp ;
	P = new T[p.riemp] ;

	for ( int i = 0 ; i < p.riemp ; i++ ) P[i] = p.P[i] ;

}

const Pila& Pila::operator=( const Pila& p ) {

	if ( this != &p ) {

		delete [] P ;
		riemp = p.riemp ;

		for( int i = 0 ;i < p.riemp; i++ ) P[i] = p.P[i] ;

	}

	return *this ;

}

bool Pila::push( const T& elem ) {

	T * tmp_P = new T[riemp] ;
	for ( int i = 0 ; i < riemp ; i++ ) tmp_P[i] = P[i] ;

	delete [] P ;
	P = new T[++riemp] ;

	for ( int i = 0 ; i < riemp ; i++ ) P[i] = tmp_P[i] ;
	P[riemp] = elem ;

	return true ;

}

bool Pila::pop( T& elem ) {

	elem = P[riemp-1] ;
	riemp-- ;
	return true ;

}

void Pila::print( ostream& out )const {

	for ( int i = 0 ; i < riemp ; i++ ) out << P[i] ;

}

bool Pila::top( T& elem ) {

	elem = P[0] ;
	return true ;

}

