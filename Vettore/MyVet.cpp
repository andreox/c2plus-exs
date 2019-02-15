#include "MyVet.h"

namespace Vector {

	void MyVet::sort() {

		for ( int i = 0 ; i < dim-1 ; i++ ) {

			for ( int j = i ; j < dim ; j++ ) {

				if ( v[i] > v[j] ) {

					T tmp ;
					tmp = v[i] ;
					v[i] = v[j] ;
					v[j] = tmp ;

				}
			}
		}
	}

	bool MyVet::is_sorted() const {

		for ( int i = 0 ; i < dim-1  ; i++ )
			if ( v[i] > v[i+1] ) return false ;
		return true ;
	}

	int MyVet::BinarySearch(T& elem ) throw(NotSorted) {

		int top = dim ;
		int bottom = 0 ;
		int med ;

		if ( !is_sorted() ) {

			NotSorted n("Non ordinato",-1) ;
			throw n ;
			return -1 ;

		}

		while ( top >= bottom ) {

			med = (top+bottom)/2 ;
			if ( v[med] == elem ) return med ;
			else if ( v[med] > elem ) top = med ;
			else bottom = med ;

		}

		return -1 ;
	}

	std::ostream& MyVet::print( std::ostream& out ) {

		out << "Stampa del vettore" << std::endl ;
		for( int i = 0 ; i < dim ; i++ ) out << v[i] << std::endl ;

		return out ;
	}
}
