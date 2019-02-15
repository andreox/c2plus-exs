#include "Vettore.h"

namespace Vector {

	Vettore::Vettore( const Vettore& vec ) {

		dim = vec.getDim() ;
		v = new T[dim] ;
		for ( int i = 0 ; i < dim ; i++ ) v[i] = vec[i] ;
	}

	Vettore& Vettore::operator=( const Vettore& vec ) {

		if ( this != &vec ) {

			delete [] v ;
			dim = vec.getDim() ;
			v = new T[dim] ;
			for ( int i = 0 ; i < dim ; i++ ) v[i] = vec[i] ;
		}

		return  *this ;
	}

	bool Vettore::push_back(const T& elem ) {

		if ( dim == MAX ) return false ;

		v[dim] = elem ;
		dim++ ;
		return true ;
	}

	bool Vettore::pop_back(T& elem) {

		if ( dim == 0 ) return false ;
		elem = v[dim] ;
		dim-- ;
		return true ;

	}
}
