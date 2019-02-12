#include "Vettore.h"
#include <iostream>

namespace Temperature {

	Vettore::Vettore( const Vettore& vet ) {

		dim = vet.dim ;
		v = new T[dim] ;
		riemp = vet.riemp ;

		for ( int i = 0 ; i < dim ; i++ ) v[i] = vet.v[i] ;

	}

	const Vettore& Vettore::operator=( const Vettore& vet ) {

		if ( this != &vet ) {

			delete [] v ;
			dim = vet.dim ;
			v = new T[dim] ;
			for ( int i = 0 ; i < dim ; i++ ) v[i] = vet.v[i] ;
			riemp = vet.riemp ;
		}

		return *this ;

	}

	void Vettore::stampa( ostream& out) const {

		for ( int i = 0 ; i < dim ; i++ ) out << v[i] ;

	}

	bool Vettore::push( const T& elem ) {

		if ( !full() ) {

			v[riemp] = elem ;
			riemp++ ;
			return true ;
		}

		return false ;
	}
}
