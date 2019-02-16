#include "CodaFotografia.h"
#include <fstream>

using namespace std ;

namespace Foto {

	CodaFotografia::CodaFotografia( const char* nf ) {

		ifstream file(nf) ;
		if( file.is_open() ) {

			for ( int i = 0 ; i <= F_ELEM ; i++ )
				file >> v[i] ;


		}
		nelem = F_ELEM ;
	}

	void CodaFotografia::pop( T& elem ) throw(BadPop) {

		if ( empty() ) {
			BadPop p("Coda vuota, impossibile rimuovere elementi",0) ;
			throw p ;
		}

		int index = nelem%N ;
		elem = v[index] ;

	}

	void CodaFotografia::stampa( ) const {

		for( int i = 0 ; i < (nelem)%N ; i++ ) cout << v[i] << endl ;
	}
}
